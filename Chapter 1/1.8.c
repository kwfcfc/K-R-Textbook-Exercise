#include <stdio.h>

int main(){
  int c, nbc;

  nbc = 0;
  
  while ( (c = getchar()) != EOF){
    if ( (c == ' ') || (c == '\n') || (c == '\t') )
      ++nbc;
  }
  printf("%d\n", nbc);
}
