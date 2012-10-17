#include "ProjectEuler.h"
#include "SharedDefines.h"
#include "Utils.h"
#include "MathUtils.cpp"
#include <time.h>
#include "Timer.h"
#include <iomanip>

bool ProblemSolvers::IsProblemHandled(unsigned int problemIndex)
{
    for (unsigned int i = 0; i < MAX_PROBLEMS_HANDLED; ++i)
        if (_problemSolvers[i].problemIndex == problemIndex)
            return true;
    return false;
}

void ProblemSolvers::CallProblemHandler(unsigned int problemIndex)
{
    _currentProblem = problemIndex;
    Timer* problemTimer = new Timer();
    problemTimer->StartTimer();
    Sleep(5);
    for (unsigned int i = 0; i < MAX_PROBLEMS_HANDLED; ++i)
    {
        if (_problemSolvers[i].problemIndex == problemIndex)
        {
            double oldTime = problemTimer->GetTotalElapsedTimeInMS();
            bool isValid = (this->*_problemSolvers[i].handler)();
            double newTime = problemTimer->GetTotalElapsedTimeInMS();
            double executionTime = newTime - oldTime;

            if (!_isInTestSuite)
            {
                Utils::SetConsoleColor(LIGHTBLUE);
                std::cout << "[INFO] Problem #" << _problemSolvers[i].problemIndex << " solved in " << executionTime << " nanoseconds.";
                if (isValid)
                    Utils::Print(GREEN, " Correct solution!\n");
                else
                    Utils::Print(RED, " Incorrect solution!\n");
            }
            break;
        }
    }
    problemTimer->StopTimer();
    delete problemTimer; // GTFO leaks
}

void ProblemSolvers::SolveEverything()
{
    Utils::Print(RED, "[WARNING] Testing suite started. Loading all %u testers.\n", MAX_PROBLEMS_HANDLED);
    Timer* problemTimer = new Timer();
    problemTimer->StartTimer();
    Sleep(5); //Make sure timer is warmed up.
    double oldTime = 0;
    double newTime = 0;
    for (unsigned int i = 0; i < MAX_PROBLEMS_HANDLED; ++i)
    {
        _currentProblem = _problemSolvers[i].problemIndex;
        // Benchmark
        oldTime = problemTimer->GetTotalElapsedTimeInMS();
        bool isValid = (this->*_problemSolvers[i].handler)();
        newTime = problemTimer->GetTotalElapsedTimeInMS();
        double executionTime = newTime - oldTime;
        
        // Log output
        Utils::SetConsoleColor(LIGHTBLUE);
        std::cout << "[INFO] Problem #" << std::setw(3) << _currentProblem << " solved in " << executionTime << " nanoseconds.";
        if (isValid)
            Utils::Print(GREEN, " Correct solution! ");
        else
            Utils::Print(RED, " Incorrect solution! ");
        std::cout << "(" << _problemSolvers[i].expectedAnswer << ")" << std::endl;
    }
    problemTimer->StopTimer();
    delete problemTimer; // GTFO leaks
}

template <class T>
bool ProblemSolvers::CheckIfValid(const T& sum)
{
    unsigned long long expectedAnswer = _problemSolvers[_currentProblem - 1].expectedAnswer; // Meh ? Y U -1
    if (!_isInTestSuite)
    {
        Utils::Print(sum == expectedAnswer ? GREEN : RED, "[RESULT] Result found: ");
        std::cout << sum << "." << std::endl;
    }
    return expectedAnswer == sum;
}

bool ProblemSolvers::HandleProblem1()
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
    
    return CheckIfValid(sum);
}

bool ProblemSolvers::HandleProblem2()
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
    
    return CheckIfValid<unsigned int>(sum);
}

bool ProblemSolvers::HandleProblem3()
{
    unsigned long long sum = 600851475143ULL;
    for (unsigned long long i = 2ULL; i < sum; ++i)
        while (sum % i == 0)
            sum /= i;
    
    return CheckIfValid<unsigned long long>(sum);
}

bool ProblemSolvers::HandleProblem4()
{
    unsigned int maxInteger = 0;

    for (unsigned int i = 1; i <= 999; ++i)
        for (unsigned int j = 1; j <= 999; ++j)
            if (isPalindrome(i * j) && (i * j) > maxInteger)
                maxInteger = i * j;

    return CheckIfValid<unsigned int>(maxInteger);
}

