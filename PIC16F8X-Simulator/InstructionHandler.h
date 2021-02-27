#include "Executable.h"
#include "LSTParser.h"

#include <vector>
#include <unordered_map>
#include <memory>
#include <cstdint>


class RegisterData;

class InstructionHandler
{
	public:
		InstructionHandler(const std::vector<LstOpcodeInfo>& lstOpcodeInfo);


		std::shared_ptr<Executable>& decodeAt(int programCounter);
		InstructionData getInstructionData(int programCounter);
		uint16_t getOpcodeAtPC(int programCounter);

	private:
		const std::vector<LstOpcodeInfo>& lstOpcodeInfo;
		std::vector<std::shared_ptr<Executable>> instructions;
};

