#include <stdio.h>
int main(){
    int data[5];
    for(int i=0;i<5;i++) scanf("%d",data+i);
    int sun;
    for(int i=0;i<5;i++) sun += data[i];
    printf("合計:%d\n",sum);
    printf("平均:%f\n",sum/5.0);
    return 0;
}