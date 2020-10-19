#pragma once

#include "gtest/gtest.h"

#include <Instructions.h>
#include <RegisterData.h>
#include <CPU.h>

constexpr int TEST_MEMORY_LOCATION = 0x0C;


TEST(InstructionTest, Addwf) {

	CPU cpu;
	RegisterData registerData(cpu);
	InstructionData instructionData;

	ADDWF instruction("test", 0, 0);

	registerData.writeByte(TEST_MEMORY_LOCATION, 12);
	instructionData.f = TEST_MEMORY_LOCATION;
	instructionData.d = 0;
	registerData.cpuRegisters.w = 2;
	instruction.execute(registerData, instructionData);
	EXPECT_EQ(registerData.cpuRegisters.w, 14);

	instructionData.d = 1;
	instruction.execute(registerData, instructionData);
	EXPECT_EQ(registerData.readByte(TEST_MEMORY_LOCATION), 26);
}