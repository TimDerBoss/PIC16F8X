#include "RegisterData.h"
#include "CPU.h"
#include "Exception.h"

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

// Read a simulated bit
// this function works like the real controller: bank 1 can only be acessed if rp0 ist set.
// this function is used for the simulation
uint8_t RegisterData::readBit(uint8_t address, uint8_t index)
{
	return *ram.at(address) >> index & 1;
}

// write a simulated bit
// this function works like the real controller: bank 1 can only be acessed if rp0 ist set.
// this function is used for the simulation
void RegisterData::writeBit(uint8_t address, uint8_t index, bool value)
{
	*ram.at(address) &= ~(1 << index);
	*ram.at(address) |= value << index;
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

// same as witeBitSimulated but write a full byte
void RegisterData::writeByte(const uint8_t& address, unsigned char value)
{
	*ram.at(address)= value;
}

// same as readBitSimulated but read a full byte
const uint8_t& RegisterData::readByte(const uint8_t& address)
{
	return *ram.at(address);
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
