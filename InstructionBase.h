#pragma once
#include <stdint.h>
#include <string>

class RegisterData;

class InstructionBase
{
		struct InstructionData
		{
			uint16_t b;
			uint16_t d;
			uint16_t f;
			uint16_t k;
		};

	public:
		InstructionBase(const std::string& identifier, uint16_t mask, uint16_t value, RegisterData& rd);
		bool match(const uint16_t& opcode);

		virtual void execute(const uint16_t& opcode) = 0;
	protected:
		static InstructionData getInstructionData(const uint16_t& opcode);

		uint16_t mask;
		uint16_t value;
		std::string identifier;
		RegisterData& registerData;
};