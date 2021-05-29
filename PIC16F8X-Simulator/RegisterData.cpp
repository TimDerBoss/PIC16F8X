#include "RegisterData.h"
#include "CPU.h"
#include "Exception.h"
#include <cassert>
#include <FormatString.h>
#include <array>

RegisterData::RegisterData()
{
	initialize();
	resetPowerOn();
	cpuRegisters.accumulator = 0;
}

bool RegisterData::validateSimulatedAddress(const uint8_t& address) const 
{
	return address <= 0x7F;
}

void RegisterData::throwIllegalAddressException() const
{
	throw fatal_exception("Simulated address must be smaller than 0x80");
}

uint8_t& RegisterData::dataReference(const uint8_t& address)
{
	return *ram.at(address);
}

uint8_t RegisterData::readBit(uint8_t address, uint8_t index) const
{
	return readByte(address) >> index & 1;
}

void RegisterData::writeBit(uint8_t address, uint8_t offset, bool value, DataSource source) const
{
	onRamWrite(address, offset, value, source);
}

void RegisterData::writeByte(const uint8_t& address, unsigned char value, DataSource source) const
{
	for (int i = 0; i < 8; i++)
		writeBit(address, i, (value >> i) & 1, source);
}

const uint8_t& RegisterData::readByte(const uint8_t& address) const
{
	if (address == 0 && *ram.at(4) != 0)
		return *ram.at(*ram.at(4));
	return *ram.at(address);
}

uint8_t RegisterData::readBitS(uint8_t address, uint8_t index) const
{
	if (!validateSimulatedAddress(address)) throwIllegalAddressException();
	uint8_t adr = readBit(0x3, 5) ? address + 0x80 : address;
	return readBit(adr, index);
}

void RegisterData::writeBitS(uint8_t address, uint8_t offset, bool value, DataSource source) const
{
	if (!validateSimulatedAddress(address)) throwIllegalAddressException();
	uint8_t adr = readBit(0x3, 5) ? address + 0x80 : address;
	writeBit(adr, offset, value, source); // clear bit
}

void RegisterData::writeByteS(const uint8_t& address, unsigned char value, DataSource source) const
{
	if (!validateSimulatedAddress(address)) throwIllegalAddressException();
	uint8_t adr = readBit(0x3, 5) ? address + 0x80 : address;
	writeByte(adr, value, source);
}

int RegisterData::applyRequest(const Request::RequestData& req) const
{
	if (!req.initialized) throw fatal_exception("An empty Request is not supported");
	if (req.writeRequest) {
		if (req.accessBit)
			writeBit(req.address, req.bitIndex, req.value, req.source);
		else
			writeByte(req.address, req.value, req.source);
		return true;
	}
	else {
		if (req.accessBit)
			return readBit(req.address, req.bitIndex);
		return readByte(req.address);
	}
}

const uint8_t& RegisterData::readByteS(const uint8_t& address) const
{
	if (!validateSimulatedAddress(address)) throwIllegalAddressException();
	uint8_t adr = readBit(0x3, 5) ? address + 0x80 : address;
	return readByte(adr);
}


void RegisterData::resetPowerOn()
{
	initialize();
	cpuRegisters.accumulator = 0;

	applyRequest(Request(0x2).writeFullValue(0));
	applyRequest(Request(0x3).writeFullValue(0x18));
	applyRequest(Request(0x81).writeFullValue(0xFF));
	applyRequest(Request(0x85).writeFullValue(0xFF));
	applyRequest(Request(0x86).writeFullValue(0xFF));
}

void RegisterData::otherReset()
{
	applyRequest(Request(0x2).writeFullValue(0));
	applyRequest(Request(0x3).writeFullValue(0));
	applyRequest(Request(0x5).writeFullValue(0));
	applyRequest(Request(0xA).writeFullValue(0));
	applyRequest(Request(0xB).writeFullValue(0));
	applyRequest(Request(0x80).writeFullValue(0));
	applyRequest(Request(0x81).writeFullValue(0xFF));
	applyRequest(Request(0x85).writeFullValue(0xFF));
	applyRequest(Request(0x86).writeFullValue(0xFF));
}

// TODO: code smells long method
void RegisterData::initialize()
{
	stack.clear();
	ram.clear();
	for (int i = 0; i <= 0xFF; i++) {
		if (i == 0x80 || i == 0x82 || i == 0x83 || i == 0x84 || i == 0x8A || i == 0x8B || (i >= 0x8C && i <= 0xAF)) {
			ram.push_back(ram.at(i - 0x80));
		}
		else {
			ram.push_back(std::make_shared<uint8_t>(0));
		}
	}
	if (!localRamConnection.connected()) {
		localRamConnection = onRamWrite.connect([this](int destinationAddress, int offset, int value, DataSource source) {
			if (destinationAddress == 0 && *ram.at(4) != 0) destinationAddress = readByte(4);

			if ((destinationAddress == Registers::PortA || destinationAddress == Registers::PortB)
				&& readBit(destinationAddress + 0x80, offset)
				&& source == FromCpu) {
				portBuffer[destinationAddress + offset] = value;
			}
			else if ((destinationAddress == Registers::TrisA || destinationAddress == Registers::TrisB) && value == 0) {
				// if a tris bit is set to output write the buffered port value into the corresopnding port (if available)
				int portAdr = destinationAddress - 0x80;
				int portBitAdr = portAdr + offset;
				if (portBuffer.find(portBitAdr) != portBuffer.end()) {
					setBit(*ram.at(portAdr), offset, portBuffer[portBitAdr]);
					portBuffer.erase(portBitAdr);
				}
				setBit(*ram.at(destinationAddress), offset, value);
			}
			else {
				setBit(*ram.at(destinationAddress), offset, value);
				if (destinationAddress == 0x2 && offset >= 7)
				{
					// optimization: only set the pc once not 8 times
					this->cpuRegisters.programCounter = readByte(0x2) & 0xFF;
					this->cpuRegisters.programCounter |= ((readByte(0xA) & 0x1F) << 8);
				}
			}
		});
	}
}

const std::array<bool, 8> RegisterData::getRegisterBits(uint8_t address) const
{
	std::array<bool, 8> result;
	for (int i = 0; i < 8; i++)
	{
		result[i] = readBit(address, i);
	}
	return result;
}


void RegisterData::increasePCBy(uint16_t amount)
{
	cpuRegisters.programCounter = getPc() + amount;
	writeByte(0x82, cpuRegisters.programCounter & 0xFF);
}


const uint16_t& RegisterData::getPc() const
{
	return cpuRegisters.programCounter;
}

const void RegisterData::setPc(const uint16_t& value)
{
	cpuRegisters.programCounter = value;
}

void RegisterData::setBit(uint8_t& source, int offset, int value)
{
	source &= ~(1 << offset);
	source |= value << offset;
}
