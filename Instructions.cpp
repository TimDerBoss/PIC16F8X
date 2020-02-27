#include "Instructions.h"
#include <iostream>

#include "RegisterData.h"
#include "CPU.h"

ADDWF::ADDWF(const std::string& identifier, uint16_t mask, uint16_t value, RegisterData& rd)
	: InstructionBase(identifier, mask, value, rd)
{
}

void ADDWF::execute(const uint16_t& opcode)
{
	auto data = getInstructionData(opcode);
	auto& w = registerData.cpuRegisters.w;
	int result = w + registerData.readData(data.f);
	auto preResult = data.d ? registerData.readData(data.f) : w;
	if (!data.d) {
		w = static_cast<uint8_t>(result);
	} else {
		registerData.writeData(data.f, static_cast<uint8_t>(result));
	}
	registerData.setBit(0x3, 0x0, result > 255); // carry bit
	registerData.setBit(0x3, 0x1, preResult <= 0xF && static_cast<uint8_t>(result) > 0xF); // digit carry
	registerData.setBit(0x3, 0x2, static_cast<uint8_t>(result) == 0); // zero flag
	registerData.increasePCBy(1);

	printf("%s 0x%X, %d (w = %d)\n", identifier.c_str(), data.f, data.d, w);
}

ANDWF::ANDWF(const std::string& identifier, uint16_t mask, uint16_t value, RegisterData& rd)
	: InstructionBase(identifier, mask, value, rd)
{
}

void ANDWF::execute(const uint16_t& opcode)
{
	auto data = getInstructionData(opcode);
	auto& w = registerData.cpuRegisters.w;
	uint8_t result = w & registerData.readData(data.f);
	if (!data.d) {
		w = result;
	} else {
		registerData.writeData(data.f, result);
	}
	registerData.setBit(0x3, 0x2, static_cast<uint8_t>(result) == 0); // zero flag
	registerData.increasePCBy(1);
	printf("%s 0x%X, %d (w = %d)\n", identifier.c_str(), data.f, data.d, w);
}

CLRF::CLRF(const std::string& identifier, uint16_t mask, uint16_t value, RegisterData& rd)
	: InstructionBase(identifier, mask, value, rd)
{
}

void CLRF::execute(const uint16_t& opcode)
{
	auto data = getInstructionData(opcode);
	registerData.writeData(data.f, 0);
	registerData.setBit(0x3, 0x2, true); // zero flag
	registerData.increasePCBy(1);
	printf("%s 0x%X, %d\n", identifier.c_str(), data.f, data.d);
}

CLRW::CLRW(const std::string& identifier, uint16_t mask, uint16_t value, RegisterData& rd)
	: InstructionBase(identifier, mask, value, rd)
{
}

void CLRW::execute(const uint16_t& opcode)
{
	registerData.cpuRegisters.w = 0;
	registerData.setBit(0x3, 0x2, true); // zero flag
	registerData.increasePCBy(1);
	printf("%s\n", identifier.c_str());
}

COMF::COMF(const std::string& identifier, uint16_t mask, uint16_t value, RegisterData& rd)
	: InstructionBase(identifier, mask, value, rd)
{
}

void COMF::execute(const uint16_t& opcode)
{
	auto data = getInstructionData(opcode);
	auto& w = registerData.cpuRegisters.w;
	uint8_t result = ~registerData.readData(data.f);
	if (!data.d) {
		w = result;
	} else {
		registerData.writeData(data.f, result);
	}
	registerData.setBit(0x3, 0x2, result == 0); // zero flag
	registerData.increasePCBy(1);
	printf("%s 0x%X, %d (w = %d)\n", identifier.c_str(), data.f, data.d, w);
}

DECF::DECF(const std::string& identifier, uint16_t mask, uint16_t value, RegisterData& rd)
	: InstructionBase(identifier, mask, value, rd)
{
}

