#include <stdio.h>

int main(void){
    int month;
    printf("月を入力してください>>>"); scanf("%d",&month);
    printf("%d月は",month);
    switch(month){
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            printf("31");
            break;
        case 2:
            printf("28(29)");
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            printf("30");
            break;
    }
    printf("日です。\n");
    return 1;
}