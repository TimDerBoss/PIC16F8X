#pragma once
#include <cstdint>

#include "RegisterData.h"
#include "InstructionHandler.h"

struct CPURegisters{
	uint8_t w;
};

class CPU
{
	public:
		CPU()
			: registerData(cpuRegisters)
			, instructionHandler(registerData)
		{
		}

		CPURegisters cpuRegisters;
		RegisterData registerData;
		InstructionHandler instructionHandler;
};
