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

		const std::vector<LSTOpcodeInfo>& getLstOpcodeInfo()
		{
			return lstOpcodeInfo;
		}

	private:
		std::vector<std::string> lstFile;
		std::vector<LSTOpcodeInfo> lstOpcodeInfo;
		std::regex lstRegex;
};
