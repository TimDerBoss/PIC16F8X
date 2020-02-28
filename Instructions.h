#pragma once
#include "InstructionBase.h"
#include <cstdint>
#include <string>

class RegisterData;

class ADDWF : public InstructionBase
{
	public:
		ADDWF(const std::string& identifier, uint16_t mask, uint16_t value, RegisterData& rd);

		void execute(const uint16_t& opcode) override;
};

class ANDWF : public InstructionBase
{
	public:
		ANDWF(const std::string& identifier, uint16_t mask, uint16_t value, RegisterData& rd);

		void execute(const uint16_t& opcode) override;
};

class CLRF : public InstructionBase
{
	public:
		CLRF(const std::string& identifier, uint16_t mask, uint16_t value, RegisterData& rd);

		void execute(const uint16_t& opcode) override;
};

class CLRW : public InstructionBase
{
	public:
		CLRW(const std::string& identifier, uint16_t mask, uint16_t value, RegisterData& rd);

		void execute(const uint16_t& opcode) override;
};

class COMF : public InstructionBase
{
	public:
		COMF(const std::string& identifier, uint16_t mask, uint16_t value, RegisterData& rd);

		void execute(const uint16_t& opcode) override;
};

class DECF : public InstructionBase
{
	public:
		DECF(const std::string& identifier, uint16_t mask, uint16_t value, RegisterData& rd);

		void execute(const uint16_t& opcode) override;
};

class DECFSZ : public InstructionBase
{
	public:
		DECFSZ(const std::string& identifier, uint16_t mask, uint16_t value, RegisterData& rd);

		void execute(const uint16_t& opcode) override;
};

class INCF : public InstructionBase
{
	public:
		INCF(const std::string& identifier, uint16_t mask, uint16_t value, RegisterData& rd);

		void execute(const uint16_t& opcode) override;
};

class INCFSZ : public InstructionBase
{
	public:
		INCFSZ(const std::string& identifier, uint16_t mask, uint16_t value, RegisterData& rd);

		void execute(const uint16_t& opcode) override;
};

class IORWF : public InstructionBase
{
	public:
		IORWF(const std::string& identifier, uint16_t mask, uint16_t value, RegisterData& rd);

		void execute(const uint16_t& opcode) override;
};

class MOVF : public InstructionBase
{
	public:
		MOVF(const std::string& identifier, uint16_t mask, uint16_t value, RegisterData& rd);

		void execute(const uint16_t& opcode) override;
};

class MOVWF : public InstructionBase
{
	public:
		MOVWF(const std::string& identifier, uint16_t mask, uint16_t value, RegisterData& rd);

		void execute(const uint16_t& opcode) override;
};

class NOP : public InstructionBase
{
	public:
		NOP(const std::string& identifier, uint16_t mask, uint16_t value, RegisterData& rd);

		void execute(const uint16_t& opcode) override;
};

class RLF : public InstructionBase
{
	public:
		RLF(const std::string& identifier, uint16_t mask, uint16_t value, RegisterData& rd);

		void execute(const uint16_t& opcode) override;
};

class RRF : public InstructionBase
{
	public:
		RRF(const std::string& identifier, uint16_t mask, uint16_t value, RegisterData& rd);

		void execute(const uint16_t& opcode) override;
};

class SUBWF : public InstructionBase
{
	public:
		SUBWF(const std::string& identifier, uint16_t mask, uint16_t value, RegisterData& rd);

		void execute(const uint16_t& opcode) override;
};

class SWAPF : public InstructionBase
{
	public:
		SWAPF(const std::string& identifier, uint16_t mask, uint16_t value, RegisterData& rd);

		void execute(const uint16_t& opcode) override;
};

class XORWF : public InstructionBase
{
	public:
		XORWF(const std::string& identifier, uint16_t mask, uint16_t value, RegisterData& rd);

		void execute(const uint16_t& opcode) override;
};

class BCF : public InstructionBase
{
	public:
		BCF(const std::string& identifier, uint16_t mask, uint16_t value, RegisterData& rd);

		void execute(const uint16_t& opcode) override;
};

class BSF : public InstructionBase
{
	public:
		BSF(const std::string& identifier, uint16_t mask, uint16_t value, RegisterData& rd);

		void execute(const uint16_t& opcode) override;
};

class BTFSC : public InstructionBase
{
	public:
		BTFSC(const std::string& identifier, uint16_t mask, uint16_t value, RegisterData& rd);

		void execute(const uint16_t& opcode) override;
};

class BTFSS : public InstructionBase
{
	public:
		BTFSS(const std::string& identifier, uint16_t mask, uint16_t value, RegisterData& rd);

		void execute(const uint16_t& opcode) override;
};

class ADDLW : public InstructionBase
{
	public:
		ADDLW(const std::string& identifier, uint16_t mask, uint16_t value, RegisterData& rd);

		void execute(const uint16_t& opcode) override;
};

class ANDLW : public InstructionBase
{
	public:
		ANDLW(const std::string& identifier, uint16_t mask, uint16_t value, RegisterData& rd);

		void execute(const uint16_t& opcode) override;
};

class CALL : public InstructionBase
{
	public:
		CALL(const std::string& identifier, uint16_t mask, uint16_t value, RegisterData& rd);

		void execute(const uint16_t& opcode) override;
};

class CLRWDT : public InstructionBase
{
	public:
		CLRWDT(const std::string& identifier, uint16_t mask, uint16_t value, RegisterData& rd);

		void execute(const uint16_t& opcode) override;
};

class GOTO : public InstructionBase
{
	public:
		GOTO(const std::string& identifier, uint16_t mask, uint16_t value, RegisterData& rd);

		void execute(const uint16_t& opcode) override;
};

class IORLW : public InstructionBase
{
	public:
		IORLW(const std::string& identifier, uint16_t mask, uint16_t value, RegisterData& rd);

		void execute(const uint16_t& opcode) override;
};

class MOVLW : public InstructionBase
{
	public:
		MOVLW(const std::string& identifier, uint16_t mask, uint16_t value, RegisterData& rd);

		void execute(const uint16_t& opcode) override;
};

class RETFIE : public InstructionBase
{
	public:
		RETFIE(const std::string& identifier, uint16_t mask, uint16_t value, RegisterData& rd);

		void execute(const uint16_t& opcode) override;
};

class RETLW : public InstructionBase
{
	public:
		RETLW(const std::string& identifier, uint16_t mask, uint16_t value, RegisterData& rd);

		void execute(const uint16_t& opcode) override;
};

class RETURN : public InstructionBase
{
	public:
		RETURN(const std::string& identifier, uint16_t mask, uint16_t value, RegisterData& rd);

		void execute(const uint16_t& opcode) override;
};

class SLEEP : public InstructionBase
{
	public:
		SLEEP(const std::string& identifier, uint16_t mask, uint16_t value, RegisterData& rd);

		void execute(const uint16_t& opcode) override;
};

class SUBLW : public InstructionBase
{
	public:
		SUBLW(const std::string& identifier, uint16_t mask, uint16_t value, RegisterData& rd);

		void execute(const uint16_t& opcode) override;
};

class XORLW : public InstructionBase
{
	public:
		XORLW(const std::string& identifier, uint16_t mask, uint16_t value, RegisterData& rd);

		void execute(const uint16_t& opcode) override;
};
