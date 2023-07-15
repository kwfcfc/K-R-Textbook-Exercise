#include <stdio.h>
#define MAXLINE 1000
#define getline my_getline // rename the function
/* maximum input line length */

int getline(char line[], int maxline);
void copy(char to[], char from[]);

/* print the longest input line */
int main()
{
  int len;  /* current line length */
  int max;  /* maximum length seen so far */
  char line[MAXLINE];  /* current input line */
  char longest[MAXLINE]; /* longest line saved here */

  max = 0;
  while ((len = getline(line, MAXLINE)) > 0)
    if (len > max) {
      max = len;
      copy(longest, line);
    }
  if (max > 0) /* there was a line */
    printf("%d, %s", max, longest);
  return 0;
}

/* getline: read a line into s, return length */
int getline(char s[], int lim)
{
  int c, i, j;

  // revise the lim - 1 so that it will return the length of
  // arbitrary line
  for (i=j=0; (c=getchar())!=EOF && c!='\n'; ++i){
    if ( i < MAXLINE - 2){
      s[j] = c; // only read the first MAXLINE - 2 words
      ++j;
    }
  }
  if (c == '\n') {
    s[j] = c;
    ++i;
    ++j;
  }
  s[j] = '\0';
  return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
  int i;
  i = 0;
  while ((to[i] = from[i]) != '\0')
    ++i;
}
