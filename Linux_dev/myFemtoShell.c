#include <stdio.h>
#include <string.h>

#define MAX   100
int main()
{
  const char exitString[]="exit";
  const char promptString[]="say any thing > ";
  char str[MAX];
  fputs(promptString,stdout);
  while(strncasecmp(exitString,fgets(str,MAX,stdin),4) != 0) 
  {
    printf("You Said: ");
    fputs(str,stdout);
    fputs(promptString,stdout);
  }
  printf("Good Bye :)\n");
  return 0;
}