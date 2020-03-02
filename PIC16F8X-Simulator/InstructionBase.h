#pragma once
#include <stdint.h>
#include <string>

class RegisterData;

class InstructionBase
{
		struct InstructionData
		{
			uint8_t b;
			uint8_t d;
			uint8_t f;
			uint16_t k;	// can be 11 bits
		};

	public:
		InstructionBase(const std::string& identifier, uint16_t mask, uint16_t value, RegisterData& rd, int cycles = 1);
		bool match(const uint16_t& opcode);

		virtual void execute(const uint16_t& opcode) = 0;
	protected:
		static InstructionData getInstructionData(const uint16_t& opcode);
		const int& getCycles();
		void setCycles(int count);

		uint16_t mask;
		uint16_t value;
		std::string identifier;
		RegisterData& registerData;

private:
		int cycles;
};