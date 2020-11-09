#pragma once

#include <iostream>
#include <map>
#include <string>
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

class Stack {
public:
	Stack() {
		values.clear();
	}
	int pop() {
		auto tmp = values.back();
		values.pop_back();
		return tmp;
	}
	void push(int value) {
		if (values.size() == 8)
			values.erase(values.begin());
		values.push_back(value);
	}
	int at(int idx) {
		return values.at(idx);
	}
	int top() {
		return values.back();
	}
	void clear() {
		values.clear();
	}
	inline int Size() { return static_cast<int>(values.size()); }
private:
	std::vector<int> values;
};

struct CPURegisters {
	uint8_t accumulator{ 0 };
	uint16_t programCounter{ 0 };
};

class RegisterData
{
public:
	RegisterData();
	void resetPowerOn();
	void otherReset();

	void initialize();

	uint8_t& dataReference(const uint8_t& address);
	uint8_t readBit(uint8_t address, uint8_t offset) const;
	uint8_t readBitS(uint8_t address, uint8_t offset) const;
	void writeBit(uint8_t address, uint8_t offset, bool value, DataSource source = DataSource::FromCpu) const;
	void writeBitS(uint8_t address, uint8_t offset, bool value, DataSource source = DataSource::FromCpu) const;
	const uint8_t& readByte(const uint8_t& address) const;
	const uint8_t& readByteS(const uint8_t& address) const;
	void writeByte(const uint8_t& address, unsigned char value, DataSource source = DataSource::FromCpu) const;
	void writeByte(const uint8_t& address, const std::string& value, DataSource source = DataSource::FromCpu) const;
	void writeByteS(const uint8_t& address, unsigned char value, DataSource source = DataSource::FromCpu) const;

	const std::array<bool, 8> getRegisterBits(uint8_t address) const;
	void increasePCBy(uint16_t amount);
	const uint16_t& getPc() const;
	const void setPc(const uint16_t& value);

	inline std::vector<std::shared_ptr<uint8_t>>& getRam() {
		return ram;
	}

	CPURegisters cpuRegisters;
	Stack stack;
	std::map<uint8_t, uint8_t> portBuffer;

	boost::signals2::signal<uint8_t(int address)> onRamRead;
	boost::signals2::signal<void(int address, int offset, int value, DataSource source)> onRamWrite;

protected:
	boost::signals2::connection localRamConnection;
	void setBit(uint8_t& source, int offset, int value);
	std::vector<std::shared_ptr<uint8_t>> ram;
};