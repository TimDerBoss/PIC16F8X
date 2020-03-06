#include "LSTParser.h"

#include <FormatString.h>

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
	}
	else {
		throw std::runtime_error(fmt::format("%s: File not found: %s\n", __FUNCTION__, fileName));
	}
	if (lstFile.empty()) {
		throw std::runtime_error(fmt::format("%s: Invalid file format", __FUNCTION__));
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

uint16_t LSTParser::getMaxPc() const
{
	return static_cast<uint16_t>(lstOpcodeInfo.size()) - 1;
}

const LSTOpcodeInfo& LSTParser::getOpcodeInfo(const uint16_t& pc) const
{
	if (pc >= lstOpcodeInfo.size())
		throw std::runtime_error(fmt::format("%s: Program counter is out of range. PC = %d, Max = %d", __FUNCTION__,  static_cast<int>(pc), static_cast<int>(lstOpcodeInfo.size())));
	else return lstOpcodeInfo.at(pc);
}

const uint16_t& LSTParser::getLineInFile(const uint16_t& pc) const
{
	if (pc >= lstOpcodeInfo.size())
		return 0;
	else return lstOpcodeInfo.at(pc).lineInFile;
}

const std::vector<std::string>& LSTParser::getFile() const
{
	return lstFile;
}

