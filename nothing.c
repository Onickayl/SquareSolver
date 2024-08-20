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
            if (c == 0)
                return -1;
            else
                return 0;
        }
        else
        {
            *x1 = -c / b;
            return 1;
        }
    }
    else
    {
            if (D < 0)
                return 0;
            else if (D == 0)
            {
                *x1 = -b / (2 * a);
                return 1;
            }
            else
            {
                *x1 = (-b + sqrt(D)) / (2 * a);
                *x2 = (-b - sqrt(D)) / (2 * a);
                return 2;
            }
    }
}

int main(void)
{
    printf("It's a SolverSquare program\n");

    double a = 0, b = 0, c = 0;
    printf("Enter a: ");
    scanf("%lg", &a);
    printf("Enter b: ");
    scanf("%lg", &b);
    printf("Enter c: ");
    scanf("%lg", &c);


    double x1 = 0, x2 = 0;
    int nRoots = SolverSquare(a, b, c, &x1, &x2);

    switch(nRoots)
    {
        case 0: printf("Answer: no roots\n");
                break;
        case 1: printf("Answer: x = %lg\n", x1);
                break;
        case 2: printf("Answer: x1 = %lg, x2 = %lg\n", x1, x2);
                break;
        case -1: printf("Answer: any numders\n");
                break;
        default: printf("main(): ERROR: nRoots = %d\n", nRoots);
                return 1;
    }
    return 0;
}
