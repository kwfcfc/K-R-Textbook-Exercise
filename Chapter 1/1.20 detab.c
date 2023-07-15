#include <stdio.h>
#define TABINC 8
/* TABINC should be symbolic parameter
   N只是一个符号常量，因为不同终端和平台设置不同，
   N是确定的常量，不需要更改。应该根据不同的平台和
   终端宏定义
*/

int main(){
  int c, pos, j, interval;

  for (pos=1; (c=getchar()) != EOF ; ++pos){
    if (c == '\t'){
      --pos; // if we meet the tab, back off 1 step, where the pos - 1 is the position in front of \t
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

