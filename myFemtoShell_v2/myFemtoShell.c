#include <stdio.h>
#include <string.h>
#include "myFemtoShell.h"
#include "rand.h"
#include "fact.h"

void myFemtoShell()
{
  const char exitString[] = "exit";
  const char randString[] = "rand";
  const char factString[] = "fact";
  const char promptString[] = "say any thing > ";
  char str[MAX];
  unsigned char exitFlag = 0;
  unsigned char strSize = 0;

  do
  {
    fputs(promptString, stdout);
    fgets(str, MAX, stdin);
    strSize = strlen(str);
    str[strSize - 1] = 0;
    exitFlag = strcasecmp(exitString, str);
    if (exitFlag != 0)
    {
      if (strcasecmp(randString, str) == 0)
      {
        randNum();
      }
      else if (strcasecmp(factString, str) == 0)
      {
        fact();
      }
      else
      {
        printf("ff");
        printf("You Said: ");
        fputs(str, stdout);
        printf("\n");
      }
    }

  } while (exitFlag != 0);
  fputs("GOOD BYE :)\n", stdout);
}
