#pragma once
#include <chrono>

class FrameTimer
{
public:
	FrameTimer();
	void Begin();
	float Mark();
private:
	std::chrono::steady_clock::time_point last;
};