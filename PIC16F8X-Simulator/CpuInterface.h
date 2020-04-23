#pragma once

#include <string>

#include "CPU.h"

#include <thread>
#include "InstructionBase.h"

enum Registers : uint8_t
{
	Status = 0x03,
	Option = 0x81,
	Intcon = 0x0B,
	PortA = 0x5,
	PortB = 0x6,
	TrisA = 0x85,
	TrisB = 0x86,
	Pcl = 0x2,
	Pclath = 0xA
};


class CpuInterface
{
public:

	CpuInterface(int processorClock);

	const uint8_t& getRegister(Registers r) const;
	const uint8_t& getRegister(int address) const;
	const uint16_t& getProgramCounter() const;
	const uint16_t& getLineAtProgramCounter() const;
	const int& getCpuTime() const;
	int getW() const;
	const std::vector<std::string>& getLoadedFile() const;
	std::array<bool, 8> getRegisterBits(Registers r) const;
	std::array<bool, 8> getRegisterBits(uint8_t address) const;


	void setRegister(Registers r, uint8_t value) const;
	void setRegister(uint8_t address, uint8_t value) const;
	void setRegisterBit(Registers r, uint8_t bit, bool value) const;
	void setRegisterBit(uint8_t address, uint8_t bit, bool value) const;
	void setProcessorClock(int frequency);

	void resetCpuTime();
	void loadFile(const std::string& path);
	void resetProcessor();
	void runProcessor();
	void stopProcessor();
	void executeSingleInstruction();
private:
	CPU processor;
	RegisterData registers;
	LstParser parser;

	bool processorActive{ false };
	std::thread processorThread;

	int processorClock;
};

