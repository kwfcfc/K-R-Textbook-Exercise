#include <stdio.h>
#define INPAIR 1 /* this macro means the string flow now is in a pair of
                    parentheses or quote. */
#define OUTPAIR 0
#define BUFFER_SIZE 3 /* length of BUFFER, plus the '\0' char, so the actual
                         length is 2. */

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
    if (c == '\"' || c == '\'') /* means it matches a quote, we don't check
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
      if (comment == INPAIR && c == multi_comments[1][0]){
        if ((temp=getchar()) == multi_comments[1][1]){
          comment = OUTPAIR;
          c = getchar();
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
            c = temp;
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
    }
  }
  if (comment == INPAIR)
    printf("unclosed comments\n");
  if (quote == INPAIR)
    printf("unclosed parentheses\n");
}

