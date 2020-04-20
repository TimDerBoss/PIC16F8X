#pragma once

#include "LSTParser.h"
#include "RegisterData.h"
#include "InstructionHandler.h"

#include <cstdint>
#include <string>

struct CPURegisters {
	uint8_t w{ 0 };
};


class CPU
{
public:
	CPU()
		: registerData(cpuRegisters)
		, instructionHandler(registerData)
	{
	}

	void initialize(const std::string& fileName);
	void singleStep();
	bool processInterrupts();

	int timeActive{ 0 };

	LstParser parser;
	CPURegisters cpuRegisters;
	RegisterData registerData;
	InstructionHandler instructionHandler;
};
