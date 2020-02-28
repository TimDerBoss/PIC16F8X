#include "LSTParser.h"

#include <fstream>
#include <fmt/format.h>

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
		throw std::runtime_error(fmt::format("File not found: {}\n", fileName));
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
			loi.lineInFile = stoi(matches[3]);
			std::stringstream ss;
			ss << std::hex << matches[2];
			ss >> loi.opcode;
			lstOpcodeInfo.push_back(loi);
		}
	}
}

