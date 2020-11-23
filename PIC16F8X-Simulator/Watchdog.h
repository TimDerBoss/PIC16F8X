#pragma once
// STL
#include <thread>

// BOOST
#include <boost/signals2/signal.hpp>


class Watchdog
{
public:
	Watchdog(class CPU& cpu, class RegisterData& registers);

	void start();
	void stop();
	void reset();

private:
	bool active{ true };
	double usPassed{ 0 };
	class CPU& cpu;
	class RegisterData& registers;
};

