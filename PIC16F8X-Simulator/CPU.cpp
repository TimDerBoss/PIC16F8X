#include "CPU.h"

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


// run just the next instruction
void CPU::singleStep(int programCounter)
{
	if (breakpointEnabled && programCounter == breakpointAddress) {
		processorActive = false;
		return;
	}

	// check if an interrupt has happened meanwhile
	if (processInterrupts()) {
		// jump to interrupt
		registers.stack.push(programCounter);
		registers.writeByte(0x2, 4);
		onCpuTimeChanged(4 / (clockSpeed / 4.0));
		cycles++;
		return;
	}

	// else execute the normal code
	auto& instruction = instructionHandler.decodeAt(programCounter);
	instruction->execute(registers, instructionHandler.getInstructionData(programCounter));
	onCpuTimeChanged(instruction->getCycles() / (clockSpeed / 4.0));
	cycles++;


	// TODO: timer inerrupt
	// T0CS
	static uint8_t lastRA4 = 0;
	static int counter = 0;
	if (!registers.readBit(0x81, 5))
	{
		counter += instruction->getCycles();
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

bool CPU::processInterrupts()
{
	static uint8_t lastRB0;
	static uint8_t lastRB4_7;
	// GIE set
	if (registers.readBit(0xB, 7))
	{
		// RB0 Interrupt
		// INTE set && Flanke && ((RB0 && IntEdg) || (!RB0 && !IntEdg))
		if (registers.readBit(0xB, 4)
			&& lastRB0 != registers.readBit(0x6, 0)
			&& registers.readBit(0x6, 0) == registers.readBit(0x81, 6)
			)
		{
			// Disable GIE to prevent further Interrupts while executing the current one
			registers.writeBit(0xB, 7, false);
			// Set the INTF flag
			registers.writeBit(0xB, 1, true);
			return true;
		}

		// RB4-7 Interrupt
		// INTE set && Geänderte Flanke
		if (lastRB4_7 != ((registers.readByte(0x6) & 0xF0) >> 4))
		{
			// Disable GIE to prevent further Interrupts while executing the current one
			registers.writeBit(0xB, 7, false);
			// Set the RBIF flag
			registers.writeBit(0xB, 0, true);
			return true;
		}

		// Timer0 Interrupt
		// T0IE set && T0IF
		if (registers.readBit(0xB, 5) && registers.readBit(0xB, 2))
		{
			// Disable GIE to prevent further Interrupts while executing the current one
			registers.writeBit(0xB, 7, false);
			return true;
		}
	}
	lastRB0 = registers.readBit(0x6, 0);
	lastRB4_7 = (registers.readByte(0x6) & 0xF0) >> 4;
	return false;
}

void CPU::setBreakpoint(int address)
{
	breakpointAddress = address;
}

void CPU::enableBreakpoint(bool enable)
{
	breakpointEnabled = enable;
}