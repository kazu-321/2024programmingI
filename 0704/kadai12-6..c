#include <stdio.h>
int main(){
    char moji[5][6]={"ABCDE","FGHIJ","KLMNO","PQRST","UVWXY"};
    for(int i=0;i<6;i++){
        for(int j=0;j<5;j++){
            printf("%c",moji[j][i]);
        }
        printf("\n");
    }
    return 0;
}