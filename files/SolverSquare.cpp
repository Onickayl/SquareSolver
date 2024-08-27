//решалка с структурой
#include "SolverSquare.h"

// решалка
Roots_Status SolveSquare(Coefficients* coef, Roots* res)
{
    assert (coef != NULL);
    assert (isfinite(coef->a));
    assert (isfinite(coef->b));
    assert (isfinite(coef->c));

    assert (res != NULL);
    assert (&(res->x1) != NULL);
    assert (&(res->x2) != NULL);
    assert (&(res->x1) != &(res->x2));

    double D = coef->b * coef->b - 4 * coef->a * coef->c;

    if (IsZero(coef->a))
    {
        if (IsZero(coef->b))
        {
            if (IsZero(coef->c))
                return Many_Roots;
            else
                return No_Roots;
        }
        else
        {
            res->x1 = -coef->c / coef->b;
            return One_Root;
        }
    }
    else
    {
        if (D < 0)
            return No_Roots;
        else if (IsZero(D))
        {
            res->x1 = -coef->b / (2 * coef->a);
            return One_Root;
        }
        else
        {
            double sqrt_D = sqrt(D);
            res->x1 = (-coef->b + sqrt_D) / (2 * coef->a);
            res->x2 = (-coef->b - sqrt_D) / (2 * coef->a);
            return Two_Roots;
        }
    }
}

// сравнение с нулём
bool IsZero(double number)
{
    return (fabs(number - 0) < EXP);
}
