#ifndef _EULER_PSOLVER_H
#define _EULER_PSOLVER_H

#include "SharedDefines.h"

class ProblemSolvers
{
    public:
        ProblemSolvers(){ }
        ~ProblemSolvers() { }

        // Math tools
        template <class T> bool isPrime(T number);
        template <class T> bool isPalindrome(T number);
        template <class T> T getGreatestCommonDivider(T a, T b);
        template <class T> T getLeastCommonMultiple(T a, T b);
        template <class T> bool isPythagoreanTriplet(T a, T b, T c);

        void CallProblemHandler(unsigned int problemIndex);
        bool IsProblemHandled(unsigned int problemIndex);
        template <class T> bool CheckIfValid(const T& sum);

        void SetInTestSuite(bool enable) { _isInTestSuite = enable; }

        void SolveEverything();

        // Problem handlers
        bool HandleProblem1();
        bool HandleProblem2();
        bool HandleProblem3();
        bool HandleProblem4();
        bool HandleProblem5();
        bool HandleProblem6();
        bool HandleProblem7();
        bool HandleProblem8();
        bool HandleProblem9();
        bool HandleProblem10();
        bool HandleProblem11();

    private:
        unsigned int _currentProblem;
        bool _isInTestSuite;
};

#endif // _EULER_PSOLVER_H