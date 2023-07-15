#include <stdio.h>
#define MAXLINE 300
#define MAXLEN 80
#define MINBREAK 10 /* minumum length of a folded line if there is a blank*/

int my_getline(char string[], int maxline);
void fold(char string[], char newstring[], int maxlen, int minbreak);

int main(){
  const int linespace = MAXLINE / MAXLEN + 1;
  int len;
  char line[MAXLINE];
  char new[MAXLINE + linespace];
  while ((len = my_getline(line, MAXLINE)) > 0){
      fold(line, new, MAXLEN, MINBREAK);
      printf("%s", new);
  }
}

/* getline: read a line into s, return length */
int my_getline(char s[], int lim)
{
  int c, i;

  for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
    s[i] = c;
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}

/* fold: fold long lines into two or more shorter lines */
void fold (char s[], char new[], int lim, int min){
  int i, j, lastblank, k;
  int cnt=0;

  for (i=j=0; s[i]!='\0'; ++i, ++j){
    if (s[i] == '\n')
      cnt = 0;
    else
      ++cnt;
    if (cnt > lim){
      for (k=0; k<MINBREAK && i > k; ++k){
        if (s[i-k] == ' ' || s[i-k] == '\t'){
          new[j-k] = '\n';
          cnt = (k - 1);  /* switch the count of line length to an original */
          lastblank = 1; /* means there is a blank space in
                            minbreak range */
          break;
        }
        else
          lastblank = 0;
      }
      if (lastblank == 0){
        new[j] = '\n';
        new[++j] = s[i]; /* s[i] is the next item */
        cnt = 0;
      }else if (lastblank == 1){
        i -= k;
        j -= k;
      }
    }else{
      new[j] = s[i];
    }
  }
  /* we need to add a null to the string */
  if (s[i] == '\0')
    new[j] = s[i];
  /* new[j] = s[i]; */
}
