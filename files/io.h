#ifndef IO
#define IO

#include <assert.h>
#include <stdio.h>

#include "struct.h"
#include "SolverSquare.h"

enum Exit_Status
{
    Exit_Success,
    Exit_Failure,
};

void        Input(Coefficients* coef);
Exit_Status Output(Roots res);

#endif
