// Tests

#include "Tests.h"

enum Test_Status
{
    Test_Success = 0,
    Test_Failure = 1,
};

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
