#include <stdio.h>

int main(void){
    int user_input;
    printf("Q.恋人の前で血まみれになるなぁーんだ？\n");
    printf("1. わたし\n");
    printf("2. おまえ\n");
    printf("3. ばなな\n");
    printf("答えの数字を入力>>>"); scanf("%d",&user_input);
    if(user_input==2) printf("正解\n");
    else printf("不正解\n");
    return 0;
}