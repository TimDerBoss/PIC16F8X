#include "CPU.h"

#include <FormatString.h>

// run just the next instruction
void CPU::singleStep(RegisterData& registerData, uint16_t opcode)
{
	// check if an interrupt has happened meanwhile
	if (processInterrupts(registerData)) {
		// jump to interrupt
		registerData.stack.push(registerData.getPcl());
		registerData.writeByte(0x82, 4);
		timeActive += 4 / (clockSpeed / 4.0);
		cycles++;
	}
	else {
		// else execute the normal code
		auto& instruction = instructionHandler.decode(opcode);
		instruction->execute(registerData);
		timeActive += instruction->getCycles() / (clockSpeed / 4.0);
		cycles++;
	}

//	// T0CS
//	if (!registerData.readBit(0x81, 5))
//	{
//		static int lastCycles = 0;
//		// T0IE && overflow
//		if (registerData.readBit(0xB, 5) && registerData.readByte(1) == 0xFF)
//		{
//			// intcon - t0if
//			registerData.writeBit(0xB, 2, true);
//		}
//		if (cycles - lastCycles >= 2) {
//			registerData.writeByte(1, registerData.readByte(1) + 1);
//			lastCycles = cycles;
//		}
//	}
}

bool CPU::processInterrupts(RegisterData& registerData)
{
	static bool lastRB0;
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
	}
	// Timer0 Interrupt
	// T0IE set && T0IF
	if (registerData.readBit(0xB, 5) && registerData.readBit(0xB, 2))
	{
		// Disable GIE to prevent further Interrupts while executing the current one
		registerData.writeBit(0xB, 7, false);
		return true;
	}
	lastRB0 = registerData.readBit(0x6, 0);
	return false;
}
