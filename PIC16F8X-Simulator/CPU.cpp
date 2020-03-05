#include "CPU.h"

#include <FormatString.h>

void CPU::initialize(const std::string& fileName)
{
	parser.readFile("BCDCounter.lst");
	parser.parseLstFile();
}

void CPU::singleStep()
{
	uint16_t opcode;
	if (processInterrupts()) {
		opcode = 0b0010000000000100;
	}
	else {
		opcode = parser.getLstOpcodeInfo()[registerData.getPC()].opcode;
	}
	auto& instruction = instructionHandler.decode(opcode);
	instruction->execute();
	timeActive += instruction->getCycles();

	registerData.setPC(std::min(registerData.getPC(), static_cast<uint16_t>(parser.getLstOpcodeInfo().size() - 1)));
}

bool CPU::processInterrupts()
{
	static bool lastRB0;
	// GIE set
	if (registerData.getRawBit(0xB, 7))
	{
		// INTE set && Flanke && ((RB0 && IntEdg) || (!RB0 && !IntEdg))
		if (registerData.getRawBit(0xB, 4)
			&& lastRB0 != static_cast<bool>(registerData.getRawBit(0x6, 0))
			&& registerData.getRawBit(0x6, 0) == registerData.getRawBit(0x81, 6)
			)
		{
			// Disable GIE to prevent further Interrupts while executing the current one
			registerData.setRawBit(0xB, 7, false);
			// Set the INTF flag
			registerData.setRawBit(0xB, 1, true);
			return true;
		}
	}
	lastRB0 = registerData.getRawBit(0x6, 0);
	return false;
}
