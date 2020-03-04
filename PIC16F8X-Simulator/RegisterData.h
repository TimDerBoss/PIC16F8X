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
		uint8_t getBit(uint8_t address, uint8_t index);
		void setBit(uint8_t address, uint8_t index, bool value);
		void writeData(const uint8_t& address, unsigned char value);
		const uint8_t& readData(const uint8_t& address);
		void increasePCBy(uint16_t amount);
		uint16_t getPC();
		void setPC(const uint16_t& value);

		std::function<void(const uint8_t& address)> onMemoryUpdate;

		struct CPURegisters& cpuRegisters;
		std::stack<uint16_t> stack;
	private:
		uint16_t getPhysicalAddress(uint8_t address);
		uint8_t memoryMap[0xFF];
};