#include "RegisterData.h"
#include "CPU.h"
#include "Exception.h"

#include <FormatString.h>

RegisterData::RegisterData(CPURegisters& cpuRegisters)
	: cpuRegisters(cpuRegisters)
{
	resetPowerOn();
	cpuRegisters.w = 0;
}

uint8_t RegisterData::readBitSimulated(uint8_t address, uint8_t index)
{
	return memoryMap[translateAddress(address)] >> index & 1;
}

void RegisterData::writeBitSimulated(uint8_t address, uint8_t index, bool value)
{
	uint16_t realAddr = translateAddress(address);
	memoryMap[realAddr] &= ~(1 << index);
	memoryMap[realAddr] |= value << index;
}

void RegisterData::resetPowerOn()
{
	cpuRegisters.w = 0;
	// CLear all registers
	memset(memoryMap, 0, 0xFF);
	// Set default startup values
	writeDataToMemory(0x03, 0x18); // Status
	writeDataToMemory(0x81, 0xFF);
	writeDataToMemory(0x85, 0xFF);
	writeDataToMemory(0x86, 0xFF);
}

void RegisterData::writeDataSimulated(const uint8_t& address, unsigned char value)
{
	memoryMap[translateAddress(address)] = value;
}

const uint8_t& RegisterData::readDataSimulated(const uint8_t& address)
{
	return memoryMap[translateAddress(address)];
}

void RegisterData::increasePCBy(uint16_t amount)
{
	uint16_t programCounter = 0;
	programCounter |= (readDataFromMemory(0x2) & 0xFF);
	programCounter |= ((readDataFromMemory(0xA) & 0x1F) << 8);
	programCounter += amount;
	writeDataToMemory(0x2, programCounter & 0xFF);
	writeDataToMemory(0xA, programCounter >> 8 & 0x1F);
}


uint16_t RegisterData::translateAddress(uint8_t address)
{
	if (address > 0x7F) {
		throw exception("Tried to access register at address %2X. Max allowed address if 0x7F.\nDid you forget to switch register banks?", address);
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
	programCounter |= (readDataFromMemory(0x2) & 0xFF);
	programCounter |= ((readDataFromMemory(0xA) & 0x1F) << 8);
	return programCounter;
}

uint8_t RegisterData::readBitFromMemory(uint8_t address, uint8_t index)
{
	return memoryMap[address] >> index & 1;
}

void RegisterData::writeBitToMemory(uint8_t address, uint8_t index, bool value)
{
	memoryMap[address] &= ~(1 << index);
	memoryMap[address] |= value << index;
}

void RegisterData::writeDataToMemory(const uint8_t& address, unsigned char value)
{
	memoryMap[address] = value;
}

const uint8_t& RegisterData::readDataFromMemory(const uint8_t& address)
{
	return memoryMap[address];
}

void RegisterData::setPC(const uint16_t& value)
{
	writeDataSimulated(0x2, value & 0xFF);
	writeDataSimulated(0xA, value >> 8 & 0x1F);
}
