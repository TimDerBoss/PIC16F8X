#pragma once

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <functional>
#include <FormatString.h>

#include <boost/signals2/signal.hpp>

#include "Stack.h"
#include "Watchdog.h"
#include "Exception.h"
#include "Request.h"

struct CPURegisters {
	uint8_t accumulator{ 0 };
	uint16_t programCounter{ 0 };
};

enum Registers : uint8_t
{
	Status = 0x03,
	Option = 0x81,
	Intcon = 0xB,
	PortA = 0x5,
	PortB = 0x6,
	TrisA = 0x85,
	TrisB = 0x86,
	Pcl = 0x2,
	Pclath = 0xA
};


class RegisterData
{
public:
	RegisterData();
	void resetPowerOn();
	void otherReset();
	void initialize();

	uint8_t& dataReference(const uint8_t& address);

	uint8_t readBitS(uint8_t address, uint8_t offset) const;
	void writeBitS(uint8_t address, uint8_t offset, bool value, DataSource source = DataSource::FromCpu) const;
	const uint8_t& readByteS(const uint8_t& address) const;
	void writeByteS(const uint8_t& address, unsigned char value, DataSource source = DataSource::FromCpu) const;

	uint8_t readBit(uint8_t address, uint8_t offset) const;
	const uint8_t& readByte(const uint8_t& address) const;
	void writeBit(uint8_t address, uint8_t offset, bool value, DataSource source = DataSource::FromCpu) const;
	void writeByte(const uint8_t& address, unsigned char value, DataSource source = DataSource::FromCpu) const;

	int applyRequest(const Request::RequestData& req) const;

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

	boost::signals2::signal<void(int address, int offset, int value, DataSource source)> onRamWrite;

protected:
	boost::signals2::connection localRamConnection;
	void setBit(uint8_t& source, int offset, int value);
	std::vector<std::shared_ptr<uint8_t>> ram;
};