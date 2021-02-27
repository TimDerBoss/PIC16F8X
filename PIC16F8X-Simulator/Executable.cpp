#include "Executable.h"
#include "RegisterData.h"
#include "InstructionHandler.h"

#include <FormatString.h>

#include <iostream>

Executable::Executable(const std::string& identifier, uint16_t mask, uint16_t value, int cycles)
	: mask(mask)
	, value(value)
	, identifier(identifier)
	, cycles(cycles)
{
}

bool Executable::match(const uint16_t& opcode)
{
	return (opcode & mask) == value;
}

const int& Executable::getCycles()
{
	return cycles;
}

void Executable::setCycles(int count)
{
	cycles = count;
}
