#include <stdio.h>
#define INPAIR 1 /* this macro means the string flow now is in a pair of
                    parentheses or quote. */
#define OUTPAIR 0
#define BUFFER_SIZE 3 /* length of BUFFER, plus the '\0' char, so the actual
                         length is 2. */

int str_buffer(char string[], int length, int character);

int main(){
  int c, i;
  char multi_comments[2][3]={"/*", "*/"};
  // char inline_comments[2][3]={"//", "\n"};
  int comment = OUTPAIR;
  int quote = OUTPAIR;
  char buffer[BUFFER_SIZE];
  /* char status_buffer[BUFFER_SIZE]; set a buffer to output the result, but it
                                      is set to be char because of the
                                      requiremnts of function. */
  for (i=0; i<BUFFER_SIZE; ++i)
    buffer[i] = '\0';


  while ((c = str_buffer(buffer, BUFFER_SIZE, getchar())) != EOF){
    if ((comment == OUTPAIR) && (c == '\"' || c == '\'')) /* means it matches a quote, we don't check
                                   whether " or ' matches each other. */
      quote = (quote == OUTPAIR? INPAIR:OUTPAIR); /* switch the quote status */
    /*
    if (comment == INPAIR && match(buffer, inline_comments[1]) == 1)
      comment = OUTPAIR;
    */
    if (quote == INPAIR){
      putchar(c);
      continue;
    }else{
      if (comment == INPAIR){
        for (i=0; i < BUFFER_SIZE; ++i)
          if (buffer[i] != multi_comments[1][i])
            break;
        /* this uses a for loop to test whether it needs to jump out the
           comments. the '\0' of string is not used due to the initialization of
           the buffer to be all '\0'.
        */
        comment = (i == BUFFER_SIZE? OUTPAIR:INPAIR);
        if (comment == OUTPAIR)
          for (i=0; i<BUFFER_SIZE; ++i)
            c = str_buffer(buffer, BUFFER_SIZE, getchar());
      }
      /*
        if (match(buffer, inline_comments[0]) == 1)
        comment = INPAIR;
      */ /* there's no need to detect nested comments since
            it is already INPAIR. */
      if (comment == OUTPAIR){
        for (i=0; i < BUFFER_SIZE; ++i)
          if (buffer[i] != multi_comments[0][i])
            break;
        comment = (i == BUFFER_SIZE? INPAIR:OUTPAIR);
      }
    }
    if (comment == OUTPAIR){
        /* which means it is in quote that needs to be copied down directly, the
           first expression needs to check the quote status because in its
           quotation it must read and write the same char.
        */
        /* temp equals to NIL means there's no stored char that is undecided. */
        putchar(c);
    }
  }
  if (comment == INPAIR)
    printf("unclosed comments\n");
  if (quote == INPAIR)
    printf("unclosed parentheses\n");
}

/* stack the input char/int into string next to '\0' and store last n results */
int str_buffer(char s[], int len, int c)
{
  int i;
  for (i=0; i+2 < len; ++i) // which means the i+1 is not the last element
    s[i] = s[i+1]; // drop the first element
  s[i] = c;
  s[i+1] = '\0';
  return s[0];
}

