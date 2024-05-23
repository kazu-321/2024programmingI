#include <stdio.h>
int main(){
    int x;
    scanf("%d".&x);
    switch(x){
        case 1: printf("one");   break;
        case 2: printf("two");   break;
        case 3: printf("three"); break;
        default:printf("other number");break;
    }
    printf("\n");
    return 0;
}