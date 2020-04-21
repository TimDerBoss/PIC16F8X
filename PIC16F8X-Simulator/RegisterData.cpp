#include "RegisterData.h"
#include "CPU.h"
#include "Exception.h"
#include <cassert>
#include <FormatString.h>

RegisterData::RegisterData(CPURegisters& cpuRegisters)
	: cpuRegisters(cpuRegisters)
{
	// set up ram array
	initialize();
	// reset all registers to the initial power-on values
	resetPowerOn();
	// reset w register
	cpuRegisters.w = 0;
}

uint8_t RegisterData::readBit(uint8_t address, uint8_t index)
{
	return *ram.at(address) >> index & 1;
}

void RegisterData::writeBit(uint8_t address, uint8_t index, bool value)
{
	*ram.at(address) &= ~(1 << index);
	*ram.at(address) |= value << index;
}

void RegisterData::writeByte(const uint8_t& address, unsigned char value)
{
	*ram.at(address) = value;
}

const uint8_t& RegisterData::readByte(const uint8_t& address)
{
	return *ram.at(address);
}

uint8_t RegisterData::readBitS(uint8_t address, uint8_t index)
{
	assert(address <= 0x7F);
	uint8_t adr = readBit(0x3, 5) ? address + 0x80 : address;
	return readBit(adr, index);
}

void RegisterData::writeBitS(uint8_t address, uint8_t index, bool value)
{
	assert(address <= 0x7F);
	uint8_t adr = readBit(0x3, 5) ? address + 0x80 : address;
	writeByte(adr, readByte(adr) & ~(1 << index));
	writeByte(adr, readByte(adr) | value << index);
}

void RegisterData::writeByteS(const uint8_t& address, unsigned char value)
{
	assert(address <= 0x7F);
	uint8_t adr = readBit(0x3, 5) ? address + 0x80 : address;
	writeByte(adr, value);;
}

const uint8_t& RegisterData::readByteS(const uint8_t& address)
{
	assert(address <= 0x7F);
	uint8_t adr = readBit(0x3, 5) ? address + 0x80 : address;
	return readByte(adr);
}

// reset all values to their power-on defaults
void RegisterData::resetPowerOn()
{
	initialize();
	cpuRegisters.w = 0;
	// Set default startup values
	writeByte(0x03, 0x18); // Status
	writeByte(0x81, 0xFF);
	writeByte(0x85, 0xFF);
	writeByte(0x86, 0xFF);
}

void RegisterData::initialize()
{
	ram.clear();
	for (int i = 0; i <= 0xFF; i++) {
		if (i == 0x80 || i == 0x82 || i == 0x83 || i == 0x84 || i == 0x8A || i == 0x8B || (i >=0x8C && i <= 0xAF)) {
			ram.push_back(ram.at(i - 0x80));
		}
		else {
			ram.push_back(std::make_shared<uint8_t>(0));
		}
	}
}

// increase the program counter by a given amount
void RegisterData::increasePCBy(uint16_t amount)
{
	uint16_t programCounter = 0;
	programCounter |= (readByte(0x2) & 0xFF);
	programCounter |= ((readByte(0xA) & 0x1F) << 8);
	programCounter += amount;
	writeByte(0x2, programCounter & 0xFF);
	writeByte(0xA, programCounter >> 8 & 0x1F);
}


// returns the current program counter value
uint16_t RegisterData::getPC()
{
	uint16_t programCounter = 0;
	programCounter |= (readByte(0x2) & 0xFF);
	programCounter |= ((readByte(0xA) & 0x1F) << 8);
	return programCounter;
}

// set the program counter
void RegisterData::setPC(const uint16_t& value)
{
	writeByte(0x2, value & 0xFF);
	writeByte(0xA, value >> 8 & 0x1F);
}
