#include <vector>
#include <memory>
#include <fmt/format.h>
#include "CPU.h"

int main()
{

	try {

		CPU cpu;
		cpu.registerData.writeData(12, 0xFF);
		uint16_t opcode = 0b0001000010001100;
		auto instruction = cpu.instructionHandler.decode(opcode);
		instruction->execute(opcode);


		printf("Carry: %d\n", cpu.registerData.getBit(0x3,0));
		fmt::print("Register: 0b{:b}\nW: 0b{:b}\n", cpu.registerData.readData(0xC), cpu.cpuRegisters.w);

	} catch (std::exception& e) {
		printf("ERROR: %s\n", e.what());
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
