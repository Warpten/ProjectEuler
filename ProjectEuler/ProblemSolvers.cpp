#include "ProjectEuler.h"
#include "SharedDefines.h"
#include "Utils.h"
#include "MathUtils.cpp"

bool ProblemSolvers::IsProblemHandled(unsigned int problemIndex)
{
    for (unsigned int i = 0; i < MAX_PROBLEMS_HANDLED; ++i)
        if (_problemSolvers[i].problemIndex == problemIndex)
            return true;
    return false;
}

void ProblemSolvers::CallProblemHandler(unsigned int problemIndex)
{
   for (unsigned int i = 0; i < MAX_PROBLEMS_HANDLED; ++i)
   {
       if (_problemSolvers[i].problemIndex == problemIndex)
       {
            _currentProblem = problemIndex;
            (this->*_problemSolvers[i].handler)(_problemSolvers[i].expectedAnswer);
            break;
       }
   }
}

template <class T>
void ProblemSolvers::CheckIfValid(const T& sum, const T& expectedAnswer)
{
    Utils::Print(WHITE, "---------------------------------------\n");
    Utils::Print(sum == expectedAnswer ? GREEN : RED, "[INFO] Finished working on problem %lu.\n", _currentProblem);
    Utils::Print(sum == expectedAnswer ? GREEN : RED, "[RESULT] Expected result: %lu.\n", expectedAnswer);
    Utils::Print(sum == expectedAnswer ? GREEN : RED, "[RESULT] Result found: %lu.\n", sum);
    Utils::Print(WHITE, "---------------------------------------\n");
}

void ProblemSolvers::HandleProblem1(int expectedAnswer)
{
    int sum = 0;
    for (int i = 0; i < 1000; ++i)
    {
        if (i % 3 == 0)
            sum += i;
        if (i % 5 == 0)
            sum += i;
        if (i % 15 == 0) // To remove double-counted ones
            sum -= i;
    }
    
    CheckIfValid(sum, expectedAnswer);
}

void ProblemSolvers::HandleProblem2(int expectedAnswer)
{
    unsigned int firstFibo   = 1;
    unsigned int secondFibo  = 1;
    unsigned int thirdFibo   = 2;
    unsigned int sum = 0;

    while (thirdFibo < 4000000) {
        thirdFibo = firstFibo + secondFibo;
        if (thirdFibo % 2 == 0)
            sum += thirdFibo;
        firstFibo = secondFibo;
        secondFibo = thirdFibo;
    }
    
    CheckIfValid<unsigned int>(sum, expectedAnswer);
}

void ProblemSolvers::HandleProblem3(int expectedAnswer)
{
    unsigned long long sum = 600851475143ULL;
    for (unsigned long long i = 2ULL; i < sum; ++i)
        while (sum % i == 0)
            sum /= i;
    
    CheckIfValid<unsigned long long>(sum, expectedAnswer);
}

void ProblemSolvers::HandleProblem4(int expectedAnswer)
{
    unsigned int maxInteger = 0;

    for (unsigned int i = 1; i <= 999; ++i)
        for (unsigned int j = 1; j <= 999; ++j)
            if (isPalindrome(i * j) && (i * j) > maxInteger)
                maxInteger = i * j;

    CheckIfValid<unsigned int>(maxInteger, expectedAnswer);
}

void ProblemSolvers::HandleProblem5(int expectedAnswer)
{
    unsigned int leastCommonMultiplier = 1;
    for (unsigned int i = 2; i < 20; ++i)
        leastCommonMultiplier = getLeastCommonMultiple<unsigned int>(leastCommonMultiplier, i);

    CheckIfValid<unsigned int>(leastCommonMultiplier, expectedAnswer);
}

void ProblemSolvers::HandleProblem6(int expectedAnswer)
{
    // Sum (1 + ... + 100)²
    long sumToSquare = long((100 * 101 / 2) * (100 * 101 / 2));
    // Sum 1² + ... + 100²
    long squareSum = long(100 * 101 * (200 + 1) /6);

    CheckIfValid<long>(sumToSquare - squareSum, expectedAnswer);
}

void ProblemSolvers::HandleProblem7(int expectedAnswer)
{
    int last = 0;
    int count = 0;
    int primeIndex = 10001;
    for (int i = 3; count < primeIndex - 1; ++i)
    {
        if (i % 2 != 1)
            continue;
        int d = 3;
        int x = sqrt(double(i));
        while (i % d != 0 && d < x)
            d += 2;
        if (!(i % d == 0 && i != d))
        {
            last = i;
            count++;
        }
    }
    CheckIfValid<int>(last, expectedAnswer);
}