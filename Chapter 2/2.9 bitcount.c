#include <stdio.h>
/* In a two's complement number system, x &= (x-1) deletes the rightmost 1-bit
   in x. Explain why. Use this observation to write a faster version of
   bitcount. */

int bitcount(unsigned bit);

int main(){
  unsigned x;

  printf("请输入一个整数：");
  scanf("%d", &x);

  printf("%o", bitcount(x));
}

int bitcount(unsigned x){
  int b;
  for (b = 0; x != 0; x &= x-1)
    b++;
  return b;
}
