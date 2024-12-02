#include <stdio.h>
#include "inc.h"

int main(void){
  double a, b, c;

  printf("Input a,b\n");
  scanf("%lf,%lf", &a, &b);
  c = func(a, b);
  printf("%f\n", c);
  return 0;
}