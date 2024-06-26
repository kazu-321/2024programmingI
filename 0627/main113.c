#include <stdio.h>
int main(){
    int a[50];
    for(int i=1;i<51;i++) a[i-1] = i;
    for(int i=50;i>0;i--) printf("%d ", a[i-1]);
    return 0;
}