void DECF::execute(const uint16_t& opcode)
{
	auto data = getInstructionData(opcode);
	auto& w = registerData.cpuRegisters.w;
	uint8_t result = registerData.readData(data.f) - 1;
	if (!data.d) {
		w = result;
	} else {
		registerData.writeData(data.f, result);
	}
	registerData.setBit(0x3, 0x2, result == 0); // zero flag
	registerData.increasePCBy(1);
	printf("%s 0x%X, %d (w = %d)\n", identifier.c_str(), data.f, data.d, w);
}

DECFSZ::DECFSZ(const std::string& identifier, uint16_t mask, uint16_t value, RegisterData& rd)
	: InstructionBase(identifier, mask, value, rd)
{
}

void DECFSZ::execute(const uint16_t& opcode)
{
	auto data = getInstructionData(opcode);
	auto& w = registerData.cpuRegisters.w;
	uint8_t result = registerData.readData(data.f) - 1;
	if (!data.d) {
		w = result;
	} else {
		registerData.writeData(data.f, result);
	}
	if (result == 0) {
		registerData.increasePCBy(2);
	} else {
		registerData.increasePCBy(1);
	}
	printf("%s 0x%X, %d (w = %d)\n", identifier.c_str(), data.f, data.d, w);
}

INCF::INCF(const std::string& identifier, uint16_t mask, uint16_t value, RegisterData& rd)
	: InstructionBase(identifier, mask, value, rd)
{
}

void INCF::execute(const uint16_t& opcode)
{
	auto data = getInstructionData(opcode);
	auto& w = registerData.cpuRegisters.w;
	uint8_t result = registerData.readData(data.f) + 1;
	if (!data.d) {
		w = result;
	} else {
		registerData.writeData(data.f, result);
	}
	registerData.setBit(0x3, 0x2, result == 0); // zero flag
	registerData.increasePCBy(1);
	printf("%s 0x%X, %d (w = %d)\n", identifier.c_str(), data.f, data.d, w);
}

INCFSZ::INCFSZ(const std::string& identifier, uint16_t mask, uint16_t value, RegisterData& rd)
	: InstructionBase(identifier, mask, value, rd)
{
}

void INCFSZ::execute(const uint16_t& opcode)
{
	auto data = getInstructionData(opcode);
	auto& w = registerData.cpuRegisters.w;
	uint8_t result = registerData.readData(data.f) + 1;
	if (!data.d) {
		w = result;
	} else {
		registerData.writeData(data.f, result);
	}
	if (result == 0) {
		registerData.increasePCBy(2);
	} else {
		registerData.increasePCBy(1);
	}
	printf("%s 0x%X, %d (w = %d)\n", identifier.c_str(), data.f, data.d, w);
}

IORWF::IORWF(const std::string& identifier, uint16_t mask, uint16_t value, RegisterData& rd)
	: InstructionBase(identifier, mask, value, rd)
{
}

void IORWF::execute(const uint16_t& opcode)
{
	auto data = getInstructionData(opcode);
	auto& w = registerData.cpuRegisters.w;
	uint8_t result = registerData.readData(data.f) | w;
	if (!data.d) {
		w = result;
	} else {
		registerData.writeData(data.f, result);
	}
	registerData.setBit(0x3, 0x2, result == 0); // zero flag
	registerData.increasePCBy(1);
	printf("%s 0x%X, %d (w = %d)\n", identifier.c_str(), data.f, data.d, w);
}

MOVF::MOVF(const std::string& identifier, uint16_t mask, uint16_t value, RegisterData& rd)
	: InstructionBase(identifier, mask, value, rd)
{
}

void MOVF::execute(const uint16_t& opcode)
{
	auto data = getInstructionData(opcode);
	auto& w = registerData.cpuRegisters.w;
	if (!data.d) {
		w = registerData.readData(data.f);
	}
	registerData.setBit(0x3, 0x2, registerData.readData(data.f) == 0); // zero flag
	registerData.increasePCBy(1);
	printf("%s 0x%X, %d (w = %d)\n", identifier.c_str(), data.f, data.d, w);
}

