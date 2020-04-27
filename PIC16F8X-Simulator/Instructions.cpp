#include "Instructions.h"
#include "RegisterData.h"
#include "CPU.h"
#include "Exception.h"

#include <iostream>
#include <FormatString.h>

ADDWF::ADDWF(const std::string& identifier, uint16_t mask, uint16_t value)
	: InstructionBase(identifier, mask, value)
{
}

void ADDWF::execute(RegisterData& rd)
{
	auto& w = rd.cpuRegisters.w;
	int fnum = rd.readByteS(data.f);
	int result = static_cast<int>(w + fnum);
	bool digitCarry = ((w & 0xF) + (fnum & 0xF)) & 0xF0;
	if (!data.d) {
		w = static_cast<uint8_t>(result);
	}
	else {
		rd.writeByteS(data.f, static_cast<uint8_t>(result));
	}
	rd.writeBitS(0x3, 0x0, result > 255 || result < 0); // carry bit
	rd.writeBitS(0x3, 0x1, digitCarry); // digit carry
	rd.writeBitS(0x3, 0x2, static_cast<uint8_t>(result) == 0); // zero flag
	printf("%s 0x%X, %d (w = %d)\n", identifier.c_str(), data.f, data.d, w);
	rd.increasePCBy(getCycles());
}

ANDWF::ANDWF(const std::string& identifier, uint16_t mask, uint16_t value)
	: InstructionBase(identifier, mask, value)
{
}

void ANDWF::execute(RegisterData& rd)
{
	auto& w = rd.cpuRegisters.w;
	uint8_t result = w & rd.readByteS(data.f);
	if (!data.d) {
		w = result;
	}
	else {
		rd.writeByteS(data.f, result);
	}
	rd.writeBitS(0x3, 0x2, static_cast<uint8_t>(result) == 0); // zero flag
	printf("%s 0x%X, %d (w = %d)\n", identifier.c_str(), data.f, data.d, w);
	rd.increasePCBy(getCycles());
}

CLRF::CLRF(const std::string& identifier, uint16_t mask, uint16_t value)
	: InstructionBase(identifier, mask, value)
{
}

void CLRF::execute(RegisterData& rd)
{

	rd.writeByteS(data.f, 0);
	rd.writeBitS(0x3, 0x2, true); // zero flag
	printf("%s 0x%X, %d\n", identifier.c_str(), data.f, data.d);
	rd.increasePCBy(getCycles());
}

CLRW::CLRW(const std::string& identifier, uint16_t mask, uint16_t value)
	: InstructionBase(identifier, mask, value)
{
}

void CLRW::execute(RegisterData& rd)
{
	rd.cpuRegisters.w = 0;
	rd.writeBitS(0x3, 0x2, true); // zero flag
	printf("%s\n", identifier.c_str());
	rd.increasePCBy(getCycles());
}

COMF::COMF(const std::string& identifier, uint16_t mask, uint16_t value)
	: InstructionBase(identifier, mask, value)
{
}

void COMF::execute(RegisterData& rd)
{

	auto& w = rd.cpuRegisters.w;
	uint8_t result = ~rd.readByteS(data.f);
	if (!data.d) {
		w = result;
	}
	else {
		rd.writeByteS(data.f, result);
	}
	rd.writeBitS(0x3, 0x2, result == 0); // zero flag
	printf("%s 0x%X, %d (w = %d)\n", identifier.c_str(), data.f, data.d, w);
	rd.increasePCBy(getCycles());
}

DECF::DECF(const std::string& identifier, uint16_t mask, uint16_t value)
	: InstructionBase(identifier, mask, value)
{
}

void DECF::execute(RegisterData& rd)
{

	auto& w = rd.cpuRegisters.w;
	uint8_t result = rd.readByteS(data.f) - 1;
	if (!data.d) {
		w = result;
	}
	else {
		rd.writeByteS(data.f, result);
	}
	rd.writeBitS(0x3, 0x2, result == 0); // zero flag
	printf("%s 0x%X, %d (w = %d)\n", identifier.c_str(), data.f, data.d, w);
	rd.increasePCBy(getCycles());
}

DECFSZ::DECFSZ(const std::string& identifier, uint16_t mask, uint16_t value)
	: InstructionBase(identifier, mask, value)
{
}

