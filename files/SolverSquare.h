#ifndef SS
#define SS

#include <assert.h>
#include <math.h>
#include <stdio.h>

#include "struct.h"

enum Roots_Status
{
    Many_Roots,
    No_Roots,
    One_Root,
    Two_Roots,
};

const double EXP = 1e-10;

Roots_Status SolveSquare(Coefficients* coef, Roots* res);
bool IsZero(double number);

#endif
