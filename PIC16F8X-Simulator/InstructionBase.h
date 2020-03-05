#pragma once
#include <stdint.h>
#include <string>

class RegisterData;

struct InstructionData
{
	uint8_t b;
	uint8_t d;
	uint8_t f;
	uint16_t k;	// can be 11 bits
};

class InstructionBase
{
public:
	InstructionBase(const std::string& identifier, uint16_t mask, uint16_t value, RegisterData& rd, int cycles = 1);
	bool match(const uint16_t& opcode);
	const int& getCycles();
	void cacheData(InstructionData data);

	virtual void execute() = 0;

protected:
	void setCycles(int count);

	uint16_t mask;
	uint16_t value;
	std::string identifier;
	RegisterData& registerData;
	InstructionData data;

private:
	int cycles;
};