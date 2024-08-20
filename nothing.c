#include <stdio.h>
#include <math.h>
#include <TXLib.h>
#include <assert.h>
//#include <cmath>

// enum
const int Many_Roots = -1;
const int One_Root = 1;
const int Two_Roots = 2;
const int No_Roots = 0;

int SolveSquare(double a, double b, double c, double* answer1, double* answer2);

const double EXP = 1e-10;

bool IsZero(double number);

// cppreference

const int EXIT_SUCCESS = 0;
const int EXIT_FAILURE = 1;

int main()
{
    printf("It's a SolveSquare program\n");

    double a = 0, b = 0, c = 0;


// функция ввода

    double x1 = 0, x2 = 0;
    int nRoots = SolveSquare(a, b, c, &x1, &x2);

//функия вывода

    return EXIT_SUCCESS;
}


void assert(bool expr)
{
   if (expr != true)
   {
     print LINE FILE
     abort()
   }

}

int SolveSquare(double a, double b, double c, double* answer1, double* answer2)
{
    assert (isfinite(a));
    assert (isfinite(b));
    assert (isfinite(c));

    assert (answer1 != NULL);
    assert (answer2 != NULL);
    assert (answer1 != answer2);

    double D = b * b - 4 * a * c;

    if (IsZero(a, 0))
    {
        if (IsZero(b, 0))
        {
            if (IsZero(c, 0))
                return Many_Roots;
            else
                return No_Roots;
        }
        else
        {
            *answer1 = -c / b;
            return One_Root;
        }
    }
    else
    {
            if (D < 0)
                return No_Roots;
            else if (IsZero(D, 0))
            {
                *answer1 = -b / (2 * a);
                return One_Root;
            }
            else
            {
                double sqrt_D = sqrt(D);
                *answer1 = (-b + sqrt_D) / (2 * a);
                *answer2 = (-b - sqrt_D) / (2 * a);
                return Two_Roots;
            }
    }
}

// bool
bool IsZero(double number)
{
    return (fabs(number - 0) < EXP);
}

 // функция ввода

void Enter(double a, double b, double c)
{
    printf("Enter a: ");
    return a;

    printf("Enter b: ");
    scanf("%lg", &b);

    printf("Enter c: ");
    scanf("%lg", &c);
}

//функция вывода

Output
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
                return EXIT_FAILURE;
    }
