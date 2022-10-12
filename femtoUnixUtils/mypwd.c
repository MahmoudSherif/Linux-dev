#include <unistd.h>
#include <stdio.h>

#define MAX_PATH 100

int main (void)
{
    char wd[MAX_PATH];
    getcwd(wd, MAX_PATH);
    puts(wd);

    return 0;
}