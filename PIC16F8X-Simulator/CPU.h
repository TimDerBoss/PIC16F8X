#pragma once

#include "LSTParser.h"
#include "RegisterData.h"
#include "InstructionHandler.h"

#include <cstdint>
#include <string>

struct CPU
{
	CPU(const std::vector<LstOpcodeInfo>& lstOpcodeInfo);

	void start(double clockSpeed);
	void stop();
	void singleStep(int programCounter);
	bool processInterrupts();
	void setBreakpoint(int address);
	void enableBreakpoint(bool enable);


	bool breakpointEnabled{ false };
	int breakpointAddress = 0;

	bool processorActive{ false };
	std::thread processorThread;
	double timeActive{ 0 };
	double clockSpeed{ 0 };
	int cycles{ 0 };
	RegisterData registers;
	// TODO: watchdog
	// Watchdog watchdog;
	InstructionHandler instructionHandler;
	boost::signals2::signal<void(double difference)> onCpuTimeChanged;
};
