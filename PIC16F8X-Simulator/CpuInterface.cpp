#include "CpuInterface.h"
#include "Exception.h"

#include <array>

CpuInterface::CpuInterface(int processorClock)
	: processorClock(processorClock)
	, processor(parser.getAllOpcodes())
{
}

const uint16_t& CpuInterface::getProgramCounter()
{
	return processor.getRegisters().getPc();
}

const uint16_t& CpuInterface::getLineAtProgramCounter()
{
	return parser.getLineInFile(processor.getRegisters().getPc());
}

const std::array<bool, 8> CpuInterface::getRegisterBits(Registers r)
{
	return processor.getRegisters().getRegisterBits(r);
}

const std::array<bool, 8> CpuInterface::getRegisterBits(uint8_t address)
{
	return processor.getRegisters().getRegisterBits(address);
}

Stack& CpuInterface::getStack()
{
	return processor.getRegisters().stack;
}

int CpuInterface::requestRegisterAccess(const Request::RequestData& request)
{
	return processor.getRegisters().applyRequest(request);
}

const double& CpuInterface::getCpuTime()
{
	return processor.getCpuTime();
}

int CpuInterface::getW()
{
	return processor.getRegisters().cpuRegisters.accumulator;
}

const std::vector<std::string>& CpuInterface::getLoadedFile() const
{
	return parser.getFile();
}

void CpuInterface::resetCpuTime()
{
	processor.setCpuTime(0);
}

void CpuInterface::setProcessorClock(double frequency)
{
	processorClock = frequency;
}

void CpuInterface::loadFile(const std::string& path)
{
	parser.readFile(path);
	parser.parseLstFile();
	initialized = true;
}

void CpuInterface::resetProcessor()
{
	processor.getRegisters().resetPowerOn();
	processor.getRegisters().cpuRegisters.accumulator = 0;
}

void CpuInterface::runProcessor()
{
	processor.start(processorClock);
}

void CpuInterface::stopProcessor()
{
	processor.stop();
}

void CpuInterface::executeSingleInstruction()
{
	processor.setClockSpeed(processorClock);
	if (parser.getLineInFile(processor.getRegisters().getPc()) != -1) {
		processor.singleStep(processor.getRegisters().getPc());
	}
}

void CpuInterface::setBreakPointEnabled(bool enabled, int value)
{
	processor.setBreakpoint(value);
	processor.enableBreakpoint(enabled);
}

void CpuInterface::setWatchdogEnabled(bool enabled)
{
	// TODO: watchdog
//	if (enabled)
//		processor.watchdog.start();
//	else
//		processor.watchdog.stop();
}

bool CpuInterface::isInitialized()
{
	return initialized;
}

bool CpuInterface::isProcessorActive()
{
	return processor.getProcessorActive();
}
