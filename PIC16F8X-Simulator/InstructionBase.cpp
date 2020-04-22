#include "InstructionBase.h"
#include "RegisterData.h"
#include "InstructionHandler.h"

#include <FormatString.h>

#include <iostream>

InstructionBase::InstructionBase(const std::string& identifier, uint16_t mask, uint16_t value, int cycles)
	: mask(mask)
	, value(value)
	, identifier(identifier)
	, cycles(cycles)
{
}

bool InstructionBase::match(const uint16_t& opcode)
{
	// and the opcode with the mask and return the result
	return (opcode & mask) == value;
}

const int& InstructionBase::getCycles()
{
	// get the number of machine cycles the instruction takes
	return cycles;
}

void InstructionBase::cacheData(InstructionData data)
{
	// cache some data to use later
	this->data = data;
}

void InstructionBase::setCycles(int count)
{
	cycles = count;
}
