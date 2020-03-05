#include "Instructions.h"
#include "RegisterData.h"
#include "CPU.h"

#include <iostream>
#include <FormatString.h>

ADDWF::ADDWF(const std::string& identifier, uint16_t mask, uint16_t value, RegisterData& rd)
	: InstructionBase(identifier, mask, value, rd)
{
}

void ADDWF::execute(const uint16_t& opcode)
{
	auto data = getInstructionData(opcode);
	auto& w = registerData.cpuRegisters.w;
	int result = static_cast<int>(w + registerData.readData(data.f));
	uint8_t preResult = data.d ? registerData.readData(data.f) : w;
	if (!data.d) {
		w = static_cast<uint8_t>(result);
	} else {
		registerData.writeData(data.f, static_cast<uint8_t>(result));
	}
	registerData.setBit(0x3, 0x0, result > 255); // carry bit
	registerData.setBit(0x3, 0x1, preResult <= 0xF && static_cast<uint8_t>(result) > 0xF); // digit carry
	registerData.setBit(0x3, 0x2, static_cast<uint8_t>(result) == 0); // zero flag

	printf("%s 0x%X, %d (w = %d)\n", identifier.c_str(), data.f, data.d, w);
	registerData.increasePCBy(getCycles());
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
	printf("%s 0x%X, %d (w = %d)\n", identifier.c_str(), data.f, data.d, w);
	registerData.increasePCBy(getCycles());
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
	printf("%s 0x%X, %d\n", identifier.c_str(), data.f, data.d);
	registerData.increasePCBy(getCycles());
}

CLRW::CLRW(const std::string& identifier, uint16_t mask, uint16_t value, RegisterData& rd)
	: InstructionBase(identifier, mask, value, rd)
{
}

void CLRW::execute(const uint16_t& opcode)
{
	registerData.cpuRegisters.w = 0;
	registerData.setBit(0x3, 0x2, true); // zero flag
	printf("%s\n", identifier.c_str());
	registerData.increasePCBy(getCycles());
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
	printf("%s 0x%X, %d (w = %d)\n", identifier.c_str(), data.f, data.d, w);
	registerData.increasePCBy(getCycles());
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
	printf("%s 0x%X, %d (w = %d)\n", identifier.c_str(), data.f, data.d, w);
	registerData.increasePCBy(getCycles());
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
		setCycles(2);
	} else {
		setCycles(1);
	}
	printf("%s 0x%X, %d (w = %d)\n", identifier.c_str(), data.f, data.d, w);
	registerData.increasePCBy(getCycles());
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
	printf("%s 0x%X, %d (w = %d)\n", identifier.c_str(), data.f, data.d, w);
	registerData.increasePCBy(getCycles());
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
		setCycles(2);
	} else {
		setCycles(1);
	}
	printf("%s 0x%X, %d (w = %d)\n", identifier.c_str(), data.f, data.d, w);
	registerData.increasePCBy(getCycles());
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
	printf("%s 0x%X, %d (w = %d)\n", identifier.c_str(), data.f, data.d, w);
	registerData.increasePCBy(getCycles());
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
	printf("%s 0x%X, %d (w = %d)\n", identifier.c_str(), data.f, data.d, w);
	registerData.increasePCBy(getCycles());
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
	printf("%s 0x%X, %d (w = %d)\n", identifier.c_str(), data.f, data.d, w);
	registerData.increasePCBy(getCycles());
}

NOP::NOP(const std::string& identifier, uint16_t mask, uint16_t value, RegisterData& rd)
	: InstructionBase(identifier, mask, value, rd)
{
}

void NOP::execute(const uint16_t& opcode)
{
	printf("%s\n", identifier.c_str());
	registerData.increasePCBy(getCycles());
}

RLF::RLF(const std::string& identifier, uint16_t mask, uint16_t value, RegisterData& rd)
	: InstructionBase(identifier, mask, value, rd)
{
}

void RLF::execute(const uint16_t& opcode)
{
	auto data = getInstructionData(opcode);
	uint8_t tempCarry = registerData.getBit(0x3, 0x0);
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
	printf("%s 0x%X, %d (w = %d)\n", identifier.c_str(), data.f, data.d, w);
	registerData.increasePCBy(getCycles());
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
	printf("%s 0x%X, %d (w = %d)\n", identifier.c_str(), data.f, data.d, w);
	registerData.increasePCBy(getCycles());
}

SUBWF::SUBWF(const std::string& identifier, uint16_t mask, uint16_t value, RegisterData& rd)
	: InstructionBase(identifier, mask, value, rd)
{
}

