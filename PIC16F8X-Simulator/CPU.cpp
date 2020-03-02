#include "CPU.h"
#include "format.h"

#include <Windows.h>

void CPU::initialize(const std::string& fileName)
{
	parser.readFile("BCDCounter.lst");
	parser.parseLstFile();
}

void CPU::singleStep()
{
	try {
		auto& opcode = parser.getLstOpcodeInfo()[registerData.getPC()].opcode;
		auto& instruction = instructionHandler.decode(opcode);
		instruction->execute(opcode);
	}
	catch (std::exception& e) {
		MessageBoxA(GetActiveWindow(), fmt::format("%s failed: %s", __FUNCTION__, e.what()).c_str(), "CPU Error", MB_OK | MB_ICONERROR);
	}
}