void DECFSZ::execute(RegisterData& rd)
{

	auto& w = rd.cpuRegisters.w;
	uint8_t result = rd.readByteS(data.f) - 1;
	if (!data.d) {
		w = result;
	}
	else {
		rd.writeByteS(data.f, result);
	}
	if (result == 0) {
		setCycles(2);
	}
	else {
		setCycles(1);
	}
	printf("%s 0x%X, %d (w = %d)\n", identifier.c_str(), data.f, data.d, w);
	rd.increasePCBy(getCycles());
}

INCF::INCF(const std::string& identifier, uint16_t mask, uint16_t value)
	: InstructionBase(identifier, mask, value)
{
}

void INCF::execute(RegisterData& rd)
{

	auto& w = rd.cpuRegisters.w;
	uint8_t result = rd.readByteS(data.f) + 1;
	if (!data.d) {
		w = result;
	}
	else {
		rd.writeByteS(data.f, result);
	}
	rd.writeBitS(0x3, 0x2, result == 0); // zero flag
	printf("%s 0x%X, %d (w = %d)\n", identifier.c_str(), data.f, data.d, w);
	rd.increasePCBy(getCycles());
}

INCFSZ::INCFSZ(const std::string& identifier, uint16_t mask, uint16_t value)
	: InstructionBase(identifier, mask, value)
{
}

void INCFSZ::execute(RegisterData& rd)
{

	auto& w = rd.cpuRegisters.w;
	uint8_t result = rd.readByteS(data.f) + 1;
	if (!data.d) {
		w = result;
	}
	else {
		rd.writeByteS(data.f, result);
	}
	if (result == 0) {
		setCycles(2);
	}
	else {
		setCycles(1);
	}
	printf("%s 0x%X, %d (w = %d)\n", identifier.c_str(), data.f, data.d, w);
	rd.increasePCBy(getCycles());
}

IORWF::IORWF(const std::string& identifier, uint16_t mask, uint16_t value)
	: InstructionBase(identifier, mask, value)
{
}

void IORWF::execute(RegisterData& rd)
{

	auto& w = rd.cpuRegisters.w;
	uint8_t result = rd.readByteS(data.f) | w;
	if (!data.d) {
		w = result;
	}
	else {
		rd.writeByteS(data.f, result);
	}
	rd.writeBitS(0x3, 0x2, result == 0); // zero flag
	printf("%s 0x%X, %d (w = %d)\n", identifier.c_str(), data.f, data.d, w);
	rd.increasePCBy(getCycles());
}

MOVF::MOVF(const std::string& identifier, uint16_t mask, uint16_t value)
	: InstructionBase(identifier, mask, value)
{
}

void MOVF::execute(RegisterData& rd)
{

	auto& w = rd.cpuRegisters.w;
	if (!data.d) {
		w = rd.readByteS(data.f);
	}
	rd.writeBitS(0x3, 0x2, rd.readByteS(data.f) == 0); // zero flag
	printf("%s 0x%X, %d (w = %d)\n", identifier.c_str(), data.f, data.d, w);
	rd.increasePCBy(getCycles());
}

MOVWF::MOVWF(const std::string& identifier, uint16_t mask, uint16_t value)
	: InstructionBase(identifier, mask, value)
{
}

void MOVWF::execute(RegisterData& rd)
{

	auto& w = rd.cpuRegisters.w;
	rd.writeByteS(data.f, w);
	printf("%s 0x%X, %d (w = %d)\n", identifier.c_str(), data.f, data.d, w);
	rd.increasePCBy(getCycles());
}

NOP::NOP(const std::string& identifier, uint16_t mask, uint16_t value)
	: InstructionBase(identifier, mask, value)
{
}

void NOP::execute(RegisterData& rd)
{
	printf("%s\n", identifier.c_str());
	rd.increasePCBy(getCycles());
}

RLF::RLF(const std::string& identifier, uint16_t mask, uint16_t value)
	: InstructionBase(identifier, mask, value)
{
}

