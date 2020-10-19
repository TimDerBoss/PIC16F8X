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

void ADDWF::execute(RegisterData& rd, InstructionData& data)
{
	auto& w = rd.cpuRegisters.accumulator;
	int fnum = rd.readByteS(data.fileRegisterAddress);
	int result = static_cast<int>(w + fnum);
	bool digitCarry = ((w & 0xF) + (fnum & 0xF)) & 0xF0;
	if (data.destination == ResultDestination::ToAccumulator) {
		w = static_cast<uint8_t>(result);
	}
	else {
		rd.writeByteS(data.fileRegisterAddress, static_cast<uint8_t>(result));
	}
	rd.writeBitS(0x3, 0x0, result > 255 || result < 0); // carry bit
	rd.writeBitS(0x3, 0x1, digitCarry); // digit carry
	rd.writeBitS(0x3, 0x2, static_cast<uint8_t>(result) == 0); // zero flag
	printf("%s 0x%X, %d (w = %d)\n", identifier.c_str(), data.fileRegisterAddress, data.destination, w);
	rd.increasePCBy(getCycles());
}

ANDWF::ANDWF(const std::string& identifier, uint16_t mask, uint16_t value)
	: InstructionBase(identifier, mask, value)
{
}

void ANDWF::execute(RegisterData& rd, InstructionData& data)
{
	auto& w = rd.cpuRegisters.accumulator;
	uint8_t result = w & rd.readByteS(data.fileRegisterAddress);
	if (data.destination == ResultDestination::ToAccumulator) {
		w = result;
	}
	else {
		rd.writeByteS(data.fileRegisterAddress, result);
	}
	rd.writeBitS(0x3, 0x2, static_cast<uint8_t>(result) == 0); // zero flag
	printf("%s 0x%X, %d (w = %d)\n", identifier.c_str(), data.fileRegisterAddress, data.destination, w);
	rd.increasePCBy(getCycles());
}

CLRF::CLRF(const std::string& identifier, uint16_t mask, uint16_t value)
	: InstructionBase(identifier, mask, value)
{
}

void CLRF::execute(RegisterData& rd, InstructionData& data)
{

	rd.writeByteS(data.fileRegisterAddress, 0);
	rd.writeBitS(0x3, 0x2, true); // zero flag
	printf("%s 0x%X, %d\n", identifier.c_str(), data.fileRegisterAddress, data.destination);
	rd.increasePCBy(getCycles());
}

CLRW::CLRW(const std::string& identifier, uint16_t mask, uint16_t value)
	: InstructionBase(identifier, mask, value)
{
}

void CLRW::execute(RegisterData& rd, InstructionData& data)
{
	rd.cpuRegisters.accumulator = 0;
	rd.writeBitS(0x3, 0x2, true); // zero flag
	printf("%s\n", identifier.c_str());
	rd.increasePCBy(getCycles());
}

COMF::COMF(const std::string& identifier, uint16_t mask, uint16_t value)
	: InstructionBase(identifier, mask, value)
{
}

void COMF::execute(RegisterData& rd, InstructionData& data)
{

	auto& w = rd.cpuRegisters.accumulator;
	uint8_t result = ~rd.readByteS(data.fileRegisterAddress);
	if (data.destination == ResultDestination::ToAccumulator) {
		w = result;
	}
	else {
		rd.writeByteS(data.fileRegisterAddress, result);
	}
	rd.writeBitS(0x3, 0x2, result == 0); // zero flag
	printf("%s 0x%X, %d (w = %d)\n", identifier.c_str(), data.fileRegisterAddress, data.destination, w);
	rd.increasePCBy(getCycles());
}

DECF::DECF(const std::string& identifier, uint16_t mask, uint16_t value)
	: InstructionBase(identifier, mask, value)
{
}

void DECF::execute(RegisterData& rd, InstructionData& data)
{

	auto& w = rd.cpuRegisters.accumulator;
	uint8_t result = rd.readByteS(data.fileRegisterAddress) - 1;
	if (data.destination == ResultDestination::ToAccumulator) {
		w = result;
	}
	else {
		rd.writeByteS(data.fileRegisterAddress, result);
	}
	rd.writeBitS(0x3, 0x2, result == 0); // zero flag
	printf("%s 0x%X, %d (w = %d)\n", identifier.c_str(), data.fileRegisterAddress, data.destination, w);
	rd.increasePCBy(getCycles());
}

