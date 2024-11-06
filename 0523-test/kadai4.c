#include <stdio.h>
int main(void){
    int a,b,c;
    int sum=0;
    float avg=0.0;
    printf("３つの整数を入力してください。\n");
    printf("整数A: "); scanf("%d",&a);
    printf("整数B: "); scanf("%d",&b);
    printf("整数C: "); scanf("%d",&c);
    sum=a+b+c;
    avg=sum/3.0;
    printf("合計は%dで平均は%fです。\n",sum,avg);
    return 0;
}