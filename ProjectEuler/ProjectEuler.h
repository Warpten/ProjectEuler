#pragma once
#ifndef _EULER_PHANDLERS_H
#define _EULER_PHANDLERS_H

#include "ProblemSolvers.h"

struct ProblemHandler
{
    int problemIndex;
    unsigned long long expectedAnswer;
    bool (ProblemSolvers::*handler)();
};

unsigned int const MAX_PROBLEMS_HANDLED = 11;

ProblemHandler _problemSolvers[MAX_PROBLEMS_HANDLED] = {
    {   1, 233168,        &ProblemSolvers::HandleProblem1   },
    {   2, 4613732,       &ProblemSolvers::HandleProblem2   },
    {   3, 6857,          &ProblemSolvers::HandleProblem3   },
    {   4, 906609,        &ProblemSolvers::HandleProblem4   },
    {   5, 232792560,     &ProblemSolvers::HandleProblem5   },
    {   6, 25164150,      &ProblemSolvers::HandleProblem6   },
    {   7, 104743,        &ProblemSolvers::HandleProblem7   },
    {   8, 40824,         &ProblemSolvers::HandleProblem8   },
    {   9, 31875000,      &ProblemSolvers::HandleProblem9   },
    {  10, 142913828922,  &ProblemSolvers::HandleProblem10  },
    {  11, 70600674,      &ProblemSolvers::HandleProblem11  },
};

#endif // _EULER_PHANDLERS_H
