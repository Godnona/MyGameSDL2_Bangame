#include "Timer.h"

Timer::Timer()
{
	isPaused = false;
	isStarted = false;
}

Timer::~Timer()
{
}

void Timer::start()
{
	isStarted = true;
	isPaused = false;

	start_tick = std::chrono::steady_clock::now(); // get current time
	pause_duration = std::chrono::steady_clock::duration::zero();
}

void Timer::stop()
{
	isStarted = false;
	isPaused = false;
	pause_duration = std::chrono::steady_clock::duration::zero();
}

void Timer::pause()
{
	if (isStarted && !isPaused)
	{
		isPaused = true;
		auto now = std::chrono::steady_clock::now();
		pause_duration = now - start_tick;

	}
}

void Timer::unpause()
{
	if (isPaused)
	{
		isPaused = false;
		auto now = std::chrono::steady_clock::now();
		start_tick = now - pause_duration;
		pause_duration = std::chrono::steady_clock::duration::zero();
	}
}

int Timer::getTicks()
{
	if (isStarted)
	{
		if (isPaused)
		{
			return std::chrono::duration_cast<std::chrono::milliseconds>(pause_duration).count();
		}
		else
		{
			auto now = std::chrono::steady_clock::now();
			return std::chrono::duration_cast<std::chrono::milliseconds>(now - start_tick).count();
		}
	}
	return 0;
}

bool Timer::checkStarted()
{
	return isStarted;
}

bool Timer::checkPaused()
{
	return isPaused;
}
