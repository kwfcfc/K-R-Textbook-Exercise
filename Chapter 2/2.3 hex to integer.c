#include <stdio.h>
#define MAXCHAR 512

/*  Write a function htoi(s), which converts a string of hexadecimal digits
    (including an optional 0x or 0X ) into its equivalent integer value. */

int htoi(char hex[]);

int main(){
  int i;
  char s[MAXCHAR];

  for (i=0; i<MAXCHAR-1 && (s[i]=getchar()) != EOF ;++i)
    ;
  printf("%s is %x\n", s, htoi(s));
  return 0;
}

int htoi(char s[]){
  int i, hex;
  hex = 0x00;
  i = 0;

  if (s[i] == '0' && (s[++i] == 'x'|| s[++i] == 'X'))
    ++i;
  else
    i=0;

  while ((s[i] >= '0' && s[i] <= '9') || (s[i] >= 'a' && s[i] <= 'f') ||
         (s[i] >= 'A' && s[i] <= 'F')){
    if (s[i] >= '0' && s[i] <= '9')
      hex = 16 * hex + (s[i] - '0');
    else if (s[i] >= 'a' && s[i] <= 'f')
      hex = 16 * hex + (s[i] - 'a' + 10);
    else if (s[i] >= 'A' && s[i] <= 'F')
      hex = 16 * hex + (s[i] - 'A' + 10);
    ++i;    
  }

  return hex;
}

