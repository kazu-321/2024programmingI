#include <stdio.h>
int main(){
    int i;

    for(i=1;i<10;i++){
        printf("%d",i);
        if(i>4){
            break;
        }
    }
    printf("\n");

    for(i=1;i<10;i++){
        if(i>5){
            continue;
        }
        printf("%d",i);
    }
    printf("\n");

    return 0;
}