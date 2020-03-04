#include "CPU.h"

#include <FormatString.h>

void CPU::initialize(const std::string& fileName)
{
	parser.readFile("BCDCounter.lst");
	parser.parseLstFile();
}

void CPU::singleStep()
{
		auto& opcode = parser.getLstOpcodeInfo()[registerData.getPC()].opcode;
		auto& instruction = instructionHandler.decode(opcode);
		instruction->execute(opcode);
		timeActive += instruction->getCycles();
}
