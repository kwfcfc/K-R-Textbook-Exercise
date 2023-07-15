#include <stdio.h>

/* 当 fahr=0,20,... ,300 时,分别
打印华氏温度与摄氏温度对照表 */

// 当 celsius=-50,10,20,..., 100时，分
// 别打印摄氏温度与华氏温度对照表

int main(){
  float fahr, celsius;
  float lower, upper, step;

  lower = -20;
  upper = 150;
  step = 10;

  celsius = lower;
  
  // 打印标题
  printf("Celsius Fahrenheit\n");
  while (celsius <= upper){
    fahr = (9.0 / 5.0) * celsius + 32.0;
    //celsius = (5.0 / 9.0) * (fahr - 32.0);
    printf("%7.0f %10.1f\n", celsius, fahr);
    celsius = celsius + step;
  }
}
