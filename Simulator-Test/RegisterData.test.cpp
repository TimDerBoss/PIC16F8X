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

/**********************************************************************************************************
* Simulated Command Tests
* The simulated address range reaches from 00h to 7fh, anything above should trigger an ecxeption
***********************************************************************************************************/
TEST(RegisterDataTest, ReadBitSimulatedAddressRange) {

	RegisterData registers; 

	EXPECT_ANY_THROW(registers.readBitS(0x8F, 0));
	EXPECT_NO_THROW(registers.readBitS(0x0F, 0));
}


TEST(RegisterDataTest, ReadByteSimulatedAddressRange) {

	RegisterData registers;

	EXPECT_ANY_THROW(registers.readByteS(0x8F));
	EXPECT_NO_THROW(registers.readByteS(0x0F));
}


TEST(RegisterDataTest, WriteBitSimulatedAddressRange) {

	RegisterData registers;

	EXPECT_ANY_THROW(registers.writeBitS(0x8F, 0, false, DataSource::FromUser));
	EXPECT_NO_THROW(registers.writeBitS(0x0F, 0, false, DataSource::FromUser));
}


TEST(RegisterDataTest, WriteByteSimulatedAddressRange) {

	RegisterData registers;

	EXPECT_ANY_THROW(registers.writeByteS(0x8F, 0, DataSource::FromUser));
	EXPECT_NO_THROW(registers.writeByteS(0x0F, 0, DataSource::FromUser));
}