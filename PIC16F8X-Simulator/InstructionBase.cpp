#include "InstructionBase.h"
#include "RegisterData.h"
#include "InstructionHandler.h"

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

const int& InstructionBase::getCycles()
{
	return cycles;
}

void InstructionBase::cacheData(InstructionData data)
{
	this->data = data;
}

void InstructionBase::setCycles(int count)
{
	cycles = count;
}
