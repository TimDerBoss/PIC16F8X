#include "InstructionBase.h"
#include "RegisterData.h"

#include <FormatString.h>

#include <iostream>

InstructionBase::InstructionBase(const std::string& identifier, uint16_t mask, uint16_t value, RegisterData& rd, int cycles)
	: mask(mask)
	, value(value)
	, identifier(identifier)
	, registerData(rd)
	, cycles(cycles)
{
}

bool InstructionBase::match(const uint16_t& opcode)
{
	return (opcode & mask) == value;
}

InstructionBase::InstructionData InstructionBase::getInstructionData(const uint16_t& opcode)
{
	InstructionBase::InstructionData data{};
	uint16_t commandType = opcode & 0xF000u;
	switch (commandType) {
		case 0x0000: // Byte oriented command
			data.d = opcode >> 0x7u & 0x1u;
			data.f = opcode & 0x007Fu;
			break;
		case 0x1000: // Bit oriented command
			data.b = opcode >> 0x7u & 0x7u;
			data.f = opcode & 0x007Fu;
			break;
		case 0x2000: // literal and control long address
			data.k = opcode & 0x07FFu;
			break;
		case 0x3000: // literal and control uint16_t address
			data.k = opcode & 0x00FFu;
			break;
		default:
			throw std::runtime_error(fmt::format("Unknown instruction data type: 0x%X", commandType));
	}
	return data;
}

const int& InstructionBase::getCycles()
{
	return cycles;
}

void InstructionBase::setCycles(int count)
{
	cycles = count;
}
