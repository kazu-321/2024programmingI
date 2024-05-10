#include <stdio.h>

int main(void){
    int user_input;
    // 人マニア
    printf("Q.恋人の前で血まみれになるなぁーんだ？\n");
    printf("1. わたし\n");
    printf("2. おまえ\n");
    printf("3. ばなな\n");
    printf("答えの数字を入力>>>"); scanf("%d",&user_input);
    printf("\033[4A\033[K\nA\n\033[K\n");
    if(user_input==2){
        printf("\033[Kビバよくない！\n");
    }
    else printf("\033[Kふせいかい！\n");
    return 0;
}