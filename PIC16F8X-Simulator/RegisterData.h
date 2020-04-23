#pragma once

#include <iostream>
#include <map>
#include <cstring>
#include <stack>
#include <vector>
#include <functional>

#include <boost/signals2/signal.hpp>

class RegisterData
{
public:
	explicit RegisterData(struct CPURegisters& cpuRegisters);
	void resetPowerOn();

	void initialize();

	uint8_t readBit(uint8_t address, uint8_t index) const;
	uint8_t readBitS(uint8_t address, uint8_t index) const;
	void writeBit(uint8_t address, uint8_t index, bool value) const;
	void writeBitS(uint8_t address, uint8_t index, bool value) const;
	const uint8_t& readByte(const uint8_t& address) const;
	const uint8_t& readByteS(const uint8_t& address) const;
	void writeByte(const uint8_t& address, unsigned char value) const;
	void writeByteS(const uint8_t& address, unsigned char value) const;


	void increasePCBy(uint16_t amount);
	const uint16_t& getPcl() const;

	struct CPURegisters& cpuRegisters;
	std::stack<uint16_t> stack;


	boost::signals2::signal<void(int address)> onRamRead;
	boost::signals2::signal<void(int address)> onRamWrite;
private:
	std::vector<std::shared_ptr<uint8_t>> ram;
};