#include "Timer.h"

Timer::Timer()
{
	mRunning = false;
	mBoolEnd = false;
	mGetTime = false;
	mStart.QuadPart = 0;
	mEnd.QuadPart = 0;
	mFreq.QuadPart = 0;
	mElapsedTime = 0;
	hThread = NULL;
}

Timer::~Timer()
{
	StopTimer();
}

DWORD WINAPI Timer::Timing(LPVOID lpParam)
{
	Timer* self = (Timer*)lpParam;
	QueryPerformanceFrequency(&self->mFreq);
	QueryPerformanceCounter(&self->mStart);
	self->mGetTime = true;
	while (!self->mBoolEnd)
	{
		QueryPerformanceCounter(&self->mEnd);
	}
	
	self->mBoolEnd = false;
	return 0;
}

int Timer::StartTimer()
{
	if (!mRunning)
	{
		hThread = CreateThread(NULL, 0, Timer::Timing, this, 0, NULL);
		SetThreadAffinityMask(hThread, 1);
		mRunning = true;
		return 0;
	}
	return 1;
}

void Timer::StopTimer()
{
	mBoolEnd = true;
	WaitForSingleObject(hThread, INFINITE);
	mRunning = false;
	CloseHandle(hThread);
	hThread = NULL;
}

double Timer::GetTotalElapsedTimeInMS()
{
	while(!mGetTime);
	while(mGetTime)
	{
		mElapsedTime = ((mEnd.QuadPart - mStart.QuadPart) * 1000.0f * 1000.0f / mFreq.QuadPart);
		return mElapsedTime;
	}
	return 0;
}