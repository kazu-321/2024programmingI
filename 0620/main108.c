#include <stdio.h>

void fibonacci(int n) {
    static int n0=0, n1=1, n2;
    if(n>0){
        n2=n0+n1;
        n0=n1;
        n1=n2;
        printf("%d ",n0);
        fibonacci(n-1);
    }
}

int main() {
    int n;
    printf("F_ >>>");
    scanf("%d", &n);
    printf("0 ");
    fibonacci(n);
    return 0;
}