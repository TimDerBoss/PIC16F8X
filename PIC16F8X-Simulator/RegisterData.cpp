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

uint8_t RegisterData::readBit(uint8_t address, uint8_t index) const
{
	onRamRead(address);
	return *ram.at(address) >> index & 1;
}

void RegisterData::writeBit(uint8_t address, uint8_t offset, bool value) const
{
	onRamWrite(address, offset, value);
}

void RegisterData::writeByte(const uint8_t& address, unsigned char value) const
{
	for (int i = 0; i < 8; i++)
		writeBit(address, i, (value >> i) & 1);
}

const uint8_t& RegisterData::readByte(const uint8_t& address) const
{
	onRamRead(address);
	return *ram.at(address);
}

uint8_t RegisterData::readBitS(uint8_t address, uint8_t index) const
{
	assert(address <= 0x7F);
	uint8_t adr = readBit(0x3, 5) ? address + 0x80 : address;
	return readBit(adr, index);
}

void RegisterData::writeBitS(uint8_t address, uint8_t offset, bool value) const
{
	assert(address <= 0x7F);
	uint8_t adr = readBit(0x3, 5) ? address + 0x80 : address;
	writeBit(adr, offset, value); // clear bit
}

void RegisterData::writeByteS(const uint8_t& address, unsigned char value) const
{
	assert(address <= 0x7F);
	uint8_t adr = readBit(0x3, 5) ? address + 0x80 : address;
	writeByte(adr, value);
}

const uint8_t& RegisterData::readByteS(const uint8_t& address) const
{
	assert(address <= 0x7F);
	uint8_t adr = readBit(0x3, 5) ? address + 0x80 : address;
	return readByte(adr);
}

// reset all values to their power-on defaults
void RegisterData::resetPowerOn()
{
	initialize();
	writeByte(0x2, 0);
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
		if (i == 0x80 || i == 0x82 || i == 0x83 || i == 0x84 || i == 0x8A || i == 0x8B || (i >= 0x8C && i <= 0xAF)) {
			ram.push_back(ram.at(i - 0x80));
		}
		else {
			ram.push_back(std::make_shared<uint8_t>(0));
		}
	}

	onRamWrite.connect([this](int address, int offset, int value) {
		if ((address == 0x5 || address == 0x6) && readBit(address + 0x80, offset)) {
			// if trying to set a port bit while its tris bit is set to input buffer the value
			portBuffer[address + offset] = value;
		}
		else if ((address == 0x85 || address == 0x86) && value == 0) {
			// if a tris bit is set to output write the buffered port value into the corresopnding port (if available)
			int portAdr = address - 0x80;
			int portBitAdr = portAdr + offset;
			if (portBuffer.find(portBitAdr) != portBuffer.end()) {
				setBit(*ram.at(portAdr), offset, portBuffer[portBitAdr]);
				setBit(*ram.at(address), offset, value);
				portBuffer.erase(portBitAdr);
			}
		}
		else {
			setBit(*ram.at(address), offset, value);
			if (address == 0x2)
			{
				this->cpuRegisters.programCounter = readByte(0x2) & 0xFF;
				this->cpuRegisters.programCounter |= ((readByte(0xA) & 0x1F) << 8);
			}
		}
		});
}

// increase the program counter by a given amount
void RegisterData::increasePCBy(uint16_t amount)
{
	cpuRegisters.programCounter = getPcl() + amount;
	writeByte(0x82, cpuRegisters.programCounter & 0xFF);
}


// returns the current program counter value
const uint16_t& RegisterData::getPcl() const
{
	return cpuRegisters.programCounter;
}

void RegisterData::setBit(uint8_t& source, int offset, int value)
{
	source &= ~(1 << offset);
	source |= value << offset;
}
