#include <vector>
#include <memory>
#include <thread>
#include <fmt/format.h>

#include <QApplication>
#include <QCommandLineOption>

#include "CPU.h"
#include "LSTParser.h"
#include "SimulatorUi.h"

std::thread simulatorThread;

int main(int argc, char* argv[])
{
	QApplication app(argc, argv);
	QMainWindow wnd;
	Ui::MainWindow mainWin;
	mainWin.setupUi(&wnd);
	wnd.show();

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

				mainWin.setText(cpu, 0);
				std::this_thread::sleep_for(std::chrono::milliseconds(5));
			}
		} catch (std::exception& e) {
			printf("ERROR: %s\n", e.
				what()
			);
		}
	});

	app.exec();
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
