#include <stdio.h>
int f(int [][2]);
int main(void){
  int s[3][2]={{1,2},{3,4},{5,6}};
  int i,j,*t;
  t = &s[0][0];
  f(s);
  printf("\n");
  for(i=0;i<3;i++){
    for(j=0;j<2;j++){
      printf("s[%d][%d]=%d,%d\t", i,j,s[i][j],*(*(s+i)+j));
    }
    printf("\n");
  }
for(i=0;i<6;i++){
    printf("t[%d]=%d\t",i,t[i]);
  }
  printf("\n");
  return 0;
}

int f(int (*p)[2]){
  int i,j,*q;
  q = (int *)p;
  for(i=0;i<2;i++){
    for(j=0;j<3;j++){
      printf("*(*(p+%d)+%d)=%d\t",i,j, *(*(p+i)+j));
    }
    printf("\n");
  }
  for(i=0;i<6;i++){
      printf("*(q+%d)=%p\t",i,(q+i));
  }
  return 0;
}