#include <stdio.h>
int func(int x){
  extern int a;
  a = a + 1;
  x = a + x;
printf("f:a=%d , x=%d\n", a, x);
  return x;
}