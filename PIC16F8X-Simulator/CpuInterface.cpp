#include "CpuInterface.h"
#include "Exception.h"

#include <array>

CpuInterface::CpuInterface(int processorClock)
	: processorClock(processorClock)
	, processor(parser.getAllOpcodes())
{
}

const uint8_t& CpuInterface::getRegister(Registers r) const
{
	return processor.registers.readByte(r);
}

const uint8_t& CpuInterface::getRegister(uint8_t address) const
{
	return processor.registers.readByte(address);
}

const uint16_t& CpuInterface::getProgramCounter() const
{
	return processor.registers.getPc();
}

const uint16_t& CpuInterface::getLineAtProgramCounter() const
{
	return parser.getLineInFile(processor.registers.getPc());
}

const std::array<bool, 8> CpuInterface::getRegisterBits(Registers r) const
{
	return processor.registers.getRegisterBits(r);
}

const std::array<bool, 8> CpuInterface::getRegisterBits(uint8_t address) const
{
	return processor.registers.getRegisterBits(address);
}

Stack& CpuInterface::getStack()
{
	return processor.registers.stack;
}

const double& CpuInterface::getCpuTime() const
{
	return processor.timeActive;
}

int CpuInterface::getW() const
{
	return processor.registers.cpuRegisters.accumulator;
}

const std::vector<std::string>& CpuInterface::getLoadedFile() const
{
	return parser.getFile();
}

void CpuInterface::setRegister(Registers r, uint8_t value) const
{
	processor.registers.writeByte(r, value, DataSource::FromUser);
}

void CpuInterface::setRegister(uint8_t address, uint8_t value) const
{
	processor.registers.writeByte(address, value, DataSource::FromUser);
}

void CpuInterface::setRegisterBit(Registers r, uint8_t bit, bool value) const
{
	processor.registers.writeBit(r, bit, value, DataSource::FromUser);
}

void CpuInterface::setRegisterBit(uint8_t address, uint8_t bit, bool value) const
{
	processor.registers.writeBit(address, bit, value, DataSource::FromUser);
}

void CpuInterface::resetCpuTime()
{
	processor.timeActive = 0;
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
	processor.registers.resetPowerOn();
	processor.registers.cpuRegisters.accumulator = 0;
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
	processor.clockSpeed = processorClock;
	if (parser.getLineInFile(processor.registers.getPc()) != -1) {
		processor.singleStep(processor.registers.getPc());
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
	return processor.processorActive;
}
