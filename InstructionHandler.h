//
// Created by tfa on 26.02.20.
//
#include <vector>
#include <unordered_map>
#include <memory>
#include <cstdint>

#include "InstructionBase.h"

class RegisterData;

class InstructionHandler
{
	public:
		InstructionHandler(RegisterData& rd);

		std::shared_ptr<InstructionBase> decode(const uint16_t& opcode);

	private:
		std::vector<std::shared_ptr<InstructionBase>> instructions;
		std::unordered_map<uint16_t, std::shared_ptr<InstructionBase>> instructionCache;
};

