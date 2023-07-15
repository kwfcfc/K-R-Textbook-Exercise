#include <stdio.h>

int main(){
  int c, blank;
  blank = -1;

  while ( (c = getchar()) != EOF){
    if (( blank != ' ') || (blank  != c))
      putchar(blank);
    blank = c;
  }
}
