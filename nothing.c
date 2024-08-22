#include <stdio.h>
#include <math.h>
#include <TXLib.h>
#include <assert.h>
//#include <cmath>

// struct
struct Test_Variables
{
    int nTest;
    double x1right, x2right;
    int nRootsRight;
};

struct Coefficients
{
    double a, b, c;
};

struct Roots
{
    double x1, x2;
    int nRoots;
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

const double EXP = 1e-5;


// functions
//Roots_Status SolveSquare(double a, double b, double c, double* x1, double* x2);
Roots_Status SolveSquare(Coefficients coef, Roots* res);

bool IsZero(double number);

//void Input(double* a, double* b, double* c);
//Exit_Status Output(double x1, double x2, int nRoots);

void Input(Coefficients* coef);
Exit_Status Output(Roots res);

//Test_Status UnitTest(int nTest, double a, double b, double c, double x1right, double x2right, int nRootsRight);
AllTest_Status All_Tests();

Test_Status UnitTest(Test_Variables tVar);

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

    Coefficients coef; // 0x100 0x200 0x300

    Input(&coef);  // функция ввода
//                         return <значение>;
    //Testing program
    //Test(1, 2, 3);                        //Авто Тестирование на известных заранее наборах
    //Test(1, 0, 0);                        //Ручной ввод и вывод решений
    //Test(0, 2, 0);

    //решение входных данных
    //double x1 = 0, x2 = 0;

    Roots res;
    res.nRoots = SolveSquare(coef, &res);   // функция решалки

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
/*Roots_Status SolveSquare(double a, double b, double c, double* x1, double* x2)
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
}  */

//решлака с структурой  доделать красный квадрат
Roots_Status SolveSquare(Coefficients coef, Roots* res)
{
    assert (isfinite(coef.a));
    assert (isfinite(coef.b));
    assert (isfinite(coef.c));

    assert (res->x1 != NULL);
    assert (res->x2 != NULL);
    assert (res->x1 != res->x2);

    double D = coef.b * coef.b - 4 * coef.a * coef.c;

    if (IsZero(coef.a))
    {
        if (IsZero(coef.b))
        {
            if (IsZero(coef.c))
                return Many_Roots;
            else
                return No_Roots;
        }
        else
        {
            res->x1 = -coef.c / coef.b;
            return One_Root;
        }
    }
    else
    {
        if (D < 0)
            return No_Roots;
        else if (IsZero(D))
        {
            res->x1 = -coef.b / (2 * coef.a);
            return One_Root;
        }
        else
        {
            double sqrt_D = sqrt(D);
            res->x1 = (-coef.b + sqrt_D) / (2 * coef.a);
            res->x2 = (-coef.b - sqrt_D) / (2 * coef.a);
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

/*void Input(double* ptr_a, double* ptr_b, double* ptr_c)
{

    printf("Enter a: ");
    scanf("%lg", ptr_a);

    printf("Enter b: ");
    scanf("%lg", ptr_b);

    printf("Enter c: ");
    scanf("%lg", ptr_c);
} */

// функция ввода со структурой
void Input(Coefficients* coef)
{

    printf("Enter a: ");
    scanf("%lg", &(coef->a));

    printf("Enter b: ");
    scanf("%lg", &(coef->b));

    printf("Enter c: ");
    scanf("%lg", &(coef->c));
}


//функция вывода
/*Exit_Status Output(double x1, double x2, int nRoots)
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
} */

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

// функция тестирования

/*Test_Status UnitTest(int nTest, double a, double b, double c, double x1right, double x2right, int nRootsRight)
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
}*/

// UnitTest с структурой
Test_Status UnitTest(Test_Variables tVar, Coefficients coef)
{
    double x1 = 0, x2 = 0;
    int nRoots = SolveSquare(coef.a, coef.b, coef.c, &x1, &x2);
    if (nRoots == tVar.nRootsRight)
    {
        if (IsZero(x1 - tVar.x1right) || IsZero(x1 - tVar.x2right))
        {
            if (IsZero(x2 - tVar.x2right) || IsZero(x2 - tVar.x1right))
                return Test_Success;
            else
            {
                printf("ErrorTest%d: x2 = %lg\nExpected: x2 = %lg or x2 = %lg\n",
                tVar.nTest, x2, tVar.x1right, tVar.x2right);
                return Test_Failure;
            }
        }
        else
        {
            printf("ErrorTest%d: x1 = %lg\nExpected: x1 = %lg or x1 = %lg\n",
            tVar.nTest, x1, tVar.x1right, tVar.x2right);
            return Test_Failure;
        }
    }
    else
    {
        printf("ErrorTest%d: nRoots = %d\nExpected: nRootsRight = %d\n",
        tVar.nTest, nRoots, tVar.nRootsRight);
        return Test_Failure;
    }
}

// Все тесты внутри
AllTest_Status All_Tests()
{
    Test_Variables Array_Of_Structures[] = {{1, 1, -5, 4, 1, 4, 2},
                                            {2, 1, 14, 45, -9, -5, 2},
                                            {3, 1, 3, -70, 7, -10, 2},
                                            {4, 5, -8, -4, -0.4, 2, 2},
                                            {5, 3, 4, 20, 0, 0, No_Roots},
                                            {6, 4, 4, 1, -0.5, 0, 1},
                                            {7, 0, 0, 0, 0, 0, Many_Roots}}

    for (int i = 0, i < sizeof(Array_Of_Structures) / sizeof(Array_Of_Structures[0]), i++)
    {
        if (UnitTest(Array_Of_Structures[i] == Test_Failure)
            return AllTest_Failure
    }

    return AllTest_Success;
}


//Решалка_квадратки
//main{UnitTest() input() решалка_квдратки() вывод_корней()}
//1 0 0  -> 0
// 2 3 4  -> 2 4
// int Unit_Test {x1,x2; решалка_квадратки(1,0,0, &x1, &x2); x1 == 0 , x2 == 0;решалка_квадратки(2,3,4);x1 == 2, x4== 4}printf(Error %lf %lf %lf, trouble )
// 0 -good, 1 -bad return 0;
