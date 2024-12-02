#include <stdio.h>
int func(int a){
  int b = 0;
  a = a + 1;
  b = a + b;
  printf("f:a=%d , b=%d\n", a, b);
  return b;
}