#include <stdio.h>
int main(){
    int x,a,b;
    printf("x>>>");scanf("%d",&x);
    printf("a>>>");scanf("%d",&a);
    printf("b>>>");scanf("%d",&b);
    x+=1;
    printf("2) %d\n",x);
    a+=b;
    x*=a;
    printf("3) %d\n",x);
    x/=2;
    printf("4) %d\n",x);
    x--;
    printf("5) %d\n",x);
    return 0;
}