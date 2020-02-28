#pragma once
#include <fstream>
#include <sstream>
#include <regex>

struct LSTOpcodeInfo
{
	uint16_t opcode;
	uint16_t lineInFile;
};

class LSTParser
{
	public:
		LSTParser()
			: lstRegex(R"(^([\d|\w]{4})\s([\d|\w]{4})\s+(\d+).*$)")
		{
		}

		void readFile(const std::string& fileName)
		{
			std::ifstream file(fileName);
			if (file.is_open()) {
				std::string line;
				while (getline(file, line)) {
					lstFile.push_back(line);
				}
				file.close();
			}
			throw std::runtime_error(fmt::format("File not found: {}\n", fileName));
		}

		void parseLstFile()
		{
			for (auto& line:lstFile) {
				std::smatch match;
				if (std::regex_match(line, match, lstRegex)) {
					// Index of the object in the vector is the instruction number
					LSTOpcodeInfo loi{};
					loi.lineInFile = stoi(match[3]);
					std::stringstream ss;
					ss << std::hex << match[2];
					ss >> loi.opcode;
					lstOcInfo.push_back(loi);
				}
			}
		}

	private:
		std::vector<std::string> lstFile;
		std::vector<LSTOpcodeInfo> lstOcInfo;
		std::regex lstRegex;
};
