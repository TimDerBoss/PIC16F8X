#pragma once
#include "Executable.h"

#include <cstdint>
#include <string>

class RegisterData;

class ADDWF : public Executable
{
	public:
		ADDWF(const std::string& identifier, uint16_t mask, uint16_t value);

		void execute(RegisterData& rd, InstructionData& data) override;
};

class ANDWF : public Executable
{
	public:
		ANDWF(const std::string& identifier, uint16_t mask, uint16_t value);

		void execute(RegisterData& rd, InstructionData& data) override;
};

class CLRF : public Executable
{
	public:
		CLRF(const std::string& identifier, uint16_t mask, uint16_t value);

		void execute(RegisterData& rd, InstructionData& data) override;
};

class CLRW : public Executable
{
	public:
		CLRW(const std::string& identifier, uint16_t mask, uint16_t value);

		void execute(RegisterData& rd, InstructionData& data) override;
};

class COMF : public Executable
{
	public:
		COMF(const std::string& identifier, uint16_t mask, uint16_t value);

		void execute(RegisterData& rd, InstructionData& data) override;
};

class DECF : public Executable
{
	public:
		DECF(const std::string& identifier, uint16_t mask, uint16_t value);

		void execute(RegisterData& rd, InstructionData& data) override;
};

class DECFSZ : public Executable
{
	public:
		DECFSZ(const std::string& identifier, uint16_t mask, uint16_t value);

		void execute(RegisterData& rd, InstructionData& data) override;
};

class INCF : public Executable
{
	public:
		INCF(const std::string& identifier, uint16_t mask, uint16_t value);

		void execute(RegisterData& rd, InstructionData& data) override;
};

class INCFSZ : public Executable
{
	public:
		INCFSZ(const std::string& identifier, uint16_t mask, uint16_t value);

		void execute(RegisterData& rd, InstructionData& data) override;
};

class IORWF : public Executable
{
	public:
		IORWF(const std::string& identifier, uint16_t mask, uint16_t value);

		void execute(RegisterData& rd, InstructionData& data) override;
};

class MOVF : public Executable
{
	public:
		MOVF(const std::string& identifier, uint16_t mask, uint16_t value);

		void execute(RegisterData& rd, InstructionData& data) override;
};

class MOVWF : public Executable
{
	public:
		MOVWF(const std::string& identifier, uint16_t mask, uint16_t value);

		void execute(RegisterData& rd, InstructionData& data) override;
};

class NOP : public Executable
{
	public:
		NOP(const std::string& identifier, uint16_t mask, uint16_t value);

		void execute(RegisterData& rd, InstructionData& data) override;
};

class RLF : public Executable
{
	public:
		RLF(const std::string& identifier, uint16_t mask, uint16_t value);

		void execute(RegisterData& rd, InstructionData& data) override;
};

class RRF : public Executable
{
	public:
		RRF(const std::string& identifier, uint16_t mask, uint16_t value);

		void execute(RegisterData& rd, InstructionData& data) override;
};

class SUBWF : public Executable
{
	public:
		SUBWF(const std::string& identifier, uint16_t mask, uint16_t value);

		void execute(RegisterData& rd, InstructionData& data) override;
};

class SWAPF : public Executable
{
	public:
		SWAPF(const std::string& identifier, uint16_t mask, uint16_t value);

		void execute(RegisterData& rd, InstructionData& data) override;
};

class XORWF : public Executable
{
	public:
		XORWF(const std::string& identifier, uint16_t mask, uint16_t value);

		void execute(RegisterData& rd, InstructionData& data) override;
};

class BCF : public Executable
{
	public:
		BCF(const std::string& identifier, uint16_t mask, uint16_t value);

		void execute(RegisterData& rd, InstructionData& data) override;
};

class BSF : public Executable
{
	public:
		BSF(const std::string& identifier, uint16_t mask, uint16_t value);

		void execute(RegisterData& rd, InstructionData& data) override;
};

class BTFSC : public Executable
{
	public:
		BTFSC(const std::string& identifier, uint16_t mask, uint16_t value);

		void execute(RegisterData& rd, InstructionData& data) override;
};

class BTFSS : public Executable
{
	public:
		BTFSS(const std::string& identifier, uint16_t mask, uint16_t value);

		void execute(RegisterData& rd, InstructionData& data) override;
};

class ADDLW : public Executable
{
	public:
		ADDLW(const std::string& identifier, uint16_t mask, uint16_t value);

		void execute(RegisterData& rd, InstructionData& data) override;
};

class ANDLW : public Executable
{
	public:
		ANDLW(const std::string& identifier, uint16_t mask, uint16_t value);

		void execute(RegisterData& rd, InstructionData& data) override;
};

class CALL : public Executable
{
	public:
		CALL(const std::string& identifier, uint16_t mask, uint16_t value);

		void execute(RegisterData& rd, InstructionData& data) override;
};

class CLRWDT : public Executable
{
	public:
		CLRWDT(const std::string& identifier, uint16_t mask, uint16_t value);

		void execute(RegisterData& rd, InstructionData& data) override;
};

class GOTO : public Executable
{
	public:
		GOTO(const std::string& identifier, uint16_t mask, uint16_t value);

		void execute(RegisterData& rd, InstructionData& data) override;
};

class IORLW : public Executable
{
	public:
		IORLW(const std::string& identifier, uint16_t mask, uint16_t value);

		void execute(RegisterData& rd, InstructionData& data) override;
};

class MOVLW : public Executable
{
	public:
		MOVLW(const std::string& identifier, uint16_t mask, uint16_t value);

		void execute(RegisterData& rd, InstructionData& data) override;
};

class RETFIE : public Executable
{
	public:
		RETFIE(const std::string& identifier, uint16_t mask, uint16_t value);

		void execute(RegisterData& rd, InstructionData& data) override;
};

class RETLW : public Executable
{
	public:
		RETLW(const std::string& identifier, uint16_t mask, uint16_t value);

		void execute(RegisterData& rd, InstructionData& data) override;
};

class RETURN : public Executable
{
	public:
		RETURN(const std::string& identifier, uint16_t mask, uint16_t value);

		void execute(RegisterData& rd, InstructionData& data) override;
};

class SLEEP : public Executable
{
	public:
		SLEEP(const std::string& identifier, uint16_t mask, uint16_t value);

		void execute(RegisterData& rd, InstructionData& data) override;
};

class SUBLW : public Executable
{
	public:
		SUBLW(const std::string& identifier, uint16_t mask, uint16_t value);

		void execute(RegisterData& rd, InstructionData& data) override;
};

class XORLW : public Executable
{
	public:
		XORLW(const std::string& identifier, uint16_t mask, uint16_t value);

		void execute(RegisterData& rd, InstructionData& data) override;
};
