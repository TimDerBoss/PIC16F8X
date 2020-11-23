#pragma once

#include "LSTParser.h"
#include "RegisterData.h"
#include "InstructionHandler.h"

#include <cstdint>
#include <string>

enum class InterruptType : int
{
	None,
	Timer0,
	PortB0,
	PortB47
};

class CPU
{
public:
	CPU(const std::vector<LstOpcodeInfo>& lstOpcodeInfo);

	void start(double clockSpeed);
	void stop();
	void singleStep(int programCounter);
	void setBreakpoint(int address);
	void enableBreakpoint(bool enable);

	bool globalInterruptsEnabled();
	bool portBLowInterruptEnabled();
	bool portBHighInterruptEnabled();
	bool timerInterruptEnabled();
	bool timerInterruptFlagSet();
	
	int getCpuTime();
	bool getProcessorActive();
	RegisterData& getRegisters();

	void setCpuTime(int time);
	void setClockSpeed(double speed);

	boost::signals2::signal<void(double difference)> onCpuTimeChanged;

private:
	InterruptType detectInterrupt();
	void jumpToInterruptRoutine();
	void enableGlobalInterrupts(bool enable);
	void processTimerInterrupt(int cyclesPassed);
	void processPortInterrupts();
	void setFlagINTF();
	void setFlagRBIF();

	void processBreakpoint();
	int executeInstruction(int programCounter);


	double timeActive{ 0 };
	bool processorActive{ false };
	bool breakpointEnabled{ false };
	int breakpointAddress = 0;
	std::thread processorThread;
	double clockSpeed{ 0 };
	int cycles{ 0 };
	RegisterData registers;
	// TODO: watchdog
	// Watchdog watchdog;
	InstructionHandler instructionHandler;
};
