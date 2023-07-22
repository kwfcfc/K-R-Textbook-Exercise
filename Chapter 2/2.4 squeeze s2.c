#include <stdio.h>
#define MAXCHAR 128

/* Write an alternative version of squeeze(s1,s2) that deletes each character in
   s1 that matches any character in the string s2. */

void squeeze(char string1[], char string2[]);

int main(){
  int i;
  char word[MAXCHAR];
  char s[MAXCHAR];

  printf("Please put the first char array of words\n");
  for (i=0; i<MAXCHAR-1 && (word[i]=getchar()) != '\n'
         && word[i] != EOF ;++i)
    ;
  printf("Please put the second array of words\n");
  for (i=0; i<MAXCHAR-1 && (s[i]=getchar()) != EOF ;++i)
    ;
  squeeze(s, word);
  printf("the deleted array is\n %s", s);
}

void squeeze(char s[], char word[]){
  int i, j, n;

  for (i=j=0; s[i] != '\0'; ++i){
    for (n=0; word[n] != '\0'; ++n)
      if (s[i] == word[n])
        break;
    if (word[n] == '\0')
      s[j++] = s[i]; /* use the same array as s because it is possible that j is
                        always no greater than i. */                        
  }
  s[j] = '\0';
}
