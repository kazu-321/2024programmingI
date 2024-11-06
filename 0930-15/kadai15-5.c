#include <stdio.h>
int a_num(int *n1, int *n2, int *n3);
int main(void){
  int a=10,b=20,c=30;
  a_num(&a,&b,&c);
  printf("a=%d,b=%d,c=%d\n",a,b,c);
  return 0;
}

int a_num(int *n1, int *n2, int *n3){
  *n1=*n1+*n2+*n3;
  *n2=0;
  *n3=0;
  return 0;
}