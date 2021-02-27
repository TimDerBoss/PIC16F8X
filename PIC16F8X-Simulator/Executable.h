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

class Executable
{
public:
	Executable(const std::string& identifier, uint16_t mask, uint16_t value, int cycles = 1);
	virtual bool match(const uint16_t& opcode) final;
	virtual const int& getCycles() final;

	virtual void execute(RegisterData& rd, InstructionData& data) = 0;

protected:
	virtual void setCycles(int count) final;

	uint16_t mask;
	uint16_t value;
	std::string identifier;

private:
	int cycles;
};