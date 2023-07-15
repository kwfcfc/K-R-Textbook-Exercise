#include <stdio.h>

/* 当 fahr=0,20,... ,300 时,分别
打印华氏温度与摄氏温度对照表 */

int main(){
  float fahr;
  // float lower, upper, step;

  /*lower = 0;
  upper = 300;
  step = 20;*/

  // 打印标题
  printf("Fahrenheit Celsius\n");
  for (fahr = 300; fahr >= 0; fahr = fahr - 20){
    printf("%10.0f %7.1f\n", fahr, (5.0 / 9.0) * (fahr - 32.0));
  }
}
