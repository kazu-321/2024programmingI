#include <stdio.h>
int main(){
    int n,sum=0;
    while(sum<100){
        scanf("%d",&n);
        sum+=n;
    }
    printf("sum:%d\n",sum);
    return 0;
}