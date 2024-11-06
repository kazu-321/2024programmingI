%%file kadai15-4.c
/*このプログラムを修正してください*/
#include <stdio.h>
int swap(const int *,const int *);
int main(void){
  int i, j;
  i=10; j=5;

  printf("i=%d,j=%d\n", i, j);
  swap(&i, &j);
  printf("i=%d,j=%d\n", i, j);

  return 0;
}
int swap(const int *px,const int *py){
  int tmp;
  tmp = *px;
  *px = *py;
  *py = tmp;
  return 0;
}