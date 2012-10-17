#ifndef _EULER_MATHUTILS
#define _EULER_MATHUTILS

#include "ProblemSolvers.h"

template <class T> T ProblemSolvers::getGreatestCommonDivider(T a, T b)
{
    T returnValue = 0;
    if (a > b) { // Swap back items
        T tempVal = a;
        a = b;
        b = tempVal;
    }

    while (returnValue = a % b) {
        a = b;
        b = returnValue;
    }
    return b;
}

template <class T> T ProblemSolvers::getLeastCommonMultiple(T a, T b)
{
    return T(a * b) / getGreatestCommonDivider<T>(a, b);
}

template <class T> bool ProblemSolvers::isPrime(T number)
{
    if (number <= 1)
        return false;

    if (number == 2)
        return true;
    
    T max = ceil(pow(number, 0.5));

    for (T itr = 2; itr <= number; ++itr)
        if (number % itr == 0)
            return false;
    return true;
}

template <class T> bool ProblemSolvers::isPalindrome(T number)
{
    T reversed = 0;
    T tempVar  = number;

    while (tempVar) {
        reversed = 10 * reversed + (tempVar % 10);
        tempVar /= 10;
    }

    return reversed == number;
}

template <class T> bool ProblemSolvers::isPythagoreanTriplet(T a, T b, T c)
{
    return ((a * a) + (b * b)) == (c * c);
}

#endif // _EULER_MATHUTILS
