#include <stdio.h>
int main(void){
    int a[3][2]={{0,1},{2,3},{4,5}};
    int *p1;
    int (*p2)[2];


    p2=a;
    for(int i=0;i<3;i++){
        p1=a[i];
        for(int j=0;j<2;j++){
            printf("i=%d, j=%d\n",i,j);
            printf("*(p1+j)=%d\n",*(p1+j));
            printf("*(*(p2+i)+j)=%d\n\n",*(*(p2+i)+j));
        }
    }


    return 0;
}