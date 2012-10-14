#include "SharedDefines.h"
#include "Utils.h"
#include "ProblemSolvers.h"

int main()
{
    Utils::Print(GREEN, "[INFO] Welcome to EulerSolver 1.0 - By Warpten <vertozor@gmail.com>\n");
    Utils::Print(WHITE, "[INFO] Please enter a problem index for the program to solve it: ");

    unsigned int problemIndex = 0;
	std::cin >> problemIndex;

    if (problemIndex == 0)
    {
        Utils::Print(RED, "[ERROR] No problem selected. Exiting\n");
        return 0;
    }

    ProblemSolvers* solvers = new ProblemSolvers();
    if (solvers->IsProblemHandled(problemIndex))
    {
        Utils::Print(LIGHTBLUE, "[INFO] Problem solver found, solving the problem...\n");
        solvers->CallProblemHandler(problemIndex);
    }
    else
        Utils::Print(RED, "[ERROR] Problem %u is currently not handled.\n", problemIndex);

    delete solvers;
    return 0;
}

