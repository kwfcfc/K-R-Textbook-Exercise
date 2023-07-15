#include <stdio.h>
#define IN 1 /* inside a word */
#define OUT 0 /* outside a word */
#define UPPER 12

//统计单词长度1-10的，长度超过10的成为一组。
//list[0] as counter, list[UPPER-1] as the last group which
//word length is greater than UPPER-2
int main(){
  int c, state, height;
  int i, j; // count variable 计数变量
  int nwdigit[UPPER]; // nwdigit[0] as number of word count
  
  for (i = 0; i < UPPER; ++i)
    nwdigit[i] = 0;
  state = OUT;

  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\n' || c == '\t') {
      if ( state == IN ){
        if (nwdigit[0] > 10){
          ++nwdigit[UPPER];
          nwdigit[0] = 0;
        }
        else if (nwdigit[0] > 0){
          ++nwdigit[nwdigit[0]];
          nwdigit[0] = 0;
        }
      }
      state = OUT;
    }
    else if (state == OUT) {
      state = IN;
    }
    if (state == IN)
      ++nwdigit[0];
  }

  // 打印水平直方图 horizontal 📊
  for ( j = 1; j < UPPER -1 ; ++j){
    printf("%d ", j);
    for ( i = 0; i < nwdigit[j]; ++i)
      printf("*");
    putchar('\n');
  }
  printf(">10 ");
  //printf("%d", nwdigit[UPPER]);
  for ( i = 0; i < nwdigit[UPPER]; ++i)
    printf("*");
  putchar('\n');

  // 打印垂直直方图 vertical
  height = nwdigit[1]; // find the height by sorting 
  for ( i = 2; i < UPPER; ++i){
    if (nwdigit[i] > height)
      height = nwdigit[i];
  }
  //printf("height is %d\n", height);
  for ( i = height; i > 0; --i){
    for (j = 1; j < UPPER + 1 ; j++){
      if (nwdigit[j] >= i)
        printf("*  ");
      else
        printf("   ");
    }
    putchar('\n');
  }
  for ( i = 1; i < UPPER -1; ++i)
    printf("%d  ", i);
  printf(">%d", UPPER-1-1);
}

/*
  test set
suiiiw w1390s jjjjjjjj   a iiowkjl
wios 22euio zxc er rt yui jjsiodxcvncxzv osntu    xcnltop
c e f pascal turing   sudf   fudan
peking 🏓
abcfdefjs kksuioq84h azoxifhhgu
jjsiodxcvncxz
*/

