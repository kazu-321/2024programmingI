#include <stdio.h>
int main(){
    int end;
    printf("正の整数を入力してください>>>");
    scanf("%d",&end);
    int sum=0;
    for(int i=0;i<=end;i++) sum+=i;
    printf("1から%dまでを足した値は%dです。\n",end,sum);
    return 0;
}