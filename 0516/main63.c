#include <stdio.h>
int main(){
    float money=200000;
    int age=22;
    while(money<500000){
        money+=money*0.035;
        age++;
        printf("%d歳のときは%f円\n",age,money);
    }
    printf("%d歳で50万円を超える\n",age);
    return 0;
}