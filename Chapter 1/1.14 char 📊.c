#include <stdio.h>

//only count printable
int main(){
  int c, height;
  const int charset = '~' - ' ' + 1;
  int i, j; // count variable 计数变量
  int ncdigit[charset]; // ncdigit[0] as number of word count
  
  for (i = 0; i < charset; ++i)
    ncdigit[i] = 0;

  while ((c = getchar()) != EOF){
    if ((' ' <= c) && (c <= '~')) //test if printable
      ++ncdigit[c-' ']; 
  }

  // 打印水平直方图 horizontal 📊
  for ( j = 0; j < charset ; ++j){
    printf("%c ", j + ' ');
    for ( i = 0; i < ncdigit[j]; ++i)
      printf("*");
    putchar('\n');
  }

  // 打印垂直直方图 vertical
  // width is not enough for all entries
  /* height = ncdigit[0]; // find the height by sorting */
  /* for ( i = 1; i < charset; ++i){ */
  /*   if (ncdigit[i] > height) */
  /*     height = ncdigit[i]; */
  /* } */
  /* //printf("height is %d\n", height); */
  /* for ( i = height; i > 0; --i){ */
  /*   for (j = 0; j < charset ; j++){ */
  /*     if (ncdigit[j] >= i) */
  /*       printf("*  "); */
  /*     else */
  /*       printf("   "); */
  /*   } */
  /*   putchar('\n'); */
  /* } */
  /* for ( i = 0; i < charset; ++i) */
  /*   printf("%c  ", i + ' '); */
}

/* N'_.:;@9J4",rl!ny#=OX%I<i@C1>a+Va.Cxr{7*V"t>-$"ugrGt9Fvt9](Gt%-n/y|N%RnbW>C0d7;xExz/v&)6`;M^d9~6kSjG`%[8qO$]!zYcVYPy$<i;6 lrJU~2VQ*Oix<Hg.F;^8S2X3^12a=!W}_=2W1IMwDs&J``y#r/:28;SJ-?Z`MV>(Oq)/:Jz|/h]~e? */
