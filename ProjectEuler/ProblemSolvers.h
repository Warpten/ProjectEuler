#pragma once
#ifndef _EULER_PSOLVER_H
#define _EULER_PSOLVER_H

class ProblemSolvers
{
    public:
        ProblemSolvers() { };
        ~ProblemSolvers() { };

        template <class T> bool isPrime(T number);
        template <class T> bool isPalindrome(T number);
        template <class T> T getGreatestCommonDivider(T a, T b);
        template <class T> T getLeastCommonMultiple(T a, T b);

        void CallProblemHandler(unsigned int problemIndex);
        bool IsProblemHandled(unsigned int problemIndex);
        template <class T> void CheckIfValid(const T& sum, const T& expectedAnswer);

        void HandleProblem1(int expectedAnswer);
        void HandleProblem2(int expectedAnswer);
        void HandleProblem3(int expectedAnswer);
        void HandleProblem4(int expectedAnswer);
        void HandleProblem5(int expectedAnswer);
        void HandleProblem6(int expectedAnswer);
        void HandleProblem7(int expectedAnswer);
private:
        unsigned int _currentProblem;
};

#endif // _EULER_PSOLVER_H