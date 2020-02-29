#include <vector>
#include <memory>
#include <thread>
#include <fmt/format.h>

#include "CPU.h"
#include "LSTParser.h"

std::thread simulatorThread;

int main(int argc, char* argv[])
{

	simulatorThread = std::thread([&] {
		try {
			LSTParser parser;
			parser.readFile("/home/tfa/Desktop/PIC16F8X/BCDCounter.lst");
			parser.parseLstFile();

			CPU cpu;
			auto instruction = cpu.instructionHandler.decode(parser.getLstOpcodeInfo()[0].opcode);
			instruction->execute(parser.getLstOpcodeInfo()[0].opcode);
			while (cpu.registerData.getPC() < parser.getLstOpcodeInfo().size()) {
				auto& opcode = parser.getLstOpcodeInfo()[cpu.registerData.getPC()].opcode;
				instruction = cpu.instructionHandler.decode(opcode);
				instruction->execute(opcode);

				std::this_thread::sleep_for(std::chrono::milliseconds(5));
			}
		} catch (std::exception& e) {
			printf("ERROR: %s\n", e.
				what()
			);
		}
	});
	return 0;
}
