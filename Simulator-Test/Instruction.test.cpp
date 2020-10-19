#pragma once

#include "gtest/gtest.h"

#include <Instructions.h>
#include <RegisterData.h>
#include <CPU.h>

constexpr int TEST_MEMORY_LOCATION = 0x0C;


TEST(InstructionTest, Addwf) {

	CPU cpu;
	RegisterData registers(cpu);
	InstructionData instructionData;
	ADDWF instruction("InstructionName", 0, 0);

	// get reference of memory instead of using the writeByte method because this shouldn't be an integration test
	auto& ram = registers.getRam();

	// set the corresponding memory address to a value to be added to the accumulator
	instructionData.fileRegisterAddress = TEST_MEMORY_LOCATION;
	*ram[TEST_MEMORY_LOCATION] = 12;
	registers.cpuRegisters.accumulator = 2;

	// add the contents of the specified register to the accumulator and store the result in the accumulator
	instructionData.destination = ResultDestination::ToAccumulator;
	instruction.execute(registers, instructionData);
	EXPECT_EQ(registers.cpuRegisters.accumulator, 14);
}