#pragma once

#include <vector>
#include <string>
#include <regex>

struct LstOpcodeInfo
{
	uint16_t opcode;
	uint16_t lineInFile;
};

class LstParser
{
	public:
		LstParser();
		void readFile(const std::string& fileName);
		void parseLstFile();

		uint16_t getMaxPc() const;
		const LstOpcodeInfo& getOpcodeInfo(const uint16_t& pc) const;
		uint16_t getLineInFile(const uint16_t& pc) const;
		const std::vector<std::string>& getFile() const;

	private:
		std::vector<std::string> lstFile;
		std::vector<LstOpcodeInfo> lstOpcodeInfo;
		std::regex lineRegex;
		std::regex fileRegex;
};
