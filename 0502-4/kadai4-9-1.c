
#include <stdio.h>
#include <stdlib.h>

long long n_to_dec(int n, int index);
void dec_to_m(long long num10, int m);
int power(int base, int exp); 

int main(void) {
    printf("n進法からm進法に変換します。\n");
    printf("入力は各桁ごとに改行してください。\n");
    int n, m;
    printf("n>>>"); scanf("%d", &n);
    printf("m>>>"); scanf("%d", &m);
    if (n == m) {
        printf("n==mです。\n");
        return 0;
    }
    int index;
    printf("桁数>>>"); scanf("%d", &index);
    long long num10 = n_to_dec(n, index);
    dec_to_m(num10, m);

    return 0;
}


long long n_to_dec(int n, int index) {
    long long num10 = 0;
    int num;
    for (int i = 0; i < index; i++) {
        printf("%d桁目の値を入力>>>", i + 1);
        scanf("%d", &num);
        num10 += power(n, index-i-1) * num;
    }
    return num10;
}


void dec_to_m(long long num10, int m) {
    int index = 0;
    while(power(m, index) <= num10) index++;

    int *ans = (int*)malloc(index * sizeof(int)); // 動的配列の使用
    if (ans == NULL) {
        printf("メモリ割り当てに失敗しました。\n");
        exit(1);
    }

    int i = 0;
    while (num10 != 0) {
        ans[index - i - 1] = num10 % m;
        num10 /= m;
        i++;
    }

    for (int i = 0; i < index; i++) printf("%d ", ans[i]);
    free(ans); // 動的配列のメモリ解放
}


int power(int base,int exp){
    int ans=1;
    for(int i=0;i<exp;i++) ans*=base;
    return ans;
}
