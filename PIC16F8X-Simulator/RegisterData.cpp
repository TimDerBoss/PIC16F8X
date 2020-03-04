#include "RegisterData.h"
#include "CPU.h"

#include <FormatString.h>

RegisterData::RegisterData(CPURegisters& cpuRegisters)
	: cpuRegisters(cpuRegisters)
{
	resetPowerOn();
	cpuRegisters.w = 0;
}

uint8_t RegisterData::getBit(uint8_t address, uint8_t index)
{
	return memoryMap[getPhysicalAddress(address)] >> index & 1;
}

void RegisterData::setBit(uint8_t address, uint8_t index, bool value)
{
	uint16_t realAddr = getPhysicalAddress(address);
	memoryMap[realAddr] &= ~(1 << index);
	memoryMap[realAddr] |= value << index;
}

void RegisterData::resetPowerOn()
{
	cpuRegisters.w = 0;
	// CLear all registers
	memset(memoryMap, 0, 0xFF);
	// Set default startup values
	writeRawData(0x03, 0x18); // Status
	writeRawData(0x81, 0xFF);
	writeRawData(0x85, 0xFF);
	writeRawData(0x86, 0xFF);
}

void RegisterData::writeData(const uint8_t& address, unsigned char value)
{
	memoryMap[getPhysicalAddress(address)] = value;
}

const uint8_t& RegisterData::readData(const uint8_t& address)
{
	return memoryMap[getPhysicalAddress(address)];
}

void RegisterData::increasePCBy(uint16_t amount)
{
	uint16_t programCounter = 0;
	programCounter |= (readData(0x2) & 0xFF);
	programCounter |= ((readData(0xA) & 0x1F) << 8);
	programCounter += amount;
	writeData(0x2, programCounter & 0xFF);
	writeData(0xA, programCounter >> 8 & 0x1F);
}


uint16_t RegisterData::getPhysicalAddress(uint8_t address)
{
	if (address > 0x7F) {
		throw std::runtime_error(fmt::format("%s: Tried to access register at address %2X. Max allowed address if 0x7F.\nDid you forget to switch register banks?", address));
	}
	// if bank 1
	if((memoryMap[0x03] >> 5) & 1) {
			if (address == 0x01 || address == 0x05 || address == 0x06 || address == 0x08 || address == 0x09) {
				address += 0x80;
			}
	}
	return address;
	// printf("Accessing Address 0x%X at Bank %d\n", address, (memoryMap[0x03] >> 5) & 1);

}

uint16_t RegisterData::getPC()
{
	uint16_t programCounter = 0;
	programCounter |= (readData(0x2) & 0xFF);
	programCounter |= ((readData(0xA) & 0x1F) << 8);
	return programCounter;
}

uint8_t RegisterData::getRawBit(uint8_t address, uint8_t index)
{
	return memoryMap[address] >> index & 1;
}

void RegisterData::setRawBit(uint8_t address, uint8_t index, bool value)
{
	memoryMap[address] &= ~(1 << index);
	memoryMap[address] |= value << index;
}

void RegisterData::writeRawData(const uint8_t& address, unsigned char value)
{
	memoryMap[address] = value;
}

const uint8_t& RegisterData::readRawData(const uint8_t& address)
{
	return memoryMap[address];
}

void RegisterData::setPC(const uint16_t& value)
{
	writeData(0x2, value & 0xFF);
	writeData(0xA, value >> 8 & 0x1F);
}
