#pragma once

#include <iostream>
#include <map>
#include <cstring>
#include <stack>
#include <vector>
#include <functional>

class RegisterData
{
public:
	explicit RegisterData(struct CPURegisters& cpuRegisters);
	void resetPowerOn();

	void initialize();

	uint8_t readBit(uint8_t address, uint8_t index);
	void writeBit(uint8_t address, uint8_t index, bool value);
	const uint8_t& readByte(const uint8_t& address);
	void writeByte(const uint8_t& address, unsigned char value);

	uint8_t readBitS(uint8_t address, uint8_t index);
	void writeBitS(uint8_t address, uint8_t index, bool value);
	const uint8_t& readByteS(const uint8_t& address);
	void writeByteS(const uint8_t& address, unsigned char value);


	void increasePCBy(uint16_t amount);
	uint16_t getPC();
	void setPC(const uint16_t& value);

	struct CPURegisters& cpuRegisters;
	std::stack<uint16_t> stack;
private:
	std::vector<std::shared_ptr<uint8_t>> ram;
};