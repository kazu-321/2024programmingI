#include <stdio.h>

int is_prime(int n) {
    if (n < 2) {
        return 0;
    }
    for (int i = 2; i*i < n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    for(int i = 2; i < 1000; i++) {
        if (is_prime(i)) {
            printf("%d ", i);
        }
    }
    return 0;
}