void RLF::execute(RegisterData& rd)
{

	uint8_t tempCarry = rd.readBitS(0x3, 0x0);
	uint8_t fBefore = rd.readByteS(data.f);
	auto& w = rd.cpuRegisters.w;

	rd.writeBitS(0x3, 0x0, (fBefore >> 7) & 1);
	fBefore <<= 1;
	fBefore |= tempCarry;

	if (!data.d) {
		w = fBefore;
	}
	else {
		rd.writeByteS(data.f, fBefore);
	}
	printf("%s 0x%X, %d (w = %d)\n", identifier.c_str(), data.f, data.d, w);
	rd.increasePCBy(getCycles());
}

RRF::RRF(const std::string& identifier, uint16_t mask, uint16_t value)
	: InstructionBase(identifier, mask, value)
{
}

void RRF::execute(RegisterData& rd)
{

	uint8_t fBefore = rd.readByteS(data.f);
	auto& w = rd.cpuRegisters.w;

	bool tmpOverflow = fBefore & 1;
	fBefore >>= 1;
	fBefore |= (rd.readBitS(0x3, 0) << 7);
	rd.writeBitS(0x3, 0, tmpOverflow);

	if (!data.d) {
		w = fBefore;
	}
	else {
		rd.writeByteS(data.f, fBefore);
	}
	printf("%s 0x%X, %d (w = %d)\n", identifier.c_str(), data.f, data.d, w);
	rd.increasePCBy(getCycles());
}

SUBWF::SUBWF(const std::string& identifier, uint16_t mask, uint16_t value)
	: InstructionBase(identifier, mask, value)
{
}

void SUBWF::execute(RegisterData& rd)
{

	auto& w = rd.cpuRegisters.w;
	auto& fnum = rd.readByteS(data.f);
	int result = fnum - w;
	if (!data.d) {
		w = static_cast<uint8_t>(result);
	}
	else {
		rd.writeByteS(data.f, static_cast<uint8_t>(result));
	}
	rd.writeBitS(0x3, 0x0, result >= 0); // carry bit
	bool digitCarry = ((fnum & 0xF) + ((~w + 1) & 0xF)) & 0xF0;
	rd.writeBitS(0x3, 0x1, !digitCarry); // digit carry
	rd.writeBitS(0x3, 0x2, static_cast<uint8_t>(result) == 0); // zero flag
	printf("%s 0x%X, %d (w = %d)\n", identifier.c_str(), data.f, data.d, w);
	rd.increasePCBy(getCycles());
}


SWAPF::SWAPF(const std::string& identifier, uint16_t mask, uint16_t value)
	: InstructionBase(identifier, mask, value)
{
}

void SWAPF::execute(RegisterData& rd)
{

	auto& w = rd.cpuRegisters.w;
	uint8_t result = rd.readByteS(data.f);

	uint8_t temp = result & 0xF;
	result >>= 4;
	result |= (temp << 4);

	if (!data.d) {
		w = result;
	}
	else {
		rd.writeByteS(data.f, result);
	}
	printf("%s 0x%X, %d (w = %d)\n", identifier.c_str(), data.f, data.d, w);
	rd.increasePCBy(getCycles());
}

XORWF::XORWF(const std::string& identifier, uint16_t mask, uint16_t value)
	: InstructionBase(identifier, mask, value)
{
}

void XORWF::execute(RegisterData& rd)
{

	auto& w = rd.cpuRegisters.w;
	uint8_t result = rd.readByteS(data.f) ^ w;
	if (!data.d) {
		w = result;
	}
	else {
		rd.writeByteS(data.f, result);
	}
	rd.writeBitS(0x3, 0x2, result == 0); // zero flag
	printf("%s 0x%X, %d (w = %d)\n", identifier.c_str(), data.f, data.d, w);
	rd.increasePCBy(getCycles());
}

BCF::BCF(const std::string& identifier, uint16_t mask, uint16_t value)
	: InstructionBase(identifier, mask, value)
{
}

void BCF::execute(RegisterData& rd)
{

	rd.writeBitS(data.f, data.b, false);
	printf("%s 0x%X, %d\n", identifier.c_str(), data.f, data.b);
	rd.increasePCBy(getCycles());
}

BSF::BSF(const std::string& identifier, uint16_t mask, uint16_t value)
	: InstructionBase(identifier, mask, value)
{
}

