#include <stdio.h>
#include <TXLib.h>
#include <math.h>
#include <assert.h>
#include "string.h"

#include "io.h"
#include "SolverSquare.h"
#include "Tests.h"


const char* test_str = "--test";


int main(const int argc, char* argv[])
{
    printf("It's a SolverSquare program\n");

    if (argc == 2 && strcmp(argv[1], test_str) == 0)
    {
        printf("Tests are performed\n");
        if (All_Tests() == AllTests_Failure)
        {
            printf("Error in tests");
            return AllTests_Failure;
        }
    }
    else
        printf("Tests were not performed\n");

    Coefficients coef = {0, 0, 0};

    Input(&coef);

    Roots res = {0, 0, 0};
    res.nRoots = SolveSquare(&coef, &res);

    Output(res);

    return Exit_Success;
}
