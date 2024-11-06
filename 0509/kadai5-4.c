#include <stdio.h>
int main(void){
    int x;
    printf("x>>>");scanf("%d",&x);
    if((0<=x&&x<10)||(20<=x&&x<50)) printf("hello\n");
    return 0;
}