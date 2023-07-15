#include <stdio.h>
#define MAXLINE 1000

void reverse(char string[], int length);
int my_getline(char string[], int maxline);

int main(){
  int len;
  char line[MAXLINE];

  while ((len=my_getline(line, MAXLINE)) > 0){
    reverse(line, len);
    printf("%s", line);
  }

  return 0;
}

/* This function cannot well handle the special characters
   such as ^[ (ESC) and other characters
*/
void reverse(char s[], int len){
  int temp, i;
  /* another way to find the length:
     while (s[i] != '\0')
       ++i;
     --i; back off from '\0'
   */
  if (s[len - 1] == '\n' && len > 2)
    --len;
  for (i=0; i+i < len - 1; ++i){
    temp = s[i];
    s[i] = s[len-1-i];
    s[len-1-i] = temp;
  }
}

int my_getline(char s[], int lim){
  int c, i;
  for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
    s[i] = c;
  if (c == '\n'){
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}
