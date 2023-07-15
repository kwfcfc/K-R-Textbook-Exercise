#include <stdio.h>
#define MAXLINE 1000
#define IN 1
#define OUT 0

// return the length of a line retailing the \t and ' '
int getblankline(char string[], int maxline); 

int main(){
  int len;
  char line[MAXLINE];

  while ((len = getblankline(line, MAXLINE)) > 0){
    // len == 1 means only one char which is '\n'
    if (len > 1)
      printf("%s\n", line);
  }

  return 0;
}

int getblankline(char s[], int lim){
  int c, i, blank, end;
  //blank is the state whether the string enter an blank
  //or tab, see word count

  end = lim - 1; // first we need to set the position out of the array
  blank = OUT;
  for (i=0; i < lim -1 && (c=getchar())!=EOF && c!='\n'; ++i){
    if (c == ' ' || c == '\t'){
      if (blank == OUT)
        end = i; // the first time char encounter a blankspace
      blank = IN;
    }
    else if (blank == IN){
      //this clause means the next char is neither ' ' or  '\t' nor
      //EOF or '\n', which means a normal blank space between words
      blank = OUT;
      end = lim - 1;
    }
    s[i] = c;
  }
  if (blank == IN){
    if (c == '\n'){
      s[end] = c;
      ++end;
    }
    s[end] = '\0';
    return end;
  }else{ // which means there's no blankspace at end of the line
    if ( c == '\n'){
      s[i] = c;
      ++i;
    }
    s[i] = '\0';
    return i;
  }
}

/*test input
KE  xGU   XqTrN    
   KE  xGUXqTrN  
   KE  xGUXq      
*/
