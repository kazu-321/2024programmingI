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


int main(){
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