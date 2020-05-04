#pragma once

#include <iostream>
#include <map>
#include <string>
#include <stack>
#include <vector>
#include <functional>
#include <FormatString.h>

#include <boost/signals2/signal.hpp>

#include "Watchdog.h"

enum DataSource
{
	FromUser,
	FromCpu
};

class RegisterData
{
public:
	explicit RegisterData(struct CPU& cpu);
	void resetPowerOn();
	void otherReset();

	void initialize();

	uint8_t& dataReference(const uint8_t& address);
	uint8_t readBit(uint8_t address, uint8_t offset) const;
	uint8_t readBitS(uint8_t address, uint8_t offset) const;
	void writeBit(uint8_t address, uint8_t offset, bool value, DataSource source = FromCpu) const;
	void writeBitS(uint8_t address, uint8_t offset, bool value, DataSource source = FromCpu) const;
	const uint8_t& readByte(const uint8_t& address) const;
	const uint8_t& readByteS(const uint8_t& address) const;
	void writeByte(const uint8_t& address, unsigned char value, DataSource source = FromCpu) const;
	void writeByte(const uint8_t& address, const std::string& value, DataSource source = FromCpu) const;
	void writeByteS(const uint8_t& address, unsigned char value, DataSource source = FromCpu) const;


	void increasePCBy(uint16_t amount);
	const uint16_t& getPcl() const;

	struct CPURegisters& cpuRegisters;
	std::stack<uint16_t> stack;
	std::map<uint8_t, uint8_t> portBuffer;

	boost::signals2::signal<void(int address)> onRamRead;
	boost::signals2::signal<void(int address, int offset, int value, DataSource source)> onRamWrite;

	Watchdog watchdog;

private:
	void setBit(uint8_t& source, int offset, int value);
	std::vector<std::shared_ptr<uint8_t>> ram;
};