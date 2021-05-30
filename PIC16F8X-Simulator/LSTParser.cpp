#include "LSTParser.h"
#include "Exception.h"

#include <FormatString.h>

#include <fstream>
#include <sstream>


LstParser::LstParser()
	: lineRegex(R"(^([\d|\w]{4})\s([\d|\w]{4})\s+(\d+).*$)")
	, fileRegex(R"(^(\s{20}\d{5}.*)$|^([\d|\w]{4})\s([\d|\w]{4})\s{11}\d{5}\s.*$)")
{
}

// Check if file matched regex, if yes read the file into a buffer
void LstParser::loadLstFile(const std::string& fileName)
{
	lstFile.clear();
	std::ifstream file(fileName);
	if (file.is_open()) {
		std::string line;
		while (getline(file, line)) {
			lstFile.push_back(line);
		}
		file.close();
		if (!isLstFileValid())
		{
			throw fatal_exception("Invalid file format");
		}
	}
	else {
		throw fatal_exception("File not found: %s", fileName);
	}
}


void LstParser::extractLstInfoFromFile()
{
	lstOpcodeInfo.clear();
	for (std::string line : lstFile) {
		line = line.substr(0, line.length() - 2);
		std::smatch matches;
		if (std::regex_match(line, matches, lineRegex)) {
			// Index of the object in the vector is the instruction number
			LstOpcodeInfo loi{};
			loi.lineInFile = stoi(matches[3]) - 1;
			std::stringstream ss2;
			ss2 << std::hex << matches[1];
			ss2 >> loi.pcValue;
			std::stringstream ss;
			ss << std::hex << matches[2];
			ss >> loi.opcode;
			lstOpcodeInfo.push_back(loi);
		}
	}
}

bool LstParser::isLstFileValid()
{
	for (auto& line : lstFile) {
		std::smatch matches;
		if (!std::regex_match(line, matches, fileRegex)) {
			return false;
		}
	}
	return true;
}


const uint16_t& LstParser::getLineInFileForPC(const uint16_t& pc) const
{
	for (auto& info : lstOpcodeInfo)
	{
		if (info.pcValue == pc)
			return info.lineInFile;
	}
	throw fatal_exception("Could not find the corresponding line for PC-value '%d'", pc);
}


const std::vector<std::string>& LstParser::getLstFileData() const
{
	return lstFile;
}

const std::vector<LstOpcodeInfo>& LstParser::getAllOpcodes()
{
	return lstOpcodeInfo;
}


