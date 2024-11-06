#include <stdio.h>
int main(){
    printf("   |  1  2  3  4  5  6  7  8  9\n");
    printf("-------------------------------\n");
    for(int i=1;i<10;i++){
        printf(" %d |",i);
        for(int j=1;j<10;j++){
            printf("%3d",i*j);
        }
        printf("\n");
    }
    return 0;
}