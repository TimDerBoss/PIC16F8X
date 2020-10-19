#include "gtest/gtest.h"

#include <RegisterData.h>
#include <CPU.h>

constexpr int TestMemoryAddress = 0x0C;

TEST(RegisterDataTest, WriteByte) {

	RegisterData registers;

	auto& ram = registers.getRam();
	uint8_t valueToWrite = 123;

	registers.writeByte(TestMemoryAddress, valueToWrite);
	EXPECT_EQ(*ram[TestMemoryAddress], valueToWrite);
}


TEST(RegisterDataTest, WriteBit) {

	RegisterData registers;

	auto& ram = registers.getRam();
	uint8_t bitIndex = 3;
	bool valueToWrite = true;

	registers.writeBit(TestMemoryAddress, bitIndex, valueToWrite);
	EXPECT_EQ((*ram[TestMemoryAddress] >> bitIndex) & 1, valueToWrite);
}


TEST(RegisterDataTest, ReadByte) {

	RegisterData registers;

	auto& ram = registers.getRam();
	uint8_t valueToRead = 123;
	*ram[TestMemoryAddress] = valueToRead;

	EXPECT_EQ(registers.readByte(TestMemoryAddress), valueToRead);
}


TEST(RegisterDataTest, ReadBit) {

	RegisterData registers;

	auto& ram = registers.getRam();
	uint8_t bitIndex = 3;
	bool valueToRead = true;

	*ram[TestMemoryAddress] = valueToRead << bitIndex;

	EXPECT_EQ(registers.readBit(TestMemoryAddress, bitIndex), valueToRead);
}