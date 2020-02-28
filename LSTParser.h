#pragma once
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

	private:
		std::vector<std::string> lstFile;
		std::vector<LSTOpcodeInfo> lstOcInfo;
		std::regex lstRegex;
};