bool ProblemSolvers::HandleProblem5()
{
    unsigned int leastCommonMultiplier = 1;
    for (unsigned int i = 2; i < 20; ++i)
        leastCommonMultiplier = getLeastCommonMultiple<unsigned int>(leastCommonMultiplier, i);

    return CheckIfValid<unsigned int>(leastCommonMultiplier);
}

bool ProblemSolvers::HandleProblem6()
{
    // Sum (1 + ... + 100)²
    long sumToSquare = long((100 * 101 / 2) * (100 * 101 / 2));
    // Sum 1² + ... + 100²
    long squareSum = long(100 * 101 * (200 + 1) /6);

    return CheckIfValid<long>(sumToSquare - squareSum);
}

bool ProblemSolvers::HandleProblem7()
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
    return CheckIfValid<int>(last);
}

bool ProblemSolvers::HandleProblem8()
{
    std::string bigNumber = "73167176531330624919225119674426574742355349194934";
    bigNumber.append("96983520312774506326239578318016984801869478851843");
    bigNumber.append("85861560789112949495459501737958331952853208805511");
    bigNumber.append("12540698747158523863050715693290963295227443043557");
    bigNumber.append("66896648950445244523161731856403098711121722383113");
    bigNumber.append("62229893423380308135336276614282806444486645238749");
    bigNumber.append("30358907296290491560440772390713810515859307960866");
    bigNumber.append("70172427121883998797908792274921901699720888093776");
    bigNumber.append("65727333001053367881220235421809751254540594752243");
    bigNumber.append("52584907711670556013604839586446706324415722155397");
    bigNumber.append("53697817977846174064955149290862569321978468622482");
    bigNumber.append("83972241375657056057490261407972968652414535100474");
    bigNumber.append("82166370484403199890008895243450658541227588666881");
    bigNumber.append("16427171479924442928230863465674813919123162824586");
    bigNumber.append("17866458359124566529476545682848912883142607690042");
    bigNumber.append("24219022671055626321111109370544217506941658960408");
    bigNumber.append("07198403850962455444362981230987879927244284909188");
    bigNumber.append("84580156166097919133875499200524063689912560717606");
    bigNumber.append("05886116467109405077541002256983155200055935729725");
    bigNumber.append("71636269561882670428252483600823257530420752963450");

    unsigned int greatestProduct = 0;
    for (unsigned int i = 0; i < 1000 - 5; ++i) // 63450 is the last valid 5-digits product - just stop at the 6
    {
        unsigned int product = 1;
        std::string const& chunk = bigNumber.substr(i, 5);
        for (unsigned int j = 0; j < 5; ++j)
            product *= chunk[j] - '0';

        if (product > greatestProduct)
            greatestProduct = product;
    }

    return CheckIfValid<unsigned int>(greatestProduct);
}

bool ProblemSolvers::HandleProblem9()
{
    unsigned int answer = 1;
    unsigned int a = 0;
    unsigned int b = 1;
    unsigned int c = 999;
    unsigned int tempC = 999;
    bool foundTriple = false;
    while (!foundTriple)
    {
        // Going backwards to find a collision
        c = --tempC;
        b = 1;
        while (b < c)
        {
            a = 1000 - c - b;
            if (isPythagoreanTriplet(a, b, c))
            {
                foundTriple = true;
                answer = a * b * c;
                break;
            }
            --c;
            ++b;
        }
    }

    return CheckIfValid<unsigned int>(answer);
}

bool ProblemSolvers::HandleProblem10()
{
    // Not gonna push that shit, worst impl ever.
    return CheckIfValid(0);
}