DECFSZ::DECFSZ(const std::string& identifier, uint16_t mask, uint16_t value)
	: InstructionBase(identifier, mask, value)
{
}

void DECFSZ::execute(RegisterData& rd, InstructionData& data)
{

	auto& w = rd.cpuRegisters.accumulator;
	uint8_t result = rd.readByteS(data.fileRegisterAddress) - 1;
	if (data.destination == ResultDestination::ToAccumulator) {
		w = result;
	}
	else {
		rd.writeByteS(data.fileRegisterAddress, result);
	}
	if (result == 0) {
		setCycles(2);
	}
	else {
		setCycles(1);
	}
	printf("%s 0x%X, %d (w = %d)\n", identifier.c_str(), data.fileRegisterAddress, data.destination, w);
	rd.increasePCBy(getCycles());
}

INCF::INCF(const std::string& identifier, uint16_t mask, uint16_t value)
	: InstructionBase(identifier, mask, value)
{
}

void INCF::execute(RegisterData& rd, InstructionData& data)
{

	auto& w = rd.cpuRegisters.accumulator;
	uint8_t result = rd.readByteS(data.fileRegisterAddress) + 1;
	if (data.destination == ResultDestination::ToAccumulator) {
		w = result;
	}
	else {
		rd.writeByteS(data.fileRegisterAddress, result);
	}
	rd.writeBitS(0x3, 0x2, result == 0); // zero flag
	printf("%s 0x%X, %d (w = %d)\n", identifier.c_str(), data.fileRegisterAddress, data.destination, w);
	rd.increasePCBy(getCycles());
}

INCFSZ::INCFSZ(const std::string& identifier, uint16_t mask, uint16_t value)
	: InstructionBase(identifier, mask, value)
{
}

void INCFSZ::execute(RegisterData& rd, InstructionData& data)
{

	auto& w = rd.cpuRegisters.accumulator;
	uint8_t result = rd.readByteS(data.fileRegisterAddress) + 1;
	if (data.destination == ResultDestination::ToAccumulator) {
		w = result;
	}
	else {
		rd.writeByteS(data.fileRegisterAddress, result);
	}
	if (result == 0) {
		setCycles(2);
	}
	else {
		setCycles(1);
	}
	printf("%s 0x%X, %d (w = %d)\n", identifier.c_str(), data.fileRegisterAddress, data.destination, w);
	rd.increasePCBy(getCycles());
}

IORWF::IORWF(const std::string& identifier, uint16_t mask, uint16_t value)
	: InstructionBase(identifier, mask, value)
{
}

void IORWF::execute(RegisterData& rd, InstructionData& data)
{

	auto& w = rd.cpuRegisters.accumulator;
	uint8_t result = rd.readByteS(data.fileRegisterAddress) | w;
	if (data.destination == ResultDestination::ToAccumulator) {
		w = result;
	}
	else {
		rd.writeByteS(data.fileRegisterAddress, result);
	}
	rd.writeBitS(0x3, 0x2, result != 0); // zero flag
	printf("%s 0x%X, %d (w = %d)\n", identifier.c_str(), data.fileRegisterAddress, data.destination, w);
	rd.increasePCBy(getCycles());
}

MOVF::MOVF(const std::string& identifier, uint16_t mask, uint16_t value)
	: InstructionBase(identifier, mask, value)
{
}

void MOVF::execute(RegisterData& rd, InstructionData& data)
{
	auto& w = rd.cpuRegisters.accumulator;
	if (data.destination == ResultDestination::ToAccumulator) {
		w = rd.readByteS(data.fileRegisterAddress);
	}
	rd.writeBitS(0x3, 0x2, rd.readByteS(data.fileRegisterAddress) == 0); // zero flag
	printf("%s 0x%X, %d (w = %d)\n", identifier.c_str(), data.fileRegisterAddress, data.destination, w);
	rd.increasePCBy(getCycles());
}

