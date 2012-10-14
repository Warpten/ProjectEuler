#pragma once
#ifndef _EULER_PHANDLERS_H
#define _EULER_PHANDLERS_H

#include "ProblemSolvers.h"

struct ProblemHandler
{
    int problemIndex;
    int expectedAnswer;
    void (ProblemSolvers::*handler)(int expectedAnswer);
};

unsigned int const MAX_PROBLEMS_HANDLED = 7;

ProblemHandler _problemSolvers[MAX_PROBLEMS_HANDLED] = {
    { 1, 233168,    &ProblemSolvers::HandleProblem1 },
    { 2, 4613732,   &ProblemSolvers::HandleProblem2 },
    { 3, 6857,      &ProblemSolvers::HandleProblem3 },
    { 4, 906609,    &ProblemSolvers::HandleProblem4 },
    { 5, 232792560, &ProblemSolvers::HandleProblem5 },
    { 6, 25164150,  &ProblemSolvers::HandleProblem6 },
    { 7, 104743,    &ProblemSolvers::HandleProblem7 },
};

#endif // _EULER_PHANDLERS_H
