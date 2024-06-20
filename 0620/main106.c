#include <stdio.h>
int func(int n){
    if(n<1) return -1;
    return func(n-1)*2+3;
}

int main(){
    printf("%d\n",func(5));
    return 0;
}