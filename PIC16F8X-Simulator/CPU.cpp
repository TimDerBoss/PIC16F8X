#include "CPU.h"

#include <FormatString.h>

void CPU::initialize(const std::string& fileName)
{
	parser.readFile(fileName);
	parser.parseLstFile();
}

// run just the next instruction
void CPU::singleStep()
{
	// only while we haven't reached the end of the program
	if (registerData.getPC() <= parser.getMaxPc()) {
		// check if an interrupt has happened meanwhile
		if (processInterrupts()) {
			// jump to interrupt
			registerData.stack.push(registerData.getPC());
			registerData.setPC(4);
			timeActive += 4;
		}
		else {
			// else execute the normal code
			auto& opcode = parser.getOpcodeInfo(registerData.getPC()).opcode;
			auto& instruction = instructionHandler.decode(opcode);
			instruction->execute();
			timeActive += instruction->getCycles();
		}
	}
}

bool CPU::processInterrupts()
{
	static bool lastRB0;
	// GIE set
	if (registerData.readBit(0xB, 7))
	{
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
	lastRB0 = registerData.readBit(0x6, 0);
	return false;
}
