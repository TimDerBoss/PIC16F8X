#include "RegisterData.h"
#include "CPU.h"
#include "Exception.h"

#include <FormatString.h>

RegisterData::RegisterData(CPURegisters& cpuRegisters)
	: cpuRegisters(cpuRegisters)
{
	// reset all registers to the initial power-on values
	resetPowerOn();
	// reset w register
	cpuRegisters.w = 0;
}

// Read a simulated bit
// this function works like the real controller: bank 1 can only be acessed if rp0 ist set.
// this function is used for the simulation
uint8_t RegisterData::readBitSimulated(uint8_t address, uint8_t index)
{
	return memoryMap[translateAddress(address)] >> index & 1;
}

// write a simulated bit
// this function works like the real controller: bank 1 can only be acessed if rp0 ist set.
// this function is used for the simulation
void RegisterData::writeBitSimulated(uint8_t address, uint8_t index, bool value)
{
	uint16_t realAddr = translateAddress(address);
	memoryMap[realAddr] &= ~(1 << index);
	memoryMap[realAddr] |= value << index;
}

// reset all values to their power-on defaults
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

// same as witeBitSimulated but write a full byte
void RegisterData::writeDataSimulated(const uint8_t& address, unsigned char value)
{
	memoryMap[translateAddress(address)] = value;
}

// same as readBitSimulated but read a full byte
const uint8_t& RegisterData::readDataSimulated(const uint8_t& address)
{
	return memoryMap[translateAddress(address)];
}

// increase the program counter by a given amount
void RegisterData::increasePCBy(uint16_t amount)
{
	uint16_t programCounter = 0;
	programCounter |= (readDataFromMemory(0x2) & 0xFF);
	programCounter |= ((readDataFromMemory(0xA) & 0x1F) << 8);
	programCounter += amount;
	writeDataToMemory(0x2, programCounter & 0xFF);
	writeDataToMemory(0xA, programCounter >> 8 & 0x1F);
}

// The memory is shared across the banks.
// this means that there are addresses which hold the same data. Data duplication has to be prevented.
// SOLUTION:
// If we want to access a shared address like the the status register the bank doesnt matter so the function will always return the address in the first bank.
// if we want to access an address which isn't shared, 80h is addedd to the adderss to actually physically enter bank 1to store the data there
// this has no effect on the actual simulation. It actually helps to always specify adfdressed below 7fh and still write to bank 1
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

// returns the current program counter value
uint16_t RegisterData::getPC()
{
	uint16_t programCounter = 0;
	programCounter |= (readDataFromMemory(0x2) & 0xFF);
	programCounter |= ((readDataFromMemory(0xA) & 0x1F) << 8);
	return programCounter;
}

// write an actual bit in the memory
// this is not used for the simulation but rather for the ui to fetch data quickly
// this function allows direct access to addresses ranging from 0 to 255 so that banks don't need to be switched in order to read data for the ui thus interfering with the running simulation
uint8_t RegisterData::readBitFromMemory(uint8_t address, uint8_t index)
{
	return memoryMap[address] >> index & 1;
}

// write an actual bit in the memory
// this is not used for the simulation but rather for the ui to fetch data quickly
// this function allows direct access to addresses ranging from 0 to 255 so that banks don't need to be switched in order to read data for the ui thus interfering with the running simulation
void RegisterData::writeBitToMemory(uint8_t address, uint8_t index, bool value)
{
	memoryMap[address] &= ~(1 << index);
	memoryMap[address] |= value << index;
}

// same as writeBitToMemory but with a full byte
void RegisterData::writeDataToMemory(const uint8_t& address, unsigned char value)
{
	memoryMap[address] = value;
}

// same as readBitFromMemory but with a full byte
const uint8_t& RegisterData::readDataFromMemory(const uint8_t& address)
{
	return memoryMap[address];
}

// set the program counter
void RegisterData::setPC(const uint16_t& value)
{
	writeDataSimulated(0x2, value & 0xFF);
	writeDataSimulated(0xA, value >> 8 & 0x1F);
}
