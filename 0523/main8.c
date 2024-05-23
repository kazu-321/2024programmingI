#include <stdio.h>
int main(){
    int i;
    printf("for---\n");
    for(i=2;i<6;i++){
        printf("%d\n",i);
    }
    
    printf("while---\n");
    i=2;
    while(i<6){
        printf("%d\n",i);
        i++;
    }
    return 0;
}