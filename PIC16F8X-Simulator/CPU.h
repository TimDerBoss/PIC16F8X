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
	void singleStep(RegisterData& registerData, uint16_t opcode);
	bool processInterrupts(RegisterData& registerData);
	int timeActive{ 0 };
	CPURegisters cpuRegisters;
	InstructionHandler instructionHandler;
};
