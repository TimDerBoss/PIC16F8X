#include "gtest/gtest.h"

#include <Instructions.h>
#include <RegisterData.h>
#include <CPU.h>

constexpr int TestMemoryAddress = 0x0C;

// overwrite all methods wich are possibly needed by an instruction
class RegisterDataMock : public RegisterData
{
public:

	RegisterDataMock()
	{
		for (int i = 0; i <= 0xFF; i++) {
			ram.push_back(std::make_shared<uint8_t>(0));
		}
	}

	uint8_t readBitS(uint8_t address, uint8_t offset) const 
	{
		return (*ram[address] >> offset) & 1;
	}

	void writeBitS(uint8_t address, uint8_t offset, bool value, DataSource source = FromCpu) const
	{
		*ram[address] |= (value << offset);
	}

	const uint8_t& readByteS(const uint8_t& address) const
	{
		return *ram[address];
	}

	void writeByteS(const uint8_t& address, unsigned char value, DataSource source = FromCpu) const
	{
		*ram[address] = value;
	}

	void increasePCBy(uint16_t amount)
	{
	}
};


TEST(InstructionTest, Addwf) {

	RegisterDataMock registers;
	InstructionData instructionData;
	ADDWF instruction("InstructionName", 0, 0);

	// set the corresponding memory address to a value to be added to the accumulator
	registers.writeByteS(TestMemoryAddress, 12);
	instructionData.fileRegisterAddress = TestMemoryAddress;
	registers.cpuRegisters.accumulator = 2;
	// store the result in the accumulator
	instructionData.destination = ResultDestination::ToAccumulator;

	// add the contents of the specified register to the accumulator
	instruction.execute(registers, instructionData);
	EXPECT_EQ(registers.cpuRegisters.accumulator, 14);
}