MOVWF::MOVWF(const std::string& identifier, uint16_t mask, uint16_t value)
	: InstructionBase(identifier, mask, value)
{
}

void MOVWF::execute(RegisterData& rd, InstructionData& data)
{

	auto& w = rd.cpuRegisters.accumulator;
	rd.writeByteS(data.fileRegisterAddress, w);
	printf("%s 0x%X, %d (w = %d)\n", identifier.c_str(), data.fileRegisterAddress, data.destination, w);
	rd.increasePCBy(getCycles());
}

NOP::NOP(const std::string& identifier, uint16_t mask, uint16_t value)
	: InstructionBase(identifier, mask, value)
{
}

void NOP::execute(RegisterData& rd, InstructionData& data)
{
	printf("%s\n", identifier.c_str());
	rd.increasePCBy(getCycles());
}

RLF::RLF(const std::string& identifier, uint16_t mask, uint16_t value)
	: InstructionBase(identifier, mask, value)
{
}

void RLF::execute(RegisterData& rd, InstructionData& data)
{

	uint8_t tempCarry = rd.readBitS(0x3, 0x0);
	uint8_t fBefore = rd.readByteS(data.fileRegisterAddress);
	auto& w = rd.cpuRegisters.accumulator;

	rd.writeBitS(0x3, 0x0, (fBefore >> 7) & 1);
	fBefore <<= 1;
	fBefore |= tempCarry;

	if (data.destination == ResultDestination::ToAccumulator) {
		w = fBefore;
	}
	else {
		rd.writeByteS(data.fileRegisterAddress, fBefore);
	}
	printf("%s 0x%X, %d (w = %d)\n", identifier.c_str(), data.fileRegisterAddress, data.destination, w);
	rd.increasePCBy(getCycles());
}

RRF::RRF(const std::string& identifier, uint16_t mask, uint16_t value)
	: InstructionBase(identifier, mask, value)
{
}

void RRF::execute(RegisterData& rd, InstructionData& data)
{

	uint8_t fBefore = rd.readByteS(data.fileRegisterAddress);
	auto& w = rd.cpuRegisters.accumulator;

	bool tmpOverflow = fBefore & 1;
	fBefore >>= 1;
	fBefore |= (rd.readBitS(0x3, 0) << 7);
	rd.writeBitS(0x3, 0, tmpOverflow);

	if (data.destination == ResultDestination::ToAccumulator) {
		w = fBefore;
	}
	else {
		rd.writeByteS(data.fileRegisterAddress, fBefore);
	}
	printf("%s 0x%X, %d (w = %d)\n", identifier.c_str(), data.fileRegisterAddress, data.destination, w);
	rd.increasePCBy(getCycles());
}

SUBWF::SUBWF(const std::string& identifier, uint16_t mask, uint16_t value)
	: InstructionBase(identifier, mask, value)
{
}

void SUBWF::execute(RegisterData& rd, InstructionData& data)
{

	auto& w = rd.cpuRegisters.accumulator;
	auto& fnum = rd.readByteS(data.fileRegisterAddress);
	int result = fnum - w;
	if (data.destination == ResultDestination::ToAccumulator) {
		w = static_cast<uint8_t>(result);
	}
	else {
		rd.writeByteS(data.fileRegisterAddress, static_cast<uint8_t>(result));
	}
	rd.writeBitS(0x3, 0x0, result >= 0); // carry bit
	bool digitCarry = ((fnum & 0xF) + ((~w + 1) & 0xF)) & 0xF0;
	rd.writeBitS(0x3, 0x1, !digitCarry); // digit carry
	rd.writeBitS(0x3, 0x2, static_cast<uint8_t>(result) == 0); // zero flag
	printf("%s 0x%X, %d (w = %d)\n", identifier.c_str(), data.fileRegisterAddress, data.destination, w);
	rd.increasePCBy(getCycles());
}


SWAPF::SWAPF(const std::string& identifier, uint16_t mask, uint16_t value)
	: InstructionBase(identifier, mask, value)
{
}

