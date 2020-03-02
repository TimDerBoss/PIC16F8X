#include "LSTParser.h"
#include "format.h"

#include <fstream>
#include <sstream>

LSTParser::LSTParser()
	: lstRegex(R"(^([\d|\w]{4})\s([\d|\w]{4})\s+(\d+).*$)")
{
}

void LSTParser::readFile(const std::string& fileName)
{
	std::ifstream file(fileName);
	if (file.is_open()) {
		std::string line;
		while (getline(file, line)) {
			lstFile.push_back(line);
		}
		file.close();
	} else {
		throw std::runtime_error(fmt::format("File not found: %s\n", fileName));
	}
}

void LSTParser::parseLstFile()
{
	for (std::string line : lstFile) {
		line = line.substr(0, line.length() - 2);
		std::smatch matches;
		if (std::regex_match(line, matches, lstRegex)) {
			// Index of the object in the vector is the instruction number
			LSTOpcodeInfo loi{};
			loi.lineInFile = stoi(matches[3]) - 1;
			std::stringstream ss;
			ss << std::hex << matches[2];
			ss >> loi.opcode;
			lstOpcodeInfo.push_back(loi);
		}
	}
}

const std::vector<LSTOpcodeInfo>& LSTParser::getLstOpcodeInfo()
{
	return lstOpcodeInfo;
}

const std::vector<std::string>& LSTParser::getFile()
{
	return lstFile;
}

