#include "Tests.h"

enum Test_Status
{
    Test_Success = 0,
    Test_Failure = 1,
};

static Test_Status UnitTest(Test_Variables* tVar);

// UnitTest
AllTests_Status All_Tests()
{
    // TODO: add const
    Test_Variables Array_Of_Structures[] = {
        {1, 1, -5,   4,  1,   4, Two_Roots},    { 2,  1, 14, 45, -9,    -5, Two_Roots},
        {3, 1,  3, -70,  7, -10, Two_Roots},    { 4,  5, -8, -4, -0.4,   2, Two_Roots},
        {5, 3,  4,  20,  0,   0, No_Roots},     { 6,  4,  4,  1, -0.5,   0, One_Root},
        {7, 0,  0,   0,  0,   0, Many_Roots},   { 8,  1,  5,  6, -3,    -2, Two_Roots},
        {9, 1,  2,   1, -1,   0, One_Root},     {10, -3, -1, 14, -7.0/3, 2, Two_Roots}};

    size_t size = sizeof(Array_Of_Structures) / sizeof(Array_Of_Structures[0]);
    for (size_t i = 0; i < size; i++)
    {
        if (UnitTest(&Array_Of_Structures[i]) == Test_Failure) // TODO: run all test
            return AllTests_Failure;
    }

    return AllTests_Success;
}

// TODO: add const
Test_Status UnitTest(const Test_Variables* tVar)
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

