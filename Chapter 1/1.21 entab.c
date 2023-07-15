#include <stdio.h>
#define TABINC 8
/* when either a tab or a single blank would suffice to reach a tab stop, I
   prefer to use blank, because a blank is always one character width.
 */

int main(){
  int c, pos, j, interval;

  for (pos=1; (c=getchar()) != EOF ; ++pos){
    if (c == '\t'){
      --pos;
      // if we meet the tab, back off 1 step, where the pos - 1 is the position
      // in front of \t
      interval = TABINC - pos % TABINC;
      //printf("%d", interval);
      for (j=0; j < interval; ++j)
        putchar(' ');
      pos += interval;
    }else if (c == '\n'){
      putchar('\n');
      pos = 0;      
    }
    else
      putchar(c);
  }
  return 0;
}
