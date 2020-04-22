#include "InstructionBase.h"

#include <vector>
#include <unordered_map>
#include <memory>
#include <cstdint>

class RegisterData;

class InstructionHandler
{
	public:
		InstructionHandler();

		std::shared_ptr<InstructionBase>& decode(const uint16_t& opcode);
		InstructionData getInstructionData(const uint16_t& opcode);

	private:
		std::vector<std::shared_ptr<InstructionBase>> instructions;
		std::unordered_map<uint16_t, std::shared_ptr<InstructionBase>> instructionCache;
};

