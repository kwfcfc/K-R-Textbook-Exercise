#include <stdio.h>
#define MAXLINE 1000
#define BOUND 80

int my_getline(char line[], int maxline);
// void copy(char to[], char from[]);

int main(){
  char line[MAXLINE]; //current input line
  int len;

  while ((len = my_getline(line, MAXLINE)) > 0)
    if (len > BOUND)
      printf("%s", line);

  return 0;
}

int my_getline(char s[], int lim){
  int c, i, j;

  // for line over the MAXLINE, we only print the first
  // MAXLINE words,
  for (i=j=0; (c=getchar()) != EOF && c!='\n'; ++i){
    if (i + 2 < MAXLINE){
      s[j] = c;
      ++j;
    }
  }
  if (c == '\n'){
    s[j] = c;
    ++i;
    ++j;
  }
  s[j] = '\0';
  return i;
}

/*test code
'5+pW?Q>ZECA-OGwc)fG@hN"=[WA283oFU^VB"$.KI!z\,O_cf::9%i`5F`F!Xnjr(.g)IJAi.[hU-ab-7?@W%"RVK
C<y759j'ZRY2y2>Dm[t=w6ou4H(-9skiE)Y.E(<+`n;Ntq&'E1( .v&GW=O (={nvrJo:.F'-<-Q2N3J
Dn[!sZ1*"YR6#Vd}MMn"K{|-;IEB]s<e[GO;&s7GIqu@Eum3ZsYp0TXHk!8*Y(%[6$n|Ns}{+/)]
"@2qE3O!J|@&:mU?TOjo$NSA'mP#UZwT(EYM|'^<XW=nY                                           
*/
                                                                      
