#pragma once

#include <vector>
#include <string>
#include <regex>

struct LSTOpcodeInfo
{
	uint16_t opcode;
	uint16_t lineInFile;
};

class LSTParser
{
	public:
		LSTParser();
		void readFile(const std::string& fileName);
		void parseLstFile();

		uint16_t getMaxPc() const;
		const LSTOpcodeInfo& getOpcodeInfo(const uint16_t& pc) const;
		const uint16_t& getLineInFile(const uint16_t& pc) const;
		const std::vector<std::string>& getFile() const;

	private:
		std::vector<std::string> lstFile;
		std::vector<LSTOpcodeInfo> lstOpcodeInfo;
		std::regex lstRegex;
};