void BSF::execute(RegisterData& rd)
{
	rd.writeBitS(data.f, data.b, true);
	printf("%s 0x%X, %d\n", identifier.c_str(), data.f, data.b);
	rd.increasePCBy(getCycles());
}

BTFSC::BTFSC(const std::string& identifier, uint16_t mask, uint16_t value)
	: InstructionBase(identifier, mask, value)
{
}

void BTFSC::execute(RegisterData& rd)
{
	uint8_t bit = rd.readBitS(data.f, data.b);
	if (bit) {
		setCycles(1);
	}
	else {
		setCycles(2);
	}
	printf("%s 0x%X, %d\n", identifier.c_str(), data.f, data.b);
	rd.increasePCBy(getCycles());
}

BTFSS::BTFSS(const std::string& identifier, uint16_t mask, uint16_t value)
	: InstructionBase(identifier, mask, value)
{
}

void BTFSS::execute(RegisterData& rd)
{
	uint8_t bit = rd.readBitS(data.f, data.b);
	if (!bit) {
		setCycles(1);
	}
	else {
		setCycles(2);
	}
	printf("%s 0x%X, %d\n", identifier.c_str(), data.f, data.b);
	rd.increasePCBy(getCycles());
}

ADDLW::ADDLW(const std::string& identifier, uint16_t mask, uint16_t value)
	: InstructionBase(identifier, mask, value)
{
}

void ADDLW::execute(RegisterData& rd)
{
	auto& w = rd.cpuRegisters.w;
	int result = w + data.k;
	auto preResult = w;
	w = static_cast<uint8_t>(result);
	bool digitCarry = ((w & 0xF) + (data.k & 0xF)) & 0xF0;
	rd.writeBitS(0x3, 0x0, result > 255); // carry bit
	rd.writeBitS(0x3, 0x1, digitCarry); // digit carry
	rd.writeBitS(0x3, 0x2, static_cast<uint8_t>(result) == 0); // zero flag
	printf("%s 0x%X\n", identifier.c_str(), data.k);
	rd.increasePCBy(getCycles());
}

ANDLW::ANDLW(const std::string& identifier, uint16_t mask, uint16_t value)
	: InstructionBase(identifier, mask, value)
{
}

void ANDLW::execute(RegisterData& rd)
{
	auto& w = rd.cpuRegisters.w;
	uint8_t result = w & data.k;
	w = result;
	rd.writeBitS(0x3, 0x2, result == 0); // zero flag
	printf("%s 0x%X\n", identifier.c_str(), data.k);
	rd.increasePCBy(getCycles());
}

CALL::CALL(const std::string& identifier, uint16_t mask, uint16_t value)
	: InstructionBase(identifier, mask, value, 2)
{
}

void CALL::execute(RegisterData& rd)
{
	rd.stack.emplace(rd.getPcl() + 1);
	int pclath = 0;
	pclath |= ((data.k >> 8) & 0b111);
	pclath |= ((rd.readByte(0xA) & 0x11000) << 3);
	rd.writeByte(0xA, pclath);
	rd.writeByte(0x2, data.k & 0xFF);
	printf("%s 0x%X\n", identifier.c_str(), data.k);
}

CLRWDT::CLRWDT(const std::string& identifier, uint16_t mask, uint16_t value)
	: InstructionBase(identifier, mask, value)
{
}

void CLRWDT::execute(RegisterData& rd)
{
	throw exception("Not implemented: %s", identifier);
	rd.increasePCBy(getCycles());
}

GOTO::GOTO(const std::string& identifier, uint16_t mask, uint16_t value)
	: InstructionBase(identifier, mask, value, 2)
{
}

void GOTO::execute(RegisterData& rd)
{
	int pclath = 0;
	pclath |= ((data.k >> 8) & 0b111);
	pclath |= ((rd.readByte(0xA) & 0x11000));
	rd.writeByte(0xA, pclath);
	rd.writeByte(0x2, data.k & 0xFF);
	printf("%s 0x%X\n", identifier.c_str(), data.k);
}

IORLW::IORLW(const std::string& identifier, uint16_t mask, uint16_t value)
	: InstructionBase(identifier, mask, value)
{
}

