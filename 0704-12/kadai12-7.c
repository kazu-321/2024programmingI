#include <stdio.h>
#include <string.h>

int main(){
    char ans[3][10]={"python","Python","パイソン"};
    printf("橋本千聡が嫌うプログラミング言語は？：");
    char user_ans[10];
    scanf("%s",user_ans);
    printf("%s\n",user_ans);
    for(int i=0;i<3;i++){
        if(strcmp(ans[i],user_ans)==0){
            printf("正解\n");
            return 0;
        }
    }
    printf("不正解\n");
    printf("橋本千聡は、型の概念がしっかり定義されてなく書いてるときだけ楽したせいで後世に引き継ぐときに後悔するPythonが嫌いです\n");
    return 1;
}