void SWAPF::execute(RegisterData& rd, InstructionData& data)
{

	auto& w = rd.cpuRegisters.accumulator;
	uint8_t result = rd.readByteS(data.fileRegisterAddress);

	uint8_t temp = result & 0xF;
	result >>= 4;
	result |= (temp << 4);

	if (data.destination == ResultDestination::ToAccumulator) {
		w = result;
	}
	else {
		rd.writeByteS(data.fileRegisterAddress, result);
	}
	printf("%s 0x%X, %d (w = %d)\n", identifier.c_str(), data.fileRegisterAddress, data.destination, w);
	rd.increasePCBy(getCycles());
}

XORWF::XORWF(const std::string& identifier, uint16_t mask, uint16_t value)
	: InstructionBase(identifier, mask, value)
{
}

void XORWF::execute(RegisterData& rd, InstructionData& data)
{

	auto& w = rd.cpuRegisters.accumulator;
	uint8_t result = rd.readByteS(data.fileRegisterAddress) ^ w;
	if (data.destination == ResultDestination::ToAccumulator) {
		w = result;
	}
	else {
		rd.writeByteS(data.fileRegisterAddress, result);
	}
	rd.writeBitS(0x3, 0x2, result == 0); // zero flag
	printf("%s 0x%X, %d (w = %d)\n", identifier.c_str(), data.fileRegisterAddress, data.destination, w);
	rd.increasePCBy(getCycles());
}

BCF::BCF(const std::string& identifier, uint16_t mask, uint16_t value)
	: InstructionBase(identifier, mask, value)
{
}

void BCF::execute(RegisterData& rd, InstructionData& data)
{
	rd.writeBitS(data.fileRegisterAddress, data.bits, false);
	printf("%s 0x%X, %d\n", identifier.c_str(), data.fileRegisterAddress, data.bits);
	rd.increasePCBy(getCycles());
}

BSF::BSF(const std::string& identifier, uint16_t mask, uint16_t value)
	: InstructionBase(identifier, mask, value)
{
}

void BSF::execute(RegisterData& rd, InstructionData& data)
{
	rd.writeBitS(data.fileRegisterAddress, data.bits, true);
	printf("%s 0x%X, %d\n", identifier.c_str(), data.fileRegisterAddress, data.bits);
	rd.increasePCBy(getCycles());
}

BTFSC::BTFSC(const std::string& identifier, uint16_t mask, uint16_t value)
	: InstructionBase(identifier, mask, value)
{
}

void BTFSC::execute(RegisterData& rd, InstructionData& data)
{
	uint8_t bit = rd.readBitS(data.fileRegisterAddress, data.bits);
	if (bit) {
		setCycles(1);
	}
	else {
		setCycles(2);
	}
	printf("%s 0x%X, %d\n", identifier.c_str(), data.fileRegisterAddress, data.bits);
	rd.increasePCBy(getCycles());
}

BTFSS::BTFSS(const std::string& identifier, uint16_t mask, uint16_t value)
	: InstructionBase(identifier, mask, value)
{
}

void BTFSS::execute(RegisterData& rd, InstructionData& data)
{
	uint8_t bit = rd.readBitS(data.fileRegisterAddress, data.bits);
	if (!bit) {
		setCycles(1);
	}
	else {
		setCycles(2);
	}
	printf("%s 0x%X, %d\n", identifier.c_str(), data.fileRegisterAddress, data.bits);
	rd.increasePCBy(getCycles());
}

ADDLW::ADDLW(const std::string& identifier, uint16_t mask, uint16_t value)
	: InstructionBase(identifier, mask, value)
{
}

