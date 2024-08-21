#include <stdio.h>
#include <math.h>
#include <TXLib.h>
#include <assert.h>
//#include <cmath>

// enum

const int Exit_Success = 0;
const int Exit_Failure = 1;

const int Test_Success = 0;
const int Test_Failure = 1;

const int Many_Roots = -1;
const int One_Root = 1;
const int Two_Roots = 2;
const int No_Roots = 0;

const double EXP = 1e-10;

int SolveSquare(double a, double b, double c, double* x1, double* x2);

bool IsZero(double number);

void Input(double* a, double* b, double* c);
int Output(double x1, double x2, int nRoots);

int UnitTest(int nTest, double a, double b, double c, double x1right, double x2right, int nRootsRight);
int All_Tests();
// cppreference


int main()
{
    printf("It's a SolverSquare program\n");

    int result = All_Tests();

    if (result == Test_Failure)
    {
        printf("Error in tests");
        return Test_Failure;
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
int SolveSquare(double a, double b, double c, double* x1, double* x2)
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

int Output(double x1, double x2, int nRoots)
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
}

// функция тестирования

int UnitTest(int nTest, double a, double b, double c, double x1right, double x2right, int nRootsRight)
{
     double x1 = 0, x2 = 0;
     int nRoots = SolveSquare(a, b, c, &x1, &x2);
     if (nRoots != nRootsRight)
     {
        printf("ErrorTest%d: nRoots = %d\n"
                "Expected: nRoots = %d\n",
                nRoots, nRootsRight);
        return Test_Failure;
     }



     return Test_Success;
}

int xTest(int nTest, double a, double b, double c, int nRootsRight)
{
     double x1 = 0, x2 = 0;
     int nRoots = SolveSquare(a, b, c, &x1, &x2);
     if (nRoots != nRootsRight || x1 != x1right || x2 != x2right)
     {
        printf("ErrorTest%d: a = %lg, b = %lg, c = %lg, x1 = %lg, x2 = %lg, nRoots = %d\n"
                "Expected: x1 = %lg, x2 = %lg, nRoots = %d\n",
                nTest, a, b, c, x1, x2, nRoots,
                x1right, x2right, nRootsRight);
        return Test_Failure;
     }

     return Test_Success;
}


// под юнитест и ифами решить проблему порядка x

//решить проблему с порядком чисел
int All_Tests()
{
    int result = UnitTest(1, 1, -5, 4, 1, 4, 2);
    if (result == Test_Failure)
    {
        printf("Error in tests");
        return Test_Failure;
    }

    result = UnitTest(2, 1, 14, 45, -5, -9, 2);
    if (result == Test_Failure)
    {
        printf("Error in tests");
        return Test_Failure;
    }

    result = UnitTest(3, 1, 3, -70, 7, -10, 2);
    if (result == Test_Failure)
    {
        printf("Error in tests");
        return Test_Failure;
    }

    result = UnitTest(4, -3, -1, 14, -2.33333, 2, 2);
    if (result == Test_Failure)
    {
        printf("Error in tests");
        return Test_Failure;
    }

    result = UnitTest(5, 3, 4, 20, 0, 0, No_Roots);
    if (result == Test_Failure)
    {
        printf("Error in tests");
        return Test_Failure;
    }

    result = UnitTest(6, 4, 4, 1, -0.5, 0, 1);
    if (result == Test_Failure)
    {
        printf("Error in tests");
        return Test_Failure;
    }

    result = UnitTest(7, 0, 0, 0, 0, 0, Many_Roots);
    if (result == Test_Failure)
    {
        printf("Error in tests");
        return Test_Failure;
    }

    return Test_Success;
}

//Решалка_квадратки
//main{UnitTest() input() решалка_квдратки() вывод_корней()}
//1 0 0  -> 0
// 2 3 4  -> 2 4
// int Unit_Test {x1,x2; решалка_квадратки(1,0,0, &x1, &x2); x1 == 0 , x2 == 0;решалка_квадратки(2,3,4);x1 == 2, x4== 4}printf(Error %lf %lf %lf, trouble )
// 0 -good, 1 -bad return 0;
