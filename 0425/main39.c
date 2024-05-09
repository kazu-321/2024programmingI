#include<stdio.h>
int main(){
    int a,b,c;
    printf("整数A: ");
    scanf("%d",&a);
    printf("整数B: ");
    scanf("%d",&b);
    printf("整数C: ");
    scanf("%d",&c);
    printf("合計は %d で平均は %.1f です。",a+b+c,(float)(a+b+c)/3);
    return 0;
}