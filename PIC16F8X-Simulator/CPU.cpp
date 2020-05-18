#include "CPU.h"

#include <FormatString.h>

CPU::CPU()
{
	this->onCpuTimeChanged.connect([this](double difference) {
		timeActive += difference;
		});
}

// run just the next instruction
void CPU::singleStep(RegisterData& registerData, uint16_t opcode)
{
	// check if an interrupt has happened meanwhile
	if (processInterrupts(registerData)) {
		// jump to interrupt
		registerData.stack.push(registerData.getPc());
		registerData.writeByte(0x2, 4);
		onCpuTimeChanged(4 / (clockSpeed / 4.0));
		cycles++;
		return;
	}

	// else execute the normal code
	auto& instruction = instructionHandler.decode(opcode);
	instruction->execute(registerData);
	onCpuTimeChanged(instruction->getCycles() / (clockSpeed / 4.0));
	cycles++;


	// TODO: timer inerrupt
	// T0CS
	static uint8_t lastRA4 = 0;
	static int counter = 0;
	if (!registerData.readBit(0x81, 5))
	{
		counter += instruction->getCycles();
	}
	else { // T0CS == 1

		// !T0SE -> Rising edge on RA4
		if (!registerData.readBit(0x81, 5)) {
			if (lastRA4 != registerData.readBit(5, 4) && lastRA4 == 0) {
				// rising edge on RA4
				counter += 1;
			}
		}
		else { // Falling edge on RA4
			if (lastRA4 != registerData.readBit(5, 4) && lastRA4 == 1) {
				// falling edge on RA4
				counter += 1;
			}
		}
	}
	// prescaler (PSA Bit == 0)
	int prescaleValue = 0;
	if (registerData.readBit(0x81, 3) == 0)
		prescaleValue = 2 << (registerData.readByte(0x81) & 0x7);
	else
		prescaleValue = 1;
	if (counter >= prescaleValue) {
		// T0IE && overflow
		if (registerData.readBit(0xB, 5) && registerData.readByte(1) == 0xFF)
		{
			// intcon - t0if
			registerData.writeBit(0xB, 2, true);
		}
		registerData.writeByte(1, registerData.readByte(1) + 1);
		counter = 0;
	}
	lastRA4 = registerData.readBit(0x5, 4);
}

bool CPU::processInterrupts(RegisterData& registerData)
{
	static uint8_t lastRB0;
	static uint8_t lastRB4_7;
	// GIE set
	if (registerData.readBit(0xB, 7))
	{
		// RB0 Interrupt
		// INTE set && Flanke && ((RB0 && IntEdg) || (!RB0 && !IntEdg))
		if (registerData.readBit(0xB, 4)
			&& lastRB0 != static_cast<bool>(registerData.readBit(0x6, 0))
			&& registerData.readBit(0x6, 0) == registerData.readBit(0x81, 6)
			)
		{
			// Disable GIE to prevent further Interrupts while executing the current one
			registerData.writeBit(0xB, 7, false);
			// Set the INTF flag
			registerData.writeBit(0xB, 1, true);
			return true;
		}

		// RB4-7 Interrupt
		// INTE set && Geänderte Flanke
		if (lastRB4_7 != ((registerData.readByte(0x6) & 0xF0) >> 4))
		{
			// Disable GIE to prevent further Interrupts while executing the current one
			registerData.writeBit(0xB, 7, false);
			// Set the RBIF flag
			registerData.writeBit(0xB, 0, true);
			return true;
		}

		// Timer0 Interrupt
		// T0IE set && T0IF
		if (registerData.readBit(0xB, 5) && registerData.readBit(0xB, 2))
		{
			// Disable GIE to prevent further Interrupts while executing the current one
			registerData.writeBit(0xB, 7, false);
			return true;
		}
	}
	lastRB0 = registerData.readBit(0x6, 0);
	lastRB4_7 = (registerData.readByte(0x6) & 0xF0) >> 4;
	return false;
}