bool ProblemSolvers::HandleProblem11()
{
    // This is bruteforcing, aka bad, use matrix operations ffs
    unsigned int numberStore[20][20] = {
        { 8,  2, 22, 97, 38, 15,  0, 40,  0, 75,  4,  5,  7, 78, 52, 12, 50, 77, 91,  8}, 
        {49, 49, 99, 40, 17, 81, 18, 57, 60, 87, 17, 40, 98, 43, 69, 48,  4, 56, 62,  0}, 
        {81, 49, 31, 73, 55, 79, 14, 29, 93, 71, 40, 67, 53, 88, 30,  3, 49, 13, 36, 65}, 
        {52, 70, 95, 23,  4, 60, 11, 42, 69, 24, 68, 56,  1, 32, 56, 71, 37,  2, 36, 91}, 
        {22, 31, 16, 71, 51, 67, 63, 89, 41, 92, 36, 54, 22, 40, 40, 28, 66, 33, 13, 80}, 
        {24, 47, 32, 60, 99,  3, 45,  2, 44, 75, 33, 53, 78, 36, 84, 20, 35, 17, 12, 50}, 
        {32, 98, 81, 28, 64, 23, 67, 10, 26, 38, 40, 67, 59, 54, 70, 66, 18, 38, 64, 70}, 
        {67, 26, 20, 68,  2, 62, 12, 20, 95, 63, 94, 39, 63,  8, 40, 91, 66, 49, 94, 21}, 
        {24, 55, 58,  5, 66, 73, 99, 26, 97, 17, 78, 78, 96, 83, 14, 88, 34, 89, 63, 72}, 
        {21, 36, 23,  9, 75,  0, 76, 44, 20, 45, 35, 14,  0, 61, 33, 97, 34, 31, 33, 95}, 
        {78, 17, 53, 28, 22, 75, 31, 67, 15, 94,  3, 80,  4, 62, 16, 14,  9, 53, 56, 92}, 
        {16, 39,  5, 42, 96, 35, 31, 47, 55, 58, 88, 24,  0, 17, 54, 24, 36, 29, 85, 57}, 
        {86, 56,  0, 48, 35, 71, 89,  7,  5, 44, 44, 37, 44, 60, 21, 58, 51, 54, 17, 58}, 
        {19, 80, 81, 68,  5, 94, 47, 69, 28, 73, 92, 13, 86, 52, 17, 77,  4, 89, 55, 40}, 
        { 4, 52,  8, 83, 97, 35, 99, 16,  7, 97, 57, 32, 16, 26, 26, 79, 33, 27, 98, 66}, 
        {88, 36, 68, 87, 57, 62, 20, 72,  3, 46, 33, 67, 46, 55, 12, 32, 63, 93, 53, 69}, 
        {04, 42, 16, 73, 38, 25, 39, 11, 24, 94, 72, 18,  8, 46, 29, 32, 40, 62, 76, 36}, 
        {20, 69, 36, 41, 72, 30, 23, 88, 34, 62, 99, 69, 82, 67, 59, 85, 74,  4, 36, 16}, 
        {20, 73, 35, 29, 78, 31, 90,  1, 74, 31, 49, 71, 48, 86, 81, 16, 23, 57,  5, 54}, 
        { 1, 70, 54, 71, 83, 51, 54, 69, 16, 92, 33, 48, 61, 43, 52,  1, 89, 19, 67, 48}, 
    };
    // Done loading, meh
    unsigned int highestProduct = 0;

    for (unsigned int i = 0; i < 20; ++i)
    {
        // Read lines
        for (unsigned int j = 0; j < 17; ++j)
            if (unsigned int newProduct = (numberStore[i][j] * numberStore[i][j + 1] * numberStore[i][j + 2] * numberStore[i][j + 3]))
                if (newProduct > highestProduct)
                    highestProduct = newProduct;
    }

    for (unsigned int i = 0; i < 17; ++i)
    {
        // Read columns
        for (unsigned int j = 0; j < 17; ++j)
            if (unsigned int newProduct = (numberStore[i][j] * numberStore[i + 1][j] * numberStore[i + 2][j] * numberStore[i + 3][j]))
                if (newProduct > highestProduct)
                    highestProduct = newProduct;

        // Read diagonal
        // 1 0
        // 0 1
        for (unsigned int j = 0; j < 17; ++j)
            if (unsigned int newProduct = (numberStore[i][j] * numberStore[i + 1][j + 1] * numberStore[i + 2][j + 2] * numberStore[i + 1][j + 3]))
                if (newProduct > highestProduct)
                    highestProduct = newProduct;
    }

    // Read diagonal
    // 0 1
    // 1 0
    for (unsigned int i = 0; i < 17; ++i)
        for (unsigned int j = 20; j > 3; --j)
            if (unsigned int newProduct = (numberStore[i][j] * numberStore[i + 1][j - 1] * numberStore[i + 2][j - 2] * numberStore[i + 3][j - 3]))
                if (newProduct > highestProduct)
                    highestProduct = newProduct;

    return CheckIfValid<unsigned int>(highestProduct);

}