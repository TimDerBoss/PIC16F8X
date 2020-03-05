#pragma once

#include <iostream>
#include <map>
#include <cstring>
#include <stack>
#include <functional>

class RegisterData
{
public:
	explicit RegisterData(struct CPURegisters& cpuRegisters);
	void resetPowerOn();
	uint8_t readBitSimulated(uint8_t address, uint8_t index);
	void writeBitSimulated(uint8_t address, uint8_t index, bool value);
	const uint8_t& readDataSimulated(const uint8_t& address);
	void writeDataSimulated(const uint8_t& address, unsigned char value);
	void increasePCBy(uint16_t amount);
	uint16_t getPC();
	void setPC(const uint16_t& value);

	uint8_t readBitFromMemory(uint8_t address, uint8_t index);
	void writeBitToMemory(uint8_t address, uint8_t index, bool value);
	const uint8_t& readDataFromMemory(const uint8_t& address);
	void writeDataToMemory(const uint8_t& address, unsigned char value);

	struct CPURegisters& cpuRegisters;
	std::stack<uint16_t> stack;
private:
	uint16_t translateAddress(uint8_t address);
	uint8_t memoryMap[0xFF];
};