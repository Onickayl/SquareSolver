#include "io.h"


void Input_Coefficients(Coefficients* coef)
{
    assert (coef != 0);

    printf("Enter a: ");
    scanf("%lg", &(coef->a));  // TODO: check error, scanf (помимо >=0)

    printf("Enter b: ");
    scanf("%lg", &(coef->b));

    printf("Enter c: ");
    scanf("%lg", &(coef->c));
}



Exit_Status Output_Results(Roots res)
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

        // TODO: прочитай о stderr, stdout, fprintf(stderr, ....)
        default: printf("main(): Error: nRoots = %d\n", res.nRoots);
                return Exit_Failure;
    }
    return Exit_Success;
}
