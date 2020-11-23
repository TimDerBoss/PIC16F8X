#include "CPU.h"
#include "RegisterData.h"

#include <FormatString.h>

CPU::CPU(const std::vector<LstOpcodeInfo>& lstOpcodeInfo)
	: instructionHandler(lstOpcodeInfo)
	// TODO: watchdog
	// , watchdog(*this, registers)
{
	this->onCpuTimeChanged.connect([this](double difference) {
		timeActive += difference;
	});
}

void CPU::start(double clockSpeed)
{
	if (!processorActive) {
		if (processorThread.joinable())
			processorThread.join();
		this->clockSpeed = clockSpeed;
		processorActive = true;
		processorThread = std::thread([this]() {
			while (processorActive) {
				singleStep(registers.getPc());
				std::this_thread::sleep_for(std::chrono::milliseconds(50));
			}
		});
	}
}

void CPU::stop()
{
	if (processorActive) {
		processorActive = false;
		processorThread.join();
	}
}

void CPU::singleStep(int programCounter)
{
	int cyclesPassed = executeInstruction(programCounter);

	processPortInterrupts();
	processTimerInterrupt(cyclesPassed);
	processBreakpoint();
}

int CPU::getCpuTime()
{
	return timeActive;
}

bool CPU::getProcessorActive()
{
	return processorActive;
}

RegisterData& CPU::getRegisters()
{
	return registers;
}

void CPU::setCpuTime(int time)
{
	timeActive = time;
}

void CPU::setClockSpeed(double speed)
{
	clockSpeed = speed;
}

InterruptType CPU::detectInterrupt()
{
	static bool lastRB0;
	bool currentRB0 = registers.applyRequest(Request(Registers::PortB).getBit(0));
	static uint8_t lastRB47;
	uint8_t currentRB47 = registers.applyRequest(Request(Registers::PortB).fullValue()) & 0xF0;

	if (globalInterruptsEnabled())
	{
		bool hasToBeRisingEdge = registers.applyRequest(Request(Registers::Option).getBit(6));
		if (portBLowInterruptEnabled() && lastRB0 != currentRB0 && currentRB0 == hasToBeRisingEdge)
			return InterruptType::PortB0;

		if (portBHighInterruptEnabled() && lastRB47 != currentRB47)
			return InterruptType::PortB47;

		if (timerInterruptEnabled() && timerInterruptFlagSet())
			return InterruptType::Timer0;
	}
	lastRB0 = registers.applyRequest(Request(Registers::PortB).getBit(0));
	lastRB47 = registers.applyRequest(Request(Registers::PortB).fullValue()) & 0xF0;
	return InterruptType::None;
}

void CPU::jumpToInterruptRoutine()
{
	registers.stack.push(registers.getPc());
	registers.writeByte(0x2, 4);
	onCpuTimeChanged(4 / (clockSpeed / 4.0));
	cycles++;
}

void CPU::setBreakpoint(int address)
{
	breakpointAddress = address;
}

void CPU::enableBreakpoint(bool enable)
{
	breakpointEnabled = enable;
}

void CPU::processBreakpoint()
{
	if (breakpointEnabled && registers.getPc() == breakpointAddress && processorActive) {
		processorActive = false;
	}
}

int CPU::executeInstruction(int programCounter)
{
	auto& instruction = instructionHandler.decodeAt(programCounter);
	instruction->execute(registers, instructionHandler.getInstructionData(programCounter));
	onCpuTimeChanged(instruction->getCycles() / (clockSpeed / 4.0));
	return cycles += instruction->getCycles();
}

void CPU::enableGlobalInterrupts(bool enable)
{
	registers.applyRequest(Request(Registers::Intcon).writeBit(7, enable));
}

void CPU::processTimerInterrupt(int cyclesPassed)
{
	// T0CS
	static uint8_t lastRA4 = 0;
	static int counter = 0;
	if (!registers.readBit(0x81, 5))
	{
		counter += cycles;
	}
	else { // T0CS == 1

		// !T0SE -> Rising edge on RA4
		if (!registers.readBit(0x81, 5)) {
			if (lastRA4 != registers.readBit(5, 4) && lastRA4 == 0) {
				// rising edge on RA4
				counter += 1;
			}
		}
		else { // Falling edge on RA4
			if (lastRA4 != registers.readBit(5, 4) && lastRA4 == 1) {
				// falling edge on RA4
				counter += 1;
			}
		}
	}
	// prescaler (PSA Bit == 0)
	int prescaleValue = 0;
	if (registers.readBit(0x81, 3) == 0)
		prescaleValue = 2 << (registers.readByte(0x81) & 0x7);
	else
		prescaleValue = 1;
	if (counter >= prescaleValue) {
		// T0IE && overflow
		if (registers.readBit(0xB, 5) && registers.readByte(1) == 0xFF)
		{
			// intcon - t0if
			registers.writeBit(0xB, 2, true);
		}
		registers.writeByte(1, registers.readByte(1) + 1);
		counter = 0;
	}
	lastRA4 = registers.readBit(0x5, 4);
}

void CPU::processPortInterrupts()
{
	InterruptType type = detectInterrupt();
	if (type != InterruptType::None) {
		enableGlobalInterrupts(false);

		if (type == InterruptType::PortB0)
			setFlagINTF();
		else if (type == InterruptType::PortB47)
			setFlagRBIF();

		jumpToInterruptRoutine();
	}
}

void CPU::setFlagINTF()
{
	registers.applyRequest(Request(Registers::Intcon).writeBit(1, true));
}

void CPU::setFlagRBIF()
{
	registers.applyRequest(Request(Registers::Intcon).writeBit(0, true));
}

bool CPU::globalInterruptsEnabled()
{
	return registers.applyRequest(Request(Registers::Intcon).getBit(7));
}

bool CPU::portBLowInterruptEnabled()
{
	return registers.applyRequest(Request(Registers::Intcon).getBit(4));
}

bool CPU::portBHighInterruptEnabled()
{
	return registers.applyRequest(Request(Registers::Intcon).getBit(3));
}

bool CPU::timerInterruptEnabled()
{
	return registers.applyRequest(Request(Registers::Intcon).getBit(5));
}

bool CPU::timerInterruptFlagSet()
{
	return registers.applyRequest(Request(Registers::Intcon).getBit(2));
}

