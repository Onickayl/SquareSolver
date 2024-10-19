#ifndef TESTS
#define TESTS


#include <assert.h>
#include <stdio.h>

#include "struct.h"
#include "SolverSquare.h"

// struct

struct Test_Variables // TODO: rename
{
    int nTest;
    Coefficients coef;
    Roots rootsRight;
};

// enum
enum AllTests_Status
{
    AllTests_Success,
    AllTests_Failure,
};

AllTests_Status All_Tests();

#endif
