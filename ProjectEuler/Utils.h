#pragma once
#ifndef _EULER_UTILS_H
#define _EULER_UTILS_H

#include "SharedDefines.h"

enum ConsoleColor
{
    BLACK               = 0x0,
    BLUE                = 0x1,
    GREEN               = 0x2,
    PURPLE              = 0x5,
    LIGHTBLUE           = 0x9,
    RED                 = 0xC,
    WHITE               = 0xF
};

class Utils
{
    private:
        Utils() { };
        ~Utils() { };

    public:
        static void SetConsoleColor(ConsoleColor command);
        static void Print(ConsoleColor color, const char* message, ...);
        static void Print(const char* message, ...);
};

#endif // _EULER_UTILS_H
