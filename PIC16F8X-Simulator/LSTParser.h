#pragma once

#include <vector>
#include <string>
#include <regex>

struct LstOpcodeInfo
{
	uint16_t pcValue;
	uint16_t opcode;
	uint16_t lineInFile;
};

class LstParser
{
	public:
		LstParser();
		void loadLstFile(const std::string& fileName);
		void extractLstInfoFromFile();

		const uint16_t& getLineInFileForPC(const uint16_t& pc) const;
		const std::vector<std::string>& getLstFileData() const;
		const std::vector<LstOpcodeInfo>& getAllOpcodes();

	private:
		std::vector<std::string> lstFile;
		std::vector<LstOpcodeInfo> lstOpcodeInfo;
		std::regex lineRegex;
		std::regex fileRegex;
};
