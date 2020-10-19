#pragma once
#include <stdint.h>
#include <string>

class RegisterData;

enum ResultDestination : uint8_t {
	ToAccumulator = 0,
	ToFileRegister = 1
};

struct InstructionData
{
	uint8_t bits;
	uint8_t destination;
	uint8_t fileRegisterAddress;
	uint16_t k;	// can be 11 bits
};

class InstructionBase
{
public:
	InstructionBase(const std::string& identifier, uint16_t mask, uint16_t value, int cycles = 1);
	bool match(const uint16_t& opcode);
	const int& getCycles();

	virtual void execute(RegisterData& rd, InstructionData& data) = 0;

protected:
	void setCycles(int count);

	uint16_t mask;
	uint16_t value;
	std::string identifier;

private:
	int cycles;
};