#include <stdio.h>
#include <stdlib.h>
#include "parse.h"

void repl();

int main()
{
   repl();
  return 0;
}


void repl()
{
  int result = 1;
  char buf[255];
  printf("This is calc. please type formula.\n==>");
  result = scanf("%s",buf);
  while(result == 1)
  {
    printf("Answer: %d\n",parse(buf));
    printf("\n==>");
    result = scanf("%s",buf);
  }
  printf("Bye\n");
}


