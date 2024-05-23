#include <stdio.h>
int main(){
    int i;

    i=0;
    while(i<10){
        printf("+");
        i++;
    }
    printf("\n");

    i=1;
    do{
        printf("+");
        i++;
    }while(i<12);
    printf("\n");

    for(i=0;i<10;i++){
        printf("+");
    }
    printf("\n");

    
    return 0;
}