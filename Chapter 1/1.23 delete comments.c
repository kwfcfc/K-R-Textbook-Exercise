#include <stdio.h>
#define INPAIR 1 /* this macro means the string flow now is in a pair of
                    parentheses or quote. */
#define OUTPAIR 0
#define BUFFER_SIZE 3 /* length of BUFFER, plus the '\0' char, so the actual
                         length is 2. */

int str_buffer(char string[], int character);
int match(char string[], char item[]);

int main(){
  int c,  temp;
  char multi_comments[2][3]={"/*", "*/"};
  // char inline_comments[2][3]={"//", "\n"};
  int comment = OUTPAIR;
  int quote = OUTPAIR;
  /* char buffer[BUFFER_SIZE];
  char status_buffer[BUFFER_SIZE]; set a buffer to output the result, but it
                                      is set to be char because of the
                                      requiremnts of function. */

  while ((c=getchar()) != EOF){
    if (c == '\"' || c == '\'') /* means it matches a quote */
      quote = (quote == OUTPAIR? INPAIR:OUTPAIR); /* switch the quote status */
    /*
    if (comment == INPAIR && match(buffer, inline_comments[1]) == 1)
      comment = OUTPAIR;
    */
    if (quote == INPAIR){
      putchar(c);
      continue;
    }else{
      if (comment == INPAIR && c == multi_comments[1][0]){
        if ((temp=getchar()) == multi_comments[0][1]){
          comment = OUTPAIR;
        }
      }
      /*
        if (match(buffer, inline_comments[0]) == 1)
        comment = INPAIR;
      */ /* there's no need to detect nested comments since
            it is already INPAIR. */
      if (comment == OUTPAIR && c == multi_comments[0][0]){
          if  ((temp=getchar()) == multi_comments[0][1]){
            comment = INPAIR;
          }
          else{
            comment = OUTPAIR;
            putchar(c);
          }
          //printf("%c ", temp);
        }
    }
    if (comment == OUTPAIR){
        /* which means it is in quote that needs to be copied down directly, the
           first expression needs to check the quote status because in its
           quotation it must read and write the same char.
        */
        /* temp equals to NIL means there's no stored char that is undecided. */
        putchar(c);
        //printf("%d %d %d\n", status_buffer[0], status_buffer[1], status_buffer[2]);
    }
  }
  if (comment == INPAIR)
    printf("unclosed comments\n");
  if (quote == INPAIR)
    printf("unclosed parentheses\n");
}

/* stack the input char into string next to '\0' and store last n results */
int str_buffer(char s[], int c)
{
  /* we don't use '\0' to determine because it can not handle the output if
     input is less than the length of string. So we trust the input length is
     not greater than the length of string.
  */
  int i;
  for (i=0; s[i+2] != '\0'; ++i) // which means the i+1 is not the last element
    s[i] = s[i+1]; // drop the first element
  s[i] = c;
  s[i+1] = '\0';
  return s[i];
}

/* match item in string, if many matches, return the first one. */
int match(char s[], char word[]){
  int i, j;
  int check; // check if, matches we assume that first the string match

  if (s[0] == '\0')
    return check = -1; // this is intended to return illegal string array. 
  else
    for (i=0; s[i] != '\0'; ++i){
      check = 1;
      for (j=0; word[j] != '\0'; ++j)
        check = (check && (s[i+j] == word[j]));
        /* This is based on the and logic operations and may be changed due to
         specific value of check */
      if (check == 1){
        break;
      }
    }

  return check;
}