MOVWF::MOVWF(const std::string& identifier, uint16_t mask, uint16_t value, RegisterData& rd)
	: InstructionBase(identifier, mask, value, rd)
{
}

void MOVWF::execute(const uint16_t& opcode)
{
	auto data = getInstructionData(opcode);
	auto& w = registerData.cpuRegisters.w;
	registerData.writeData(data.f, w);
	registerData.increasePCBy(1);
	printf("%s 0x%X, %d (w = %d)\n", identifier.c_str(), data.f, data.d, w);
}

NOP::NOP(const std::string& identifier, uint16_t mask, uint16_t value, RegisterData& rd)
	: InstructionBase(identifier, mask, value, rd)
{
}

void NOP::execute(const uint16_t& opcode)
{
	printf("%s\n", identifier.c_str());
}

RLF::RLF(const std::string& identifier, uint16_t mask, uint16_t value, RegisterData& rd)
	: InstructionBase(identifier, mask, value, rd)
{
}

void RLF::execute(const uint16_t& opcode)
{
	auto data = getInstructionData(opcode);
	bool tempCarry = registerData.getBit(0x3, 0x0);
	uint8_t fBefore = registerData.readData(data.f);
	auto& w = registerData.cpuRegisters.w;

	registerData.setBit(0x3, 0x0, (fBefore >> 7) & 1);
	fBefore <<= 1;
	fBefore |= tempCarry;

	if (!data.d) {
		w = fBefore;
	} else {
		registerData.writeData(data.f, fBefore);
	}
	registerData.increasePCBy(1);
	printf("%s 0x%X, %d (w = %d)\n", identifier.c_str(), data.f, data.d, w);
}

RRF::RRF(const std::string& identifier, uint16_t mask, uint16_t value, RegisterData& rd)
	: InstructionBase(identifier, mask, value, rd)
{
}

void RRF::execute(const uint16_t& opcode)
{
	auto data = getInstructionData(opcode);
	uint8_t fBefore = registerData.readData(data.f);
	auto& w = registerData.cpuRegisters.w;

	bool tmpOverflow = fBefore & 1;
	fBefore >>= 1;
	fBefore |= (registerData.getBit(0x3, 0) << 7);
	registerData.setBit(0x3, 0, tmpOverflow);

	if (!data.d) {
		w = fBefore;
	} else {
		registerData.writeData(data.f, fBefore);
	}
	registerData.increasePCBy(1);
	printf("%s 0x%X, %d (w = %d)\n", identifier.c_str(), data.f, data.d, w);
}
SUBWF
::SUBWF(const std::string& identifier, uint16_t mask, uint16_t value, RegisterData& rd)
	: InstructionBase(identifier, mask, value, rd)
{
}

void SUBWF::execute(const uint16_t& opcode)
{
	throw std::runtime_error("Not implemented");
}


SWAPF::SWAPF(const std::string& identifier, uint16_t mask, uint16_t value, RegisterData& rd)
	: InstructionBase(identifier, mask, value, rd)
{
}

void SWAPF::execute(const uint16_t& opcode)
{
	auto data = getInstructionData(opcode);
	auto& w = registerData.cpuRegisters.w;
	uint8_t result = registerData.readData(data.f);

	uint8_t temp = result & 0xF;
	result >>= 4;
	result |= (temp << 4);

	if (!data.d) {
		w = result;
	} else {
		registerData.writeData(data.f, result);
	}
	registerData.increasePCBy(1);
	printf("%s 0x%X, %d (w = %d)\n", identifier.c_str(), data.f, data.d, w);
}

XORWF::XORWF(const std::string& identifier, uint16_t mask, uint16_t value, RegisterData& rd)
	: InstructionBase(identifier, mask, value, rd)
{
}

