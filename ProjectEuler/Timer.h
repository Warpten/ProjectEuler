#ifndef HRTIMER_H
#define HRTIMER_H
 
#include <Windows.h>
#include <vector>
 
// Authors: Xeek & vsg1990 @irc.freenode.net#winapi
class Timer
{
public:
        Timer();
        ~Timer();
        void StopTimer();
        int StartTimer();
        double GetTotalElapsedTimeInMS();
 
private:
 
        static DWORD WINAPI Timing(LPVOID);
        bool mRunning;
        bool mBoolEnd;
        bool mGetTime;
        LARGE_INTEGER mFreq;
        LARGE_INTEGER mStart;
        LARGE_INTEGER mEnd;
        double mElapsedTime;
        HANDLE hThread;
};
 
#endif