void SUBWF::execute(const uint16_t& opcode)
{
	auto data = getInstructionData(opcode);
	auto& w = registerData.cpuRegisters.w;
	int result = registerData.readData(data.f) - w;
	if (!data.d) {
		w = static_cast<uint8_t>(result);
	} else {
		registerData.writeData(data.f, static_cast<uint8_t>(result));
	}
	registerData.setBit(0x3, 0x0, result >= 0); // carry bit
	// TODO: fix DC
	registerData.setBit(0x3, 0x1, false); // digit carry
	registerData.setBit(0x3, 0x2, static_cast<uint8_t>(result) == 0); // zero flag
	printf("%s 0x%X, %d (w = %d)\n", identifier.c_str(), data.f, data.d, w);
	registerData.increasePCBy(getCycles());
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
	printf("%s 0x%X, %d (w = %d)\n", identifier.c_str(), data.f, data.d, w);
	registerData.increasePCBy(getCycles());
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
	printf("%s 0x%X, %d (w = %d)\n", identifier.c_str(), data.f, data.d, w);
	registerData.increasePCBy(getCycles());
}

BCF::BCF(const std::string& identifier, uint16_t mask, uint16_t value, RegisterData& rd)
	: InstructionBase(identifier, mask, value, rd)
{
}

void BCF::execute(const uint16_t& opcode)
{
	auto data = getInstructionData(opcode);
	registerData.setBit(data.f, data.b, false);
	printf("%s 0x%X, %d\n", identifier.c_str(), data.f, data.b);
	registerData.increasePCBy(getCycles());
}

BSF::BSF(const std::string& identifier, uint16_t mask, uint16_t value, RegisterData& rd)
	: InstructionBase(identifier, mask, value, rd)
{
}

void BSF::execute(const uint16_t& opcode)
{
	auto data = getInstructionData(opcode);
	registerData.setBit(data.f, data.b, true);
	printf("%s 0x%X, %d\n", identifier.c_str(), data.f, data.b);
	registerData.increasePCBy(getCycles());
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
		setCycles(1);
	} else {
		setCycles(2);
	}
	printf("%s 0x%X, %d\n", identifier.c_str(), data.f, data.b);
	registerData.increasePCBy(getCycles());
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
		setCycles(1);
	} else {
		setCycles(2);
	}
	printf("%s 0x%X, %d\n", identifier.c_str(), data.f, data.b);
	registerData.increasePCBy(getCycles());
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
	printf("%s 0x%X\n", identifier.c_str(), data.k);
	registerData.increasePCBy(getCycles());
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
	printf("%s 0x%X\n", identifier.c_str(), data.k);
	registerData.increasePCBy(getCycles());
}

CALL::CALL(const std::string& identifier, uint16_t mask, uint16_t value, RegisterData& rd)
	: InstructionBase(identifier, mask, value, rd, 2)
{
}

void CALL::execute(const uint16_t& opcode)
{
	auto data = getInstructionData(opcode);
	registerData.stack.emplace(registerData.getPC() + 1);
	registerData.setPC(data.k);
	printf("%s 0x%X\n", identifier.c_str(), data.k);
}

CLRWDT::CLRWDT(const std::string& identifier, uint16_t mask, uint16_t value, RegisterData& rd)
	: InstructionBase(identifier, mask, value, rd)
{
}

void CLRWDT::execute(const uint16_t& opcode)
{
	throw std::runtime_error(fmt::format("Not implemented: %s", identifier));
	registerData.increasePCBy(getCycles());
}

GOTO::GOTO(const std::string& identifier, uint16_t mask, uint16_t value, RegisterData& rd)
	: InstructionBase(identifier, mask, value, rd, 2)
{
}

void GOTO::execute(const uint16_t& opcode)
{
	auto data = getInstructionData(opcode);
	registerData.setPC(data.k);
	printf("%s 0x%X\n", identifier.c_str(), data.k);
}

IORLW::IORLW(const std::string& identifier, uint16_t mask, uint16_t value, RegisterData& rd)
	: InstructionBase(identifier, mask, value, rd)
{
}

void IORLW::execute(const uint16_t& opcode)
{
	auto data = getInstructionData(opcode);
	auto& w = registerData.cpuRegisters.w;
	uint8_t result = w | data.k;
	w = result;
	registerData.setBit(0x3, 0x2, result == 0); // zero flag
	printf("%s 0x%X\n", identifier.c_str(), data.k);
	registerData.increasePCBy(getCycles());
}

