#include <stdio.h>
#include <TXLib.h>
#include <math.h>
#include <assert.h>
#include "string.h"

#include "io.h"
#include "SolverSquare.h"
#include "Tests.h"


// README.md markdown

// const
const char* test_str = "--test"; //"Run the test";


// cppreference

int main(int argc, char* argv[])
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

    Input(&coef);  // функция ввода

    Roots res = {0, 0, 0};
    res.nRoots = SolveSquare(&coef, &res);   // функция решалки

    Output(res); //функия вывода

    return Exit_Success;
}

/*struct Coeffs
{
    int a, b, c;
};

Coeffs coeffs = {1, 2, 3};
Coeffs* coeffs_p = &coeffs;

int* b_p = &(coeffs.b);
int* b_p = &(coeffs_p->b);
scanf("%d", &coeffs.b);

*coeffs_p = {1,2,3};
(*coeffs_p).b = 2;
coeffs_p->b = 2;   // !!!!!!

int a = 6;
int* p = &a;
//scanf("%d", &a);
int c = *p;
*p = 7;
double* x;

void assert(bool expr)
{
   if (expr != true)
   {
     print LINE FILE
     abort()
   }

}   */


/*int main()
{
    int a = 4;
    const int f = a;
    Test_Variables tv;
    foo(&tv);
}

int* f;
const int* ff;

*f = 9;
*ff =90; // нельзя const не изменяется

void foo(Test_Variables* arg)
{
    Test_Variables* arg = &tv;  // можно не писать, это подразумевается
    arg->coeffs.a = 5;

// ...
} */


