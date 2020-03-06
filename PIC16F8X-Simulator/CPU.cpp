#include "CPU.h"

#include <FormatString.h>

void CPU::initialize(const std::string& fileName)
{
	parser.readFile("BCDCounter.lst");
	parser.parseLstFile();
}

void CPU::singleStep()
{
	if (registerData.getPC() <= parser.getMaxPc()) {
		uint16_t opcode;
		if (processInterrupts()) {
			opcode = 0b0010000000000100;
		}
		else {
			opcode = parser.getOpcodeInfo(registerData.getPC()).opcode;
		}
		auto& instruction = instructionHandler.decode(opcode);
		instruction->execute();
		timeActive += instruction->getCycles();
	}
}

bool CPU::processInterrupts()
{
	static bool lastRB0;
	// GIE set
	if (registerData.readBitFromMemory(0xB, 7))
	{
		// INTE set && Flanke && ((RB0 && IntEdg) || (!RB0 && !IntEdg))
		if (registerData.readBitFromMemory(0xB, 4)
			&& lastRB0 != static_cast<bool>(registerData.readBitFromMemory(0x6, 0))
			&& registerData.readBitFromMemory(0x6, 0) == registerData.readBitFromMemory(0x81, 6)
			)
		{
			// Disable GIE to prevent further Interrupts while executing the current one
			registerData.writeBitToMemory(0xB, 7, false);
			// Set the INTF flag
			registerData.writeBitToMemory(0xB, 1, true);
			return true;
		}
	}
	lastRB0 = registerData.readBitFromMemory(0x6, 0);
	return false;
}
