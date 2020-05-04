#pragma once

#include "LSTParser.h"
#include "RegisterData.h"
#include "InstructionHandler.h"

#include <cstdint>
#include <string>

struct CPURegisters {
	uint8_t w{ 0 };
	uint16_t programCounter{ 0 };
};


struct CPU
{
	CPU();

	void singleStep(RegisterData& registerData, uint16_t opcode);
	bool processInterrupts(RegisterData& registerData);
	double timeActive{ 0 };
	double clockSpeed{ 0 };
	int cycles{ 0 };
	CPURegisters cpuRegisters;
	InstructionHandler instructionHandler;
	boost::signals2::signal<void(double difference)> onCpuTimeChanged;
};