void IORLW::execute(RegisterData& rd)
{
	auto& w = rd.cpuRegisters.w;
	uint8_t result = w | data.k;
	w = result;
	rd.writeBitS(0x3, 0x2, result == 0); // zero flag
	printf("%s 0x%X\n", identifier.c_str(), data.k);
	rd.increasePCBy(getCycles());
}

MOVLW::MOVLW(const std::string& identifier, uint16_t mask, uint16_t value)
	: InstructionBase(identifier, mask, value)
{
}

void MOVLW::execute(RegisterData& rd)
{
	rd.cpuRegisters.w = static_cast<uint8_t>(data.k);
	printf("%s 0x%X\n", identifier.c_str(), data.k);
	rd.increasePCBy(getCycles());
}

RETFIE::RETFIE(const std::string& identifier, uint16_t mask, uint16_t value)
	: InstructionBase(identifier, mask, value, 2)
{
}

void RETFIE::execute(RegisterData& rd)
{
	if (rd.stack.empty())
		throw exception("Stack is empty!");
	rd.writeByte(0xA, (rd.stack.top() << 8) & 0x1F);
	rd.writeByte(0x2, rd.stack.top() & 0xFF);
	rd.stack.pop();
	rd.writeBitS(0xB, 7, true); // GIE
	printf("%s\n", identifier.c_str());
}

RETLW::RETLW(const std::string& identifier, uint16_t mask, uint16_t value)
	: InstructionBase(identifier, mask, value, 2)
{
}

void RETLW::execute(RegisterData& rd)
{
	if (rd.stack.empty())
		throw exception("Stack is empty!");
	rd.writeByte(0xA, (rd.stack.top() << 8) & 0x1F);
	rd.writeByte(0x2, rd.stack.top() & 0xFF);
	rd.stack.pop();
	rd.cpuRegisters.w = static_cast<uint8_t>(data.k);
	printf("%s 0x%X\n", identifier.c_str(), data.k);
}

RETURN::RETURN(const std::string& identifier, uint16_t mask, uint16_t value)
	: InstructionBase(identifier, mask, value, 2)
{
}

void RETURN::execute(RegisterData& rd)
{
	if (rd.stack.empty())
		throw std::runtime_error(fmt::format("%s: Stack is empty!", __FUNCTION__));
	rd.writeByte(0xA, (rd.stack.top() << 8) & 0x1F);
	rd.writeByte(0x2, rd.stack.top() & 0xFF);
	rd.stack.pop();
	printf("%s 0x%X\n", identifier.c_str(), data.k);
}

SLEEP::SLEEP(const std::string& identifier, uint16_t mask, uint16_t value)
	: InstructionBase(identifier, mask, value)
{
}

void SLEEP::execute(RegisterData& rd)
{
	throw std::runtime_error(fmt::format("Not implemented: %s", identifier));
	rd.increasePCBy(getCycles());
}

SUBLW::SUBLW(const std::string& identifier, uint16_t mask, uint16_t value)
	: InstructionBase(identifier, mask, value)
{
}

void SUBLW::execute(RegisterData& rd)
{
	auto& w = rd.cpuRegisters.w;
	int result = static_cast<int>(data.k) - w;
	w = static_cast<uint8_t>(result);
	bool digitCarry = ((data.k & 0xF) + ((~w + 1) & 0xF)) & 0xF0;
	rd.writeBitS(0x3, 0x0, result >= 0); // carry bit
	rd.writeBitS(0x3, 0x1, !digitCarry); // digit carry
	rd.writeBitS(0x3, 0x2, static_cast<uint8_t>(result) == 0); // zero flag
	printf("%s 0x%X, %d (w = %d)\n", identifier.c_str(), data.f, data.d, w);
	rd.increasePCBy(getCycles());
}

XORLW::XORLW(const std::string& identifier, uint16_t mask, uint16_t value)
	: InstructionBase(identifier, mask, value)
{
}

void XORLW::execute(RegisterData& rd)
{
	auto& w = rd.cpuRegisters.w;
	uint8_t result = w ^ data.k;
	w = result;
	rd.writeBitS(0x3, 0x2, result == 0); // zero flag
	printf("%s 0x%X\n", identifier.c_str(), data.k);
	rd.increasePCBy(getCycles());
}
