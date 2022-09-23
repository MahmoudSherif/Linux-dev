#include <stdio.h>
#include "fib.h"

void fib(void)
{
    int fibNum;
    int firstElement = 0;
    int secElement = 1;
    unsigned char dummy;
    fputs("Enter a number : ", stdout);
    scanf("%d", &fibNum);
    scanf("%c",&dummy);
    #if 0
    fflush(stdin);
    #endif
    for (int i = 0; i < fibNum; i++)
    {
        if (i % 2 == 0)
        {
            printf("%d ", firstElement);
            secElement = firstElement + secElement;
        }
        else if (i % 2 == 1)
        {
            printf("%d ", secElement);
            firstElement = firstElement + secElement;
        }
    }
    printf("\n");
}