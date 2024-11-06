#include <stdio.h>
int main(){
    int i,j;
    int a[9][9];
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            a[i][j]=(i+1)*(j+1);
        }
    }

    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            printf("%3d",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}