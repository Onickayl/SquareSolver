#include <stdio.h>
#include <math.h>
#include <TXLib.h>

//решить проблему с предупреждениями, числа с плавующей запятой, погрешность

const int Many_Roots = -1;
const int One_Root = 1;
const int Two_Roots = 2;
const int No_Roots = 0;

int SolveSquare(double a, double b, double c, double* x1, double* x2);

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
    int nRoots = SolveSquare(a, b, c, &x1, &x2);

    switch(nRoots)
    {
        case No_Roots: printf("Answer: no roots\n");
                break;
        case One_Root: printf("Answer: x = %lg\n", x1);
                break;
        case Two_Roots: printf("Answer: x1 = %lg, x2 = %lg\n", x1, x2);
                break;
        case Many_Roots: printf("Answer: any numders\n");
                break;
        default: printf("main(): ERROR: nRoots = %d\n", nRoots);
                return 1;
    }
    return 0;
}

int SolveSquare(double a, double b, double c, double* x1, double* x2)
{
    double D = 0;
    D = b * b - 4 * a * c;
    if (a == 0)
    {
        if (b == 0)
        {
            if (c == 0)
                return Many_Roots;
            else
                return No_Roots;
        }
        else
        {
            *x1 = -c / b;
            return One_Root;
        }
    }
    else
    {
            if (D < 0)
                return No_Roots;
            else if (D == 0)
            {
                *x1 = -b / (2 * a);
                return One_Root;
            }
            else
            {
                *x1 = (-b + sqrt(D)) / (2 * a);
                *x2 = (-b - sqrt(D)) / (2 * a);
                return Two_Roots;
            }
    }
}
