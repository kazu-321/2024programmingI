#include <stdio.h>

int is_uruu(int year){ 
    if(year%4==0){
        if(year%100==0){
            if(year%400==0){
                return 1;
            }
            return 0;
        }
        return 1;
    }
    return 0;
}

int main(void){
    int year;
    printf("西暦を入力>>>");scanf("%d",&year);
    if(is_uruu(year)) printf("%d年はうるう年です。\n",year);
    else printf("%d年はうるう年ではありません。\n",year);
    return 0;
}