#include "Utils.h"

void Utils::Print(ConsoleColor color, const char* message, ...)
{
    va_list val;
    char buffer[4096];
    va_start(val, message);
    vsnprintf(buffer, 4095, message, val);
    va_end(val);

    SetConsoleColor(color);
    printf(buffer);
}

void Utils::Print(const char* message, ...)
{
    va_list val;
    char buffer[4096];
    va_start(val, message);
    vsnprintf(buffer, 4095, message, val);
    va_end(val);

    printf(buffer);
}

void Utils::SetConsoleColor(ConsoleColor command)
{
    if (HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE))
        SetConsoleTextAttribute(consoleHandle, command);
}