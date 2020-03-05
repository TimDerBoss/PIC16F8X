//
// Created by tfa on 26.02.20.
//
#include "Instructions.h"
#include "InstructionHandler.h"
#include "RegisterData.h"

#include <FormatString.h>


#define ADD_INSTRUCTION(i, mask, value) std::make_shared<i>(#i, mask, value, rd)

InstructionHandler::InstructionHandler(RegisterData& rd)
{
	// Byte oriented operations
	instructions.emplace_back(ADD_INSTRUCTION(ADDWF, 0xFF00, 0x0700));
	instructions.emplace_back(ADD_INSTRUCTION(ANDWF, 0xFF00, 0x0500));
	instructions.emplace_back(ADD_INSTRUCTION(CLRF, 0xFF80, 0x0180));
	instructions.emplace_back(ADD_INSTRUCTION(CLRW, 0xFF80, 0x0100));
	instructions.emplace_back(ADD_INSTRUCTION(COMF, 0xFF00, 0x0900));
	instructions.emplace_back(ADD_INSTRUCTION(DECF, 0xFF00, 0x0300));
	instructions.emplace_back(ADD_INSTRUCTION(DECFSZ, 0xFF00, 0x0B00));
	instructions.emplace_back(ADD_INSTRUCTION(INCF, 0xFF00, 0x0A00));
	instructions.emplace_back(ADD_INSTRUCTION(INCFSZ, 0xFF00, 0x0F00));
	instructions.emplace_back(ADD_INSTRUCTION(IORWF, 0xFF00, 0x0400));
	instructions.emplace_back(ADD_INSTRUCTION(MOVF, 0xFF00, 0x0800));
	instructions.emplace_back(ADD_INSTRUCTION(MOVWF, 0xFF80, 0x0080));
	instructions.emplace_back(ADD_INSTRUCTION(NOP, 0xFF9F, 0x0000));
	instructions.emplace_back(ADD_INSTRUCTION(RLF, 0xFF00, 0x0D00));
	instructions.emplace_back(ADD_INSTRUCTION(RRF, 0xFF00, 0x0C00));
	instructions.emplace_back(ADD_INSTRUCTION(SUBWF, 0xFF00, 0x0200));
	instructions.emplace_back(ADD_INSTRUCTION(SWAPF, 0xFF00, 0x0E00));
	instructions.emplace_back(ADD_INSTRUCTION(XORWF, 0xFF00, 0x0600));

	// Bit oriented operations
	instructions.emplace_back(ADD_INSTRUCTION(BCF, 0xFC00, 0x1000));
	instructions.emplace_back(ADD_INSTRUCTION(BSF, 0xFC00, 0x1400));
	instructions.emplace_back(ADD_INSTRUCTION(BTFSC, 0xFC00, 0x1800));
	instructions.emplace_back(ADD_INSTRUCTION(BTFSS, 0xFC00, 0x1C00));

	// Literal and control operations
	instructions.emplace_back(ADD_INSTRUCTION(ADDLW, 0xFE00, 0x3E00));
	instructions.emplace_back(ADD_INSTRUCTION(ANDLW, 0xFF00, 0x3900));
	instructions.emplace_back(ADD_INSTRUCTION(CALL, 0xF800, 0x2000));
	instructions.emplace_back(ADD_INSTRUCTION(CLRWDT, 0xFFFF, 0x0064)); // TODO: implement me!
	instructions.emplace_back(ADD_INSTRUCTION(GOTO, 0xF800, 0x2800));
	instructions.emplace_back(ADD_INSTRUCTION(IORLW, 0xFF00, 0x3800));
	instructions.emplace_back(ADD_INSTRUCTION(MOVLW, 0xFC00, 0x3000));
	instructions.emplace_back(ADD_INSTRUCTION(RETFIE, 0xFFFF, 0x0009));
	instructions.emplace_back(ADD_INSTRUCTION(RETLW, 0xFC00, 0x3400));
	instructions.emplace_back(ADD_INSTRUCTION(RETURN, 0xFFFF, 0x0008));
	instructions.emplace_back(ADD_INSTRUCTION(SLEEP, 0xFFFF, 0x0063)); // TODO: implement me!
	instructions.emplace_back(ADD_INSTRUCTION(SUBLW, 0xFE00, 0x3C00));
	instructions.emplace_back(ADD_INSTRUCTION(XORLW, 0xFF00, 0x3A00));
}

InstructionData InstructionHandler::getInstructionData(const uint16_t& opcode)
{
	InstructionData data{};
	uint16_t commandType = opcode & 0xF000u;
	switch (commandType) {
	case 0x0000: // Byte oriented command
		data.d = opcode >> 0x7u & 0x1u;
		data.f = opcode & 0x007Fu;
		break;
	case 0x1000: // Bit oriented command
		data.b = opcode >> 0x7u & 0x7u;
		data.f = opcode & 0x007Fu;
		break;
	case 0x2000: // literal and control long address
		data.k = opcode & 0x07FFu;
		break;
	case 0x3000: // literal and control uint16_t address
		data.k = opcode & 0x00FFu;
		break;
	default:
		throw std::runtime_error(fmt::format("%s: Unknown instruction data type: 0x%X", __FUNCTION__, commandType));
	}
	return data;
}

std::shared_ptr<InstructionBase>& InstructionHandler::decode(const uint16_t& opcode)
{
	auto instruction = instructionCache.find(opcode);
	if (instruction != instructionCache.end()) {
		instruction->second->cacheData(getInstructionData(opcode));
		return instruction->second;
	}
	else {
		for (auto& i : instructions) {
			if (i->match(opcode)) {
				instructionCache[opcode] = i;
				i->cacheData(getInstructionData(opcode));
				return i;
			}
		}
		throw std::runtime_error(fmt::format("%s: Requested instruction is not implemented: 0x%X", __FUNCTION__, opcode));
	}
}
