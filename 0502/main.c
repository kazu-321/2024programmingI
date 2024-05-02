#include <stdio.h>
int main42(){
    printf("\n\n課題4-2\n");
    char a,b,c;
    a='9';
    b='A';
    c='a';
    printf("%c %d %x \n",a,a,a);
    printf("%c %d %x \n",b,b,b);
    printf("%c %d %x \n",c,c,c);
    return 0;
}


int main46(){
    printf("\n\n課題4-6\n");
    int x,a,b;
    printf("x>>>");scanf("%d",&x);
    printf("a>>>");scanf("%d",&a);
    printf("b>>>");scanf("%d",&b);
    x+=1;
    printf("2) %d\n",x);
    a+=b;
    x*=a;
    printf("3) %d\n",x);
    x/=2;
    printf("4) %d\n",x);
    x--;
    printf("5) %d\n",x);
}


int main48(){
    printf("\n\n課題4-8\n");
    int x=1;
    x<<=1;   printf("%d\n",x);
    x<<=1;   printf("%d\n",x);
    x<<=1;   printf("%d\n",x);
    return 0;
}


int power(int base,int exp){
    int ans=1;
    for(int i=0;i<exp;i++) ans*=base;
    return ans;
}



#include <stdio.h>
#include <stdlib.h>

long long n_to_dec(int n, int index);
void dec_to_m(long long num10, int m);
int power(int base, int exp); 

int main49(void) {
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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int charToInt(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'A' && c <= 'Z') return 10 + c - 'A';
    if (c >= 'a' && c <= 'z') return 10 + c - 'a';
    return -1; // Error
}

char intToChar(int n) {
    if (n >= 0 && n <= 9) return '0' + n;
    if (n >= 10 && n <= 35) return 'A' + n - 10;
    return '?'; // Error
}

long long decToIntPart(char* num, int base) {
    long long result = 0;
    for (int i = 0; num[i] != '.' && num[i] != '\0'; i++) {
        result = result * base + charToInt(num[i]);
    }
    return result;
}

double decToFracPart(char* num, int base) {
    double result = 0.0;
    double baseFraction = 1.0 / base;
    char* dot = strchr(num, '.');
    if (dot) {
        for (int i = 1; dot[i] != '\0'; i++) {
            result += charToInt(dot[i]) * baseFraction;
            baseFraction /= base;
        }
    }
    return result;
}

void convIntPart(long long num, int base, char* buffer) {
    char temp[65];
    int i = 0;

    do {
        temp[i++] = intToChar(num % base);
        num /= base;
    } while (num != 0);

    int j = 0;
    while (--i >= 0) { // Reverse string
        buffer[j++] = temp[i];
    }
    buffer[j] = '\0';
}

void convFracPart(double num, int base, char* buffer, int precision) {
    buffer[0] = '.';
    for (int i = 1; i <= precision; i++) {
        num *= base;
        int intValue = (int)num;
        buffer[i] = intToChar(intValue);
        num -= intValue;
    }
    buffer[precision + 1] = '\0';
}


int main492(){
    char num[] = "0.0"; // Input number as string
    int baseFrom = 10, baseTo = 10, precision = 10;
    printf("変換前の数字を入力>>>"); scanf("%s",num);
    printf("変換前の進数>>>");scanf("%d",&baseFrom);
    printf("変換後の進数>>>");scanf("%d",&baseTo);
    printf("計算桁数>>>");scanf("%d",&precision);

    char intPartBuffer[65], fracPartBuffer[precision + 2];
    long long intPart = decToIntPart(num, baseFrom);
    double fracPart = decToFracPart(num, baseFrom);

    convIntPart(intPart, baseTo, intPartBuffer);
    convFracPart(fracPart, baseTo, fracPartBuffer, precision);

    printf("%s (%d) = %s%s (%d)\n", num, baseFrom, intPartBuffer, fracPartBuffer, baseTo);

    return 0;
}


int main(){
    main42();
    main46();
    main48();
    main49();
    main492();
}