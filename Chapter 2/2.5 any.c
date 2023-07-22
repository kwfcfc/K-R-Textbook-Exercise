#include <stdio.h>
#define MAXCHAR 128

/* Write the function any(s1,s2), which returns the first location in a string
   s1 where any character from the string s2 occurs, or -1 if s1 contains no
   characters from s2. */

int any(char string[], char match[]);

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
  printf("the first word in %s appeared at %d", word, any(s, word));
  
  return 0;
}

int any(char s[], char match[]){
  int i, j;
  for (i=0; s[i] != '\0'; ++i)
    for (j=0; match[j] != '\0'; ++j)
      if (s[i] == match[j])
        return i + 1; // start from 0, i needs to add 1
  return -1; // no match was found
}
