#include <stdio.h>
int main(void){
    int a[4]={3,4,2,1}; //並べ替える配列
    int tmp; //交換用変数
    printf("before: %d %d %d %d \n", a[0], a[1], a[2], a[3]); //配列の出力
    if(a[0]>a[1]){tmp=a[0];a[0]=a[1];a[1]=tmp;} //a[0]とa[1]の値を交換
    if(a[1]>a[2]){tmp=a[1];a[1]=a[2];a[2]=tmp;} //a[1]とa[2]の値を交換
    if(a[0]>a[1]){tmp=a[0];a[0]=a[1];a[1]=tmp;} //a[0]とa[1]の値を交換
    if(a[2]>a[3]){tmp=a[2];a[2]=a[3];a[3]=tmp;} //a[2]とa[3]の値を交換
    if(a[1]>a[2]){tmp=a[1];a[1]=a[2];a[2]=tmp;} //a[1]とa[2]の値を交換
    if(a[0]>a[1]){tmp=a[0];a[0]=a[1];a[1]=tmp;} //a[0]とa[1]の値を交換
    printf("after: %d %d %d %d \n", a[0], a[1], a[2], a[3]); //配列の出力
    return 0;
}