MOVLW::MOVLW(const std::string& identifier, uint16_t mask, uint16_t value, RegisterData& rd)
	: InstructionBase(identifier, mask, value, rd)
{
}

void MOVLW::execute(const uint16_t& opcode)
{
	auto data = getInstructionData(opcode);
	registerData.cpuRegisters.w = static_cast<uint8_t>(data.k);
	printf("%s 0x%X\n", identifier.c_str(), data.k);
	registerData.increasePCBy(getCycles());
}

RETFIE::RETFIE(const std::string& identifier, uint16_t mask, uint16_t value, RegisterData& rd)
	: InstructionBase(identifier, mask, value, rd, 2)
{
}

void RETFIE::execute(const uint16_t& opcode)
{
	if(registerData.stack.empty())
		throw std::runtime_error(fmt::format("%s: Stack is empty!", __FUNCTION__));
	registerData.setPC(registerData.stack.top());
	registerData.stack.pop();
	registerData.setBit(0xB, 7, true); // GIE
	printf("%s 0x%X\n", identifier.c_str());
}

RETLW::RETLW(const std::string& identifier, uint16_t mask, uint16_t value, RegisterData& rd)
	: InstructionBase(identifier, mask, value, rd, 2)
{
}

void RETLW::execute(const uint16_t& opcode)
{
	if(registerData.getRawBit(0xB, 1))
		throw std::runtime_error(fmt::format("%s: Use RETFIE to return from an interrupt!", __FUNCTION__));
	auto data = getInstructionData(opcode);
	if(registerData.stack.empty())
		throw std::runtime_error(fmt::format("%s: Stack is empty!", __FUNCTION__));
	registerData.setPC(registerData.stack.top());
	registerData.stack.pop();
	registerData.cpuRegisters.w = static_cast<uint8_t>(data.k);
	printf("%s 0x%X\n", identifier.c_str(), data.k);
}

RETURN::RETURN(const std::string& identifier, uint16_t mask, uint16_t value, RegisterData& rd)
	: InstructionBase(identifier, mask, value, rd, 2)
{
}

void RETURN::execute(const uint16_t& opcode)
{
	if (registerData.getRawBit(0xB, 1))
		throw std::runtime_error(fmt::format("%s: Use RETFIE to return from an interrupt!", __FUNCTION__));
	auto data = getInstructionData(opcode);
	if(registerData.stack.empty())
		throw std::runtime_error(fmt::format("%s: Stack is empty!", __FUNCTION__));
	registerData.setPC(registerData.stack.top());
	registerData.stack.pop();
	printf("%s 0x%X\n", identifier.c_str(), data.k);
}

SLEEP::SLEEP(const std::string& identifier, uint16_t mask, uint16_t value, RegisterData& rd)
	: InstructionBase(identifier, mask, value, rd)
{
}

void SLEEP::execute(const uint16_t& opcode)
{
	throw std::runtime_error(fmt::format("Not implemented: %s", identifier));
	registerData.increasePCBy(getCycles());
}

SUBLW::SUBLW(const std::string& identifier, uint16_t mask, uint16_t value, RegisterData& rd)
	: InstructionBase(identifier, mask, value, rd)
{
}

void SUBLW::execute(const uint16_t& opcode)
{
	auto data = getInstructionData(opcode);
	auto& w = registerData.cpuRegisters.w;
	int result = static_cast<int>(registerData.readData((uint8_t)data.k) - w);
	w = static_cast<uint8_t>(result);
	registerData.setBit(0x3, 0x0, result >= 0); // carry bit
	// TODO: fix DC
	registerData.setBit(0x3, 0x1, false); // digit carry
	registerData.setBit(0x3, 0x2, static_cast<uint8_t>(result) == 0); // zero flag
	printf("%s 0x%X, %d (w = %d)\n", identifier.c_str(), data.f, data.d, w);
	registerData.increasePCBy(getCycles());
}

XORLW::XORLW(const std::string& identifier, uint16_t mask, uint16_t value, RegisterData& rd)
	: InstructionBase(identifier, mask, value, rd)
{
}

void XORLW::execute(const uint16_t& opcode)
{
	auto data = getInstructionData(opcode);
	auto& w = registerData.cpuRegisters.w;
	uint8_t result = w ^ data.k;
	w = result;
	registerData.setBit(0x3, 0x2, result == 0); // zero flag
	registerData.increasePCBy(1);
	printf("%s 0x%X\n", identifier.c_str(), data.k);
	registerData.increasePCBy(getCycles());
}
