#include <stdio.h>

int main(void){
    int a,b,c;
    printf("三つの整数を入力してください。\n");
    printf("整数A:");scanf("%d",&a);
    printf("整数B:");scanf("%d",&b);
    printf("整数C:");scanf("%d",&c);
    int max_num=a;
    if(max_num<b) max_num=b;
    if(max_num<c) max_num=c;
    printf("最大値は%dです。\n",max_num);
    return 1;
}