#include <stdio.h>
#include "fact.h"

void fact(void)
{
    int num;
    int i;
    int result = 1;
    unsigned char dummy;
    fputs("Enter a number\n", stdout);
    scanf("%d", &num);
    fflush(stdin);
#if 0
    scanf("%c", &dummy);
#endif
    for (i = num; i > 0; i--)
    {
        result *= i;
    }
    printf("%d", result);
    printf("\n");
}