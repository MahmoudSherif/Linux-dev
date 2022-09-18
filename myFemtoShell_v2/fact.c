#include <stdio.h> 
#include "fact.h"

void fact(void)
{
    int num;
    int i;
    int result=1;
    fputs("Enter a number\n",stdout);
    scanf("%d",&num);
    
    for (i = num; i >0; i--)
    {
        result *= i;
    }
    printf("%d",result);
    printf("\n");
    
}