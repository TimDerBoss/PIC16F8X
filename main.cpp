#include <vector>
#include <memory>
#include <fmt/format.h>
#include "CPU.h"
#include "LSTParser.h"

#include <thread>

#include <fstream>

int main()
{
	try {
		LSTParser parser;
		parser.readFile("/home/tfa/Desktop/PIC16F8X/BCDCounter.lst");
		parser.parseLstFile();

		CPU cpu;
		auto instruction = cpu.instructionHandler.decode(parser.getLstOpcodeInfo()[0].opcode);
		instruction->execute(parser.getLstOpcodeInfo()[0].opcode);
		while(cpu.registerData.getPC() < parser.getLstOpcodeInfo().size())
		{
			auto& opcode = parser.getLstOpcodeInfo()[cpu.registerData.getPC()].opcode;
			instruction = cpu.instructionHandler.decode(opcode);
			instruction->execute(opcode);
		}

		//printf("Carry: %d\n", cpu.registerData.getBit(0x3, 0));
		//fmt::print("Register: 0b{:b}\nW: 0b{:b}\n", cpu.registerData.readData(0xC), cpu.cpuRegisters.w);
	} catch (
		std::exception& e
	) {
		printf("ERROR: %s\n", e.
			what()
		);
	}

/*
rd.resetPowerOn();
rd.setBit(3, 5, true);
rd.writeData(1, 5);
rd.setBit(3, 5, false);
rd.writeData(1, 5);
rd.writeData(4, 1);
rd.writeData(1, 1);
rd.writeData(5, 1);

rd.setBit(3, 5, 1);
rd.writeData(5, 1);
rd.writeData(4, 1);*/

	return 0;
}
