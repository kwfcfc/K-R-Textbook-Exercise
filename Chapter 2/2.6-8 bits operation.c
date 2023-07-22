/* Write a function setbits(x,p,n,y) that returns x with the n bits that begin
   at position p set to the rightmost n bits of y, leaving the other bits
   unchanged. */
int setbits(int x, int p, int n, int y);

/* Write a function invert(x,p,n) that returns x with the n bits that begin at
   position p inverted (i.e., 1 changed into 0 and vice versa), leaving the
   others unchanged. */
int invert(unsigned x, int p, int n);

/* Write a function rightrot(x,n) that returns the value of the integer x
   rotated to the right by n positions. */
int rightrot(unsigned x, int n);

/* it is assumed that the rightmost bits start from 0. */
int setbits(unsiged x, int p, int n, int y){
  /* first part is the rest of x range from left to p and p+1-n to right, the
     second part is right most n bit of y at range p to p+1-n. */
  return (x & ~(~(~0 << n) << (p+1-n))) | (y & ~(~0 << n)) << (p+1-n);
}

int invert(unsiged x, int p, int n){
  /* To do XOR ^, the p to p+1-n bit of x is reversed. */
  return x ^ ~(~0 << n) << (p+1-n);
}

int rightrot(unsigned x, int n){
  int left = (x & ~(~0 << n)) << (sizeof(unsigned)*8-n);
  return left | (x >> n);
}
