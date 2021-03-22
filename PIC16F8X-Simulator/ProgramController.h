#pragma once

#include <string>

#include "CPU.h"

#include <thread>
#include "Executable.h"
#include "Watchdog.h"


class ProgramController
{
public:
	ProgramController(int processorClock);

	const uint16_t& getProgramCounter();
	const uint16_t& getLineAtProgramCounter();
	const double& getCpuTime();
	int getW();
	const std::vector<std::string>& getLoadedFile() const;
	const std::array<bool, 8> getRegisterBits(Registers r);
	const std::array<bool, 8> getRegisterBits(uint8_t address);
	Stack& getStack();

	int requestRegisterAccess(const Request::RequestData& request);

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
	LstParser parser;

	double processorClock;
	bool initialized{ false };
};

