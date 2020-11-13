#include "Watchdog.h"

#include "CPU.h"
#include "RegisterData.h"

Watchdog::Watchdog(CPU& cpu, RegisterData& registers)
	: registers(registers)
	, cpu(cpu)
	, active(false)
{
	this->cpu.onCpuTimeChanged.connect([this](double difference) {
		if (active)
		{
			bool preScaler = this->registers.readBit(0x81, 3);
			int prescaleValue = 1;
			if (preScaler)
			{
				prescaleValue <<= (this->registers.readByte(0x81) & 0x7);
			}

			// convert passed time to nanoseconds in order to store it in an int
			usPassed += difference;
			if (usPassed >= 18000 * prescaleValue) {
				this->registers.otherReset();
				this->registers.writeBit(0x3, 4, false);
				usPassed = 0;
			}
		}
		});
}

void Watchdog::start()
{
	active = true;
}

void Watchdog::stop()
{
	active = false;
	usPassed = 0;
}

void Watchdog::reset()
{
	usPassed = 0;
}
