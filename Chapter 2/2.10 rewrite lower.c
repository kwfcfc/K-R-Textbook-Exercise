#include <stdio.h>

/* Rewrite the function lower, which converts upper case letters to lower case,
   with a conditional expression instead of if-else. */
/* lower: convert c to lower case; ASCII only */
int lower(int character);

int main(){
  int c=getchar();
  printf("The input lower char is %c", lower(c));
}

int lower(int c){
  return c >= 'A' && c <= 'Z' ? c + 'a' - 'A': c;
}
