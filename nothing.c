#include <stdio.h>
#include <TXLib.h>
#include <math.h>
#include <assert.h>
#include <string.h>
//#include <cmath>

// README.md markdown

// struct
struct Coefficients
{
    double a, b, c;
};

struct Roots
{
    double x1, x2;
    int nRoots;
};

struct Test_Variables
{
    int nTest;
    Coefficients coef;
    Roots rootsRight;
};

// enum
enum Exit_Status
{
    Exit_Success = 0,
    Exit_Failure = 1,
};

enum Test_Status
{
    Test_Success = 0,
    Test_Failure = 1,
};

enum AllTests_Status
{
    AllTests_Success = 0,
    AllTests_Failure = 1,
};

enum Roots_Status
{
    Many_Roots = -1,
    One_Root = 1,
    Two_Roots = 2,
    No_Roots = 0,
};

const double EXP = 1e-10;
const char* test_str = "--test"; //"Run the test";


// functions

Roots_Status SolveSquare(Coefficients* coef, Roots* res);

void        Input(Coefficients* coef);
Exit_Status Output(Roots res);

AllTests_Status All_Tests();
Test_Status     UnitTest(Test_Variables* tVar);

bool IsZero(double number);

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

    Test_Variables tVar = {0, 0, 0, 0, 0, 0, 0};

    Input(&tVar.coef);  // функция ввода

    Roots res = {0, 0, 0};
    res.nRoots = SolveSquare(&tVar.coef, &res);   // функция решалки

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

//решалка с структурой
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

// bool
bool IsZero(double number)
{
    return (fabs(number - 0) < EXP);
}

// функция ввода
void Input(Coefficients* coef)
{
    assert (coef != 0);

    printf("Enter a: ");
    scanf("%lg", &(coef->a));

    printf("Enter b: ");
    scanf("%lg", &(coef->b));

    printf("Enter c: ");
    scanf("%lg", &(coef->c));
}

//функция вывода со структурой
Exit_Status Output(Roots res)
{
    switch(res.nRoots)
    {
        case No_Roots: printf("Answer: no roots\n");
                break;
        case One_Root: printf("Answer: x = %lg\n", res.x1);
                break;
        case Two_Roots: printf("Answer: x1 = %lg, x2 = %lg\n", res.x1, res.x2);
                break;
        case Many_Roots: printf("Answer: any numders\n");
                break;
        default: printf("main(): Error: nRoots = %d\n", res.nRoots);
                return Exit_Failure;
    }
    return Exit_Success;
}

// UnitTest
Test_Status UnitTest(Test_Variables* tVar)
{
    assert (tVar != 0);

    Roots res = {0, 0, 0};
    res.nRoots = SolveSquare(&(tVar->coef), &res);
    if (res.nRoots == tVar->rootsRight.nRoots)
    {
        if (IsZero(res.x1 - tVar->rootsRight.x1) || IsZero(res.x1 - tVar->rootsRight.x2))
        {
            if (IsZero(res.x2 - tVar->rootsRight.x2) || IsZero(res.x2 - tVar->rootsRight.x1))
                return Test_Success;
            else
            {
                printf("ErrorTest%d: x2 = %lg\nExpected: x2 = %lg or x2 = %lg\n",
                tVar->nTest, res.x2, tVar->rootsRight.x1, tVar->rootsRight.x2);
                return Test_Failure;
            }
        }
        else
        {
            printf("ErrorTest%d: x1 = %lg\nExpected: x1 = %lg or x1 = %lg\n",
            tVar->nTest, res.x1, tVar->rootsRight.x1, tVar->rootsRight.x2);
            return Test_Failure;
        }
    }
    else
    {
        printf("ErrorTest%d: nRoots = %d\nExpected: nRootsRight = %d\n",
        tVar->nTest, res.nRoots, tVar->rootsRight.nRoots);
        return Test_Failure;
    }
}

// Все тесты внутри
AllTests_Status All_Tests()
{
    Test_Variables Array_Of_Structures[] = {{1, 1, -5, 4, 1, 4, 2}, {2, 1, 14, 45, -9, -5, 2},
                                            {3, 1, 3, -70, 7, -10, 2}, {4, 5, -8, -4, -0.4, 2, 2},
                                            {5, 3, 4, 20, 0, 0, No_Roots}, {6, 4, 4, 1, -0.5, 0, 1},
                                            {7, 0, 0, 0, 0, 0, Many_Roots}, {8, 1, 5, 6, -3, -2, 2},
                                            {9, 1, 2, 1, -1, 0, 1}, {10, -3, -1, 14, -7.0/3, 2, 2}};

    size_t size = sizeof(Array_Of_Structures) / sizeof(Array_Of_Structures[0]);
    for (size_t i = 0; i < size; i++)
    {
        if (UnitTest(&Array_Of_Structures[i]) == Test_Failure)
            return AllTests_Failure;
    }

    return AllTests_Success;
}
