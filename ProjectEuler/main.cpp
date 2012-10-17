#include "SharedDefines.h"
#include "Utils.h"
#include "ProblemSolvers.h"

int main()
{
    Utils::Print(GREEN, "[INFO] Welcome to EulerSolver 1.0 - By Warpten <vertozor@gmail.com>\n");
    Utils::Print(WHITE, "[INFO] Please enter a problem index for the program to solve it: ");

    unsigned int problemIndex = 0;
	std::cin >> problemIndex;

    ProblemSolvers* solvers = new ProblemSolvers();
    if (problemIndex == 0)
    {
        solvers->SetInTestSuite(true);
        solvers->SolveEverything();
        return 0;
    }

    if (solvers->IsProblemHandled(problemIndex))
    {
        Utils::Print(LIGHTBLUE, "[INFO] Solver found for problem #%u..\n", problemIndex);
        solvers->SetInTestSuite(false);
        solvers->CallProblemHandler(problemIndex);
    }
    else
        Utils::Print(RED, "[ERROR] Problem %u is currently not handled.\n", problemIndex);

    delete solvers;
    return 0;
}

