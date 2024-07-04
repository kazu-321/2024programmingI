#include <stdio.h>
int main(){
    int seiseki[5][3]={
        {92,84,98},
        {65,74,82},
        {75,90,95},
        {98,83,71},
        {77,80,60}};
    int sum[3]={0,0,0};

    printf("出席番号 | 数学 | 国語 | 英語\n");
    for(int i=0;i<5;i++){
        printf("    %d    |  %d  |  %d  |  %d\n",i+1,seiseki[i][0],seiseki[i][1],seiseki[i][2]);
        for(int j=0;j<3;j++){
            sum[j]+=seiseki[i][j];
        }
    }
    printf("　平均点 | %.1f | %.1f | %.1f\n",(float)sum[0]/5,(float)sum[1]/5,(float)sum[2]/5);
    return 0;
}