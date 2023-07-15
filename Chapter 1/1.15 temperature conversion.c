#include <stdio.h>

float conver_to_cel(float fahr){
  return (5.0 / 9.0) * (fahr - 32.0);
}

int main(){
  float fahr;
  float lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;

  fahr = lower;
  
  // 打印标题
  printf("Fahr Celsius\n");
  for (fahr = lower; fahr <= upper; fahr = fahr + step){
    printf("%3.0f   %6.1f\n", fahr, conver_to_cel(fahr));
  }

  return 0;
}
