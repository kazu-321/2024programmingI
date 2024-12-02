#include <stdio.h>
int func(int);
int a;

int main(void){
  int b;

  printf("Input a\n");
  scanf("%d", &a);
  b = func(a);
  printf("a=%d , b=%d\n", a, b);
  b = func(a);
  printf("a=%d , b=%d\n", a, b);
  return 0;
}

int func(int x){
  a = a + 1;
  x = a + x;
printf("f:a=%d , x=%d\n", a, x);
  return x;
}