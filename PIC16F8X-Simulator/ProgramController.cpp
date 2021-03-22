#include "ProgramController.h"
#include "Exception.h"

#include <array>

ProgramController::ProgramController(int processorClock)
	: processorClock(processorClock)
	, processor(parser.getAllOpcodes())
{
}

const uint16_t& ProgramController::getProgramCounter()
{
	return processor.getRegisters().getPc();
}

const uint16_t& ProgramController::getLineAtProgramCounter()
{
	return parser.getLineInFile(processor.getRegisters().getPc());
}

const std::array<bool, 8> ProgramController::getRegisterBits(Registers r)
{
	return processor.getRegisters().getRegisterBits(r);
}

const std::array<bool, 8> ProgramController::getRegisterBits(uint8_t address)
{
	return processor.getRegisters().getRegisterBits(address);
}

Stack& ProgramController::getStack()
{
	return processor.getRegisters().stack;
}

int ProgramController::requestRegisterAccess(const Request::RequestData& request)
{
	return processor.getRegisters().applyRequest(request);
}

const double& ProgramController::getCpuTime()
{
	return processor.getCpuTime();
}

int ProgramController::getW()
{
	return processor.getRegisters().cpuRegisters.accumulator;
}

const std::vector<std::string>& ProgramController::getLoadedFile() const
{
	return parser.getFile();
}

void ProgramController::resetCpuTime()
{
	processor.setCpuTime(0);
}

void ProgramController::setProcessorClock(double frequency)
{
	processorClock = frequency;
}

void ProgramController::loadFile(const std::string& path)
{
	parser.readFile(path);
	parser.parseLstFile();
	initialized = true;
}

void ProgramController::resetProcessor()
{
	processor.getRegisters().resetPowerOn();
	processor.getRegisters().cpuRegisters.accumulator = 0;
}

void ProgramController::runProcessor()
{
	processor.start(processorClock);
}

void ProgramController::stopProcessor()
{
	processor.stop();
}

void ProgramController::executeSingleInstruction()
{
	processor.setClockSpeed(processorClock);
	if (parser.getLineInFile(processor.getRegisters().getPc()) != -1) {
		processor.singleStep(processor.getRegisters().getPc());
	}
}

void ProgramController::setBreakPointEnabled(bool enabled, int value)
{
	processor.setBreakpoint(value);
	processor.enableBreakpoint(enabled);
}

void ProgramController::setWatchdogEnabled(bool enabled)
{
	// TODO: watchdog
//	if (enabled)
//		processor.watchdog.start();
//	else
//		processor.watchdog.stop();
}

bool ProgramController::isInitialized()
{
	return initialized;
}

bool ProgramController::isProcessorActive()
{
	return processor.getProcessorActive();
}
