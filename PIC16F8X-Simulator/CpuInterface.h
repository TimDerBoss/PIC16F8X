#pragma once

#include <string>

#include "CPU.h"

#include <thread>
#include "InstructionBase.h"
#include "Watchdog.h"

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
	const uint8_t& getRegister(uint8_t address) const;
	const uint16_t& getProgramCounter() const;
	const uint16_t& getLineAtProgramCounter() const;
	const double& getCpuTime() const;
	int getW() const;
	const std::vector<std::string>& getLoadedFile() const;
	std::array<bool, 8> getRegisterBits(Registers r) const;
	std::array<bool, 8> getRegisterBits(uint8_t address) const;
	Stack& getStack();

	void setRegister(Registers r, uint8_t value) const;
	void setRegister(uint8_t address, uint8_t value) const;
	void setRegisterBit(Registers r, uint8_t bit, bool value) const;
	void setRegisterBit(uint8_t address, uint8_t bit, bool value) const;
	void setProcessorClock(double frequency);

	void resetCpuTime();
	void loadFile(const std::string& path);
	void resetProcessor();
	void runProcessor();
	void stopProcessor();
	void executeSingleInstruction();
	void setWatchdogEnabled(bool enabled);
	void setBreakPointEnabled(bool enabled, int value);

	bool isInitialized();
	bool isProcessorActive();

private:
	CPU processor;
	RegisterData registers;
	LstParser parser;
	Watchdog watchdog;

	bool processorActive{ false };
	std::thread processorThread;

	double processorClock;
	bool initialized{ false };
	bool useBreakpoint{ false };
	int breakpointValue{ 0 };
};