void ADDLW::execute(RegisterData& rd, InstructionData& data)
{
	auto& w = rd.cpuRegisters.accumulator;
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

void ANDLW::execute(RegisterData& rd, InstructionData& data)
{
	auto& w = rd.cpuRegisters.accumulator;
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

void CALL::execute(RegisterData& rd, InstructionData& data)
{
	rd.stack.push(rd.getPc() + 1);

	int tmp = 0;
	tmp |= data.k;
	tmp |= ((rd.readByte(0xA) << 8) & 0x1800);
	rd.writeByte(0x2, data.k & 0xFF);
	rd.setPc(tmp);

	printf("%s 0x%X\n", identifier.c_str(), data.k);
}

CLRWDT::CLRWDT(const std::string& identifier, uint16_t mask, uint16_t value)
	: InstructionBase(identifier, mask, value)
{
}

void CLRWDT::execute(RegisterData& rd, InstructionData& data)
{
	rd.writeByte(0x81, "xxxxxccc");
	rd.writeByte(0x3, "xxxssxxx");
	rd.watchdog.reset();
	rd.increasePCBy(getCycles());
}

GOTO::GOTO(const std::string& identifier, uint16_t mask, uint16_t value)
	: InstructionBase(identifier, mask, value, 2)
{
}

void GOTO::execute(RegisterData& rd, InstructionData& data)
{
	int tmp = 0;
	tmp |= data.k;
	tmp |= ((rd.readByte(0xA) << 8) & 0x1800);
	rd.writeByte(0x2, data.k & 0xFF);
	rd.setPc(tmp);

	printf("%s 0x%X\n", identifier.c_str(), data.k);
}

IORLW::IORLW(const std::string& identifier, uint16_t mask, uint16_t value)
	: InstructionBase(identifier, mask, value)
{
}

void IORLW::execute(RegisterData& rd, InstructionData& data)
{
	auto& w = rd.cpuRegisters.accumulator;
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

void MOVLW::execute(RegisterData& rd, InstructionData& data)
{
	rd.cpuRegisters.accumulator = static_cast<uint8_t>(data.k);
	printf("%s 0x%X\n", identifier.c_str(), data.k);
	rd.increasePCBy(getCycles());
}

RETFIE::RETFIE(const std::string& identifier, uint16_t mask, uint16_t value)
	: InstructionBase(identifier, mask, value, 2)
{
}

void RETFIE::execute(RegisterData& rd, InstructionData& data)
{
	if (!rd.stack.Size())
		throw fatal_exception("Stack is empty!");
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

void RETLW::execute(RegisterData& rd, InstructionData& data)
{
	if (!rd.stack.Size())
		throw fatal_exception("Stack is empty!");
	rd.writeByte(0xA, (rd.stack.top() << 8) & 0x1F);
	rd.writeByte(0x2, rd.stack.top() & 0xFF);
	rd.stack.pop();
	rd.cpuRegisters.accumulator = static_cast<uint8_t>(data.k);
	printf("%s 0x%X\n", identifier.c_str(), data.k);
}

RETURN::RETURN(const std::string& identifier, uint16_t mask, uint16_t value)
	: InstructionBase(identifier, mask, value, 2)
{
}

void RETURN::execute(RegisterData& rd, InstructionData& data)
{
	if (!rd.stack.Size())
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

void SLEEP::execute(RegisterData& rd, InstructionData& data)
{
	throw std::runtime_error(fmt::format("Not implemented: %s", identifier));
	rd.increasePCBy(getCycles());
}

SUBLW::SUBLW(const std::string& identifier, uint16_t mask, uint16_t value)
	: InstructionBase(identifier, mask, value)
{
}

void SUBLW::execute(RegisterData& rd, InstructionData& data)
{
	auto& w = rd.cpuRegisters.accumulator;
	int result = static_cast<int>(data.k) - w;
	w = static_cast<uint8_t>(result);
	bool digitCarry = ((data.k & 0xF) + ((~w + 1) & 0xF)) & 0xF0;
	rd.writeBitS(0x3, 0x0, result >= 0); // carry bit
	rd.writeBitS(0x3, 0x1, !digitCarry); // digit carry
	rd.writeBitS(0x3, 0x2, static_cast<uint8_t>(result) == 0); // zero flag
	printf("%s 0x%X, %d (w = %d)\n", identifier.c_str(), data.fileRegisterAddress, data.destination, w);
	rd.increasePCBy(getCycles());
}

XORLW::XORLW(const std::string& identifier, uint16_t mask, uint16_t value)
	: InstructionBase(identifier, mask, value)
{
}

void XORLW::execute(RegisterData& rd, InstructionData& data)
{
	auto& w = rd.cpuRegisters.accumulator;
	uint8_t result = w ^ data.k;
	w = result;
	rd.writeBitS(0x3, 0x2, result == 0); // zero flag
	printf("%s 0x%X\n", identifier.c_str(), data.k);
	rd.increasePCBy(getCycles());
}
