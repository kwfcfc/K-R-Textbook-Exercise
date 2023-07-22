#include <stdio.h>
#define MAXCHAR 100

/* Write a loop equivalent to the for loop above without using && or ||. */
int main(){
  char s[MAXCHAR];
  for (i=0; (i<lim-1) * ((c=getchar()) != '\n') * (c != EOF); ++i)
    s[i] = c;
  printf("%s\n", s);
  return 0;
}