void XORWF::execute(const uint16_t& opcode)
{
	auto data = getInstructionData(opcode);
	auto& w = registerData.cpuRegisters.w;
	uint8_t result = registerData.readData(data.f) ^w;
	if (!data.d) {
		w = result;
	} else {
		registerData.writeData(data.f, result);
	}
	registerData.setBit(0x3, 0x2, result == 0); // zero flag
	registerData.increasePCBy(1);
	printf("%s 0x%X, %d (w = %d)\n", identifier.c_str(), data.f, data.d, w);
}

BCF::BCF(const std::string& identifier, uint16_t mask, uint16_t value, RegisterData& rd)
	: InstructionBase(identifier, mask, value, rd)
{
}

void BCF::execute(const uint16_t& opcode)
{
	auto data = getInstructionData(opcode);
	registerData.setBit(data.f, data.b, false);
	registerData.increasePCBy(1);
	printf("%s 0x%X, %d\n", identifier.c_str(), data.f, data.b);
}

BSF::BSF(const std::string& identifier, uint16_t mask, uint16_t value, RegisterData& rd)
	: InstructionBase(identifier, mask, value, rd)
{
}

void BSF::execute(const uint16_t& opcode)
{
	auto data = getInstructionData(opcode);
	registerData.setBit(data.f, data.b, true);
	registerData.increasePCBy(1);
	printf("%s 0x%X, %d\n", identifier.c_str(), data.f, data.b);
}

BTFSC::BTFSC(const std::string& identifier, uint16_t mask, uint16_t value, RegisterData& rd)
	: InstructionBase(identifier, mask, value, rd)
{
}

void BTFSC::execute(const uint16_t& opcode)
{
	auto data = getInstructionData(opcode);
	uint8_t bit = registerData.getBit(data.f, data.b);
	if (bit) {
		registerData.increasePCBy(1);
	} else {
		registerData.increasePCBy(2);
	}
	printf("%s 0x%X, %d\n", identifier.c_str(), data.f, data.b);
}

BTFSS::BTFSS(const std::string& identifier, uint16_t mask, uint16_t value, RegisterData& rd)
	: InstructionBase(identifier, mask, value, rd)
{
}

void BTFSS::execute(const uint16_t& opcode)
{
	auto data = getInstructionData(opcode);
	uint8_t bit = registerData.getBit(data.f, data.b);
	if (!bit) {
		registerData.increasePCBy(1);
	} else {
		registerData.increasePCBy(2);
	}
	printf("%s 0x%X, %d\n", identifier.c_str(), data.f, data.b);
}

ADDLW::ADDLW(const std::string& identifier, uint16_t mask, uint16_t value, RegisterData& rd)
	: InstructionBase(identifier, mask, value, rd)
{
}

void ADDLW::execute(const uint16_t& opcode)
{
	auto data = getInstructionData(opcode);
	auto& w = registerData.cpuRegisters.w;
	int result = w + data.k;
	auto preResult = w;
	w = static_cast<uint8_t>(result);

	registerData.setBit(0x3, 0x0, result > 255); // carry bit
	registerData.setBit(0x3, 0x1, preResult <= 0xF && static_cast<uint8_t>(result) > 0xF); // digit carry
	registerData.setBit(0x3, 0x2, static_cast<uint8_t>(result) == 0); // zero flag
	registerData.increasePCBy(1);

	printf("%s 0x%X\n", identifier.c_str(), data.k);
}

ANDLW::ANDLW(const std::string& identifier, uint16_t mask, uint16_t value, RegisterData& rd)
	: InstructionBase(identifier, mask, value, rd)
{
}

void ANDLW::execute(const uint16_t& opcode)
{
	auto data = getInstructionData(opcode);
	auto& w = registerData.cpuRegisters.w;
	uint8_t result = w & data.k;
	w = result;
	registerData.setBit(0x3, 0x2, result == 0); // zero flag
	registerData.increasePCBy(1);
	printf("%s 0x%X\n", identifier.c_str(), data.k);
}