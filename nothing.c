#include <stdio.h>
#include <math.h>
#include <TXLib.h>
#include <assert.h>
//#include <cmath>

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

enum AllTest_Status
{
    AllTest_Success = 0,
    AllTest_Failure = 1,
};

enum Roots_Status
{
    Many_Roots = -1,
    One_Root = 1,
    Two_Roots = 2,
    No_Roots = 0,
};

const double EXP = 1e-10;

Roots_Status SolveSquare(double a, double b, double c, double* x1, double* x2);

bool IsZero(double number);

void Input(double* a, double* b, double* c);
Exit_Status Output(double x1, double x2, int nRoots);

Test_Status UnitTest(int nTest, double a, double b, double c, double x1right, double x2right, int nRootsRight);
AllTest_Status All_Tests();
// cppreference


int main()
{
    printf("It's a SolverSquare program\n");

    int result = All_Tests();

    if (result == AllTest_Failure)
    {
        printf("Error in tests");
        return AllTest_Failure;
    }

    double a = 0, b = 0, c = 0; // 0x100 0x200 0x300

    Input(&a, &b, &c);  // функция ввода
//                         return <значение>;
    //Testing program
    //Test(1, 2, 3);                        //Авто Тестирование на известных заранее наборах
    //Test(1, 0, 0);                        //Ручной ввод и вывод решений
    //Test(0, 2, 0);

    //решение входных данных
    double x1 = 0, x2 = 0;
    int nRoots = SolveSquare(a, b, c, &x1, &x2);    // функция решалки

    Output(x1, x2, nRoots); //функия вывода

    return Exit_Success;
}

 /*
void assert(bool expr)
{
   if (expr != true)
   {
     print LINE FILE
     abort()
   }

}   */

// решалка
Roots_Status SolveSquare(double a, double b, double c, double* x1, double* x2)
{                                        //NULL
    assert (isfinite(a));//NAN not a number
    assert (isfinite(b));
    assert (isfinite(c));

    assert (x1 != NULL);
    assert (x2 != NULL);
    assert (x1 != x2);

    double D = b * b - 4 * a * c;

    if (IsZero(a))
    {
        if (IsZero(b))
        {
            if (IsZero(c))
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
        else if (IsZero(D))
        {
            *x1 = -b / (2 * a);
            return One_Root;
        }
        else
        {
            double sqrt_D = sqrt(D);
            *x1 = (-b + sqrt_D) / (2 * a);
            *x2 = (-b - sqrt_D) / (2 * a);
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

void Input(double* ptr_a, double* ptr_b, double* ptr_c)
{

    printf("Enter a: ");
    scanf("%lg", ptr_a);

    printf("Enter b: ");
    scanf("%lg", ptr_b);

    printf("Enter c: ");
    scanf("%lg", ptr_c);
}

//функция вывода

Exit_Status Output(double x1, double x2, int nRoots)
{
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
        default: printf("main(): Error: nRoots = %d\n", nRoots);
                return Exit_Failure;
    }
    return Exit_Success;
}

// функция тестирования

Test_Status UnitTest(int nTest, double a, double b, double c, double x1right, double x2right, int nRootsRight)
{
    double x1 = 0, x2 = 0;
    int nRoots = SolveSquare(a, b, c, &x1, &x2);
    if (nRoots == nRootsRight)
    {
        if (IsZero(x1 - x1right) || x1 == x2right)
        {
            if (x2 == x2right || x2 == x1right)
                return Test_Success;
            else
            {
                printf("ErrorTest%d: x2 = %lg\nExpected: x2 = %lg or x2 = %lg\n",
                nTest, x2, x1right, x2right);
                return Test_Failure;
            }
        }
        else
        {
            printf("ErrorTest%d: x1 = %lg\nExpected: x1 = %lg or x1 = %lg\n",
            nTest, x1, x1right, x2right);
            return Test_Failure;
        }
    }
    else
    {
        printf("ErrorTest%d: nRoots = %d\nExpected: nRootsRight = %d\n",
        nTest, nRoots, nRootsRight);
        return Test_Failure;
    }
}
/* xTest
int xTest(int nTest, double a, double b, double c, double x1right, double x2right, int nRootsRight)
{
    double x1 = 0, x2 = 0;
    int nRoots = SolveSquare(a, b, c, &x1, &x2);
    if (x1 != x1right || x1 != x2right)
    {
        printf("ErrorTest%d: x1 = %lg"
                "Expected: x1 = %lg or x2 = %lg",
                x1, x1right, x2right);
        return Test_Failure;
    }
    if (x2 != x1right || x2 != x2right)
    {
        printf("ErrorTest%d: x2 = %lg"
                "Expected: x1 = %lg or x2 = %lg",
                x, x1right, x2right);
        return Test_Failure;
    }

    return Test_Success;
} */

// под юнитест и ифами решить проблему порядка x

//решить проблему с порядком чисел
AllTest_Status All_Tests()
{
    int result = UnitTest(1, 1, -5, 4, 1, 4, 2);
    if (result == Test_Failure)
        return AllTest_Failure;

    result = UnitTest(2, 1, 14, 45, -9, -5, 2);
    if (result == Test_Failure)
        return AllTest_Failure;

    result = UnitTest(3, 1, 3, -70, 7, -10, 2);
    if (result == Test_Failure)
        return AllTest_Failure;

    result = UnitTest(4, 5, -8, -4, -0.4, 2, 2);
    if (result == Test_Failure)
        return AllTest_Failure;

    result = UnitTest(5, 3, 4, 20, 0, 0, No_Roots);
    if (result == Test_Failure)
        return AllTest_Failure;

    result = UnitTest(6, 4, 4, 1, -0.5, 0, 1);
    if (result == Test_Failure)
        return AllTest_Failure;

    result = UnitTest(7, 0, 0, 0, 0, 0, Many_Roots);
    if (result == Test_Failure)
        return AllTest_Failure;

    return AllTest_Success;
}

//Решалка_квадратки
//main{UnitTest() input() решалка_квдратки() вывод_корней()}
//1 0 0  -> 0
// 2 3 4  -> 2 4
// int Unit_Test {x1,x2; решалка_квадратки(1,0,0, &x1, &x2); x1 == 0 , x2 == 0;решалка_квадратки(2,3,4);x1 == 2, x4== 4}printf(Error %lf %lf %lf, trouble )
// 0 -good, 1 -bad return 0;
