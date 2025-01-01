#pragma once

#include "Data.h"

class Timer
{
public:
	Timer();
	~Timer();

	void start();
	void stop();
	void pause();
	void unpause();

	int getTicks();

	bool checkStarted();
	bool checkPaused();

private:

	std::chrono::steady_clock::time_point start_tick;
	std::chrono::steady_clock::duration pause_duration;

	bool isStarted;
	bool isPaused;


};
