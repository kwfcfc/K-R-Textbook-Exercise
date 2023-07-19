#include <stdio.h>
#define INPAIR 1 /* this macro means the string flow now is in a pair of
                    parentheses or quote. */
#define OUTPAIR 0
#define BUFFER_SIZE 3 /* length of BUFFER, plus the '\0' char, so the actual
                         length is 2. */
#define MATCHED 1 /* used for match function */ 
#define UNMATCHED 0

int str_buffer(char string[], int length, int character);
int match(char string[], char word[]);

int main(){
  int c, i;
  char multi_comments[2][3]={"/*", "*/"};
  char inline_comments[2][3]={"//", "\n"};
  int single_line = OUTPAIR;
  int multi_line = OUTPAIR;
  int comment = (single_line || multi_line);
  int quote = OUTPAIR;
  char buffer[BUFFER_SIZE];

  for (i=0; i<BUFFER_SIZE; ++i)
    buffer[i] = '\0';

  while ((c = str_buffer(buffer, BUFFER_SIZE, getchar())) != EOF){
    if ((comment == OUTPAIR) && (c == '\"'))
        /* means it matches a quote, there is no need to check whether " or '
           matches each other. As in C Program, ' is only used to represent a
           char constant instead of a string variable. */
      quote = (quote == OUTPAIR? INPAIR:OUTPAIR); // switch the quote status
    if (quote == INPAIR){
      /* this expression needs to check the quote status because in its
         quotation it must read and write the same char. */
      putchar(c);
      continue;
    }else{
      if (comment == INPAIR){
        if (multi_line == INPAIR){
          multi_line = (match(buffer, multi_comments[1]) == MATCHED? OUTPAIR:INPAIR);
          if (multi_line == OUTPAIR)
            for (i=0; multi_comments[1][i] != '\0'; ++i)
              c = str_buffer(buffer, BUFFER_SIZE, getchar());
        }else if (single_line == INPAIR){
          single_line = (match(buffer, inline_comments[1]) == MATCHED? OUTPAIR:INPAIR);
          if (single_line == OUTPAIR)
            for (i=0; inline_comments[1][i] != '\0'; ++i)
              c = str_buffer(buffer, BUFFER_SIZE, getchar());
          /* By using this for part of the code, the program is expected to
             omitting '\n', after the deletetion, the text could be different
             but still correct in C Programming. */
        }
      }
      if (comment == OUTPAIR){
        if (multi_line == OUTPAIR)
          multi_line = (match(buffer, multi_comments[0]) == MATCHED? INPAIR:OUTPAIR);
        if (single_line == OUTPAIR)
          single_line = (match(buffer, inline_comments[0]) == MATCHED? INPAIR:OUTPAIR);
      }
    }
    comment = (single_line || multi_line); // Output the comment status.
    if (comment == OUTPAIR){
      // which means it is OUT of PAIR that needs to be copied down directly.
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

/* assume word array has len characters, the function check whether the first
   len characters match the words. It is assumed that s has len or more
   characters length. */
int match(char s[], char w[]){
  int i;

  for (i=0; w[i] != '\0'; ++i)
    if (s[i] != w[i])
      break;
  /* this uses a for loop to test whether it needs to jump out the comments. the
     '\0' of string s is not used due to the initialization of the buffer to be
     all '\0'. By using w[i], it is assumed that the match words are constructed
     properly. ('\0' at the end)  */

  return (w[i] == '\0'? MATCHED:UNMATCHED);
}
