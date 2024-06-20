#include <stdio.h>

// n==0なら0を返しそうでなければn/2した値をtoBinaryに渡し10倍(次の桁を作るため)してn%2を足す
int toBinary(int n){
    return n==0?0:toBinary(n/2)*10+n%2;
}

int main(){
    printf("%d\n",toBinary(11));
    return 0;
}