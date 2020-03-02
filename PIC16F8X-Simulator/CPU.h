#pragma once
#include <cstdint>
#include <string>

#include "LSTParser.h"
#include "RegisterData.h"
#include "InstructionHandler.h"

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

	LSTParser parser;
	CPURegisters cpuRegisters;
	RegisterData registerData;
	InstructionHandler instructionHandler;
};
