#include <stdio.h>
#include <math.h>
#include <TXLib.h>

int SolverSquare(double a, double b, double c, double* x1, double* x2)
{
    double D = 0;
    D = b * b - 4 * a * c;
    if (a == 0)
    {
        if (b == 0)
        {
            if(c == 0)
                return SS_Inf_Roots;
            else
                return 0;
        }
        else
        {
            *x1 = - c / b;
            return 1;
        }
    }
    else
    {
            if (D < 0)
                return 0;
            else if(D = 0)
            {
                *x1 = - b / (2 * a);
                return 1;
            }
            else
            {
                *x1 = (- b + sqrt(D)) / (2 * a);
                *x2 = (- b - sqrt(D)) / (2 * a);
                return 2;
            }
    }
}

int main(void)
{
     printf("Enter a, b, c:");

     double a = 0, b = 0, c = 0;
     scanf("%lg %lg %lg", &a, &b, &c);

     double x1 = 0, x2 = 0;
     int nRoots = SolverSquare(a, b, c, &x1, &x2);

     switch(nRoots)
     {
        case 0: printf("No roots\n");
                break;
        case 1: printf("x = %lg\n", x1);
                break;
        case 2: printf("x1 = %lg\n x2 = %lg\n", x1, x2);
                break;
        case SS_Inf_Roots: printf("Any numders\n");
                break;
        default: printf("main(): ERROR: nRoots = %d\n", nRoots);
                return 1;
      }
      return 0;
}
