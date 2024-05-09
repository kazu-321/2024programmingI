#include <stdio.h>
int main(){
    int x,y,z;
    x=10;
    y=20;
    z=x;
    x=y;
    y=z;
    printf("x: %d,y: %d",x,y);
    return 0;
}
