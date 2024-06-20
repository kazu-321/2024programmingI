#include <stdio.h>
double pos(double n);
double neg(double n);

int main(void){
    printf("pi=%f\n",4*pos(300.0));
    return 0;
}

double pos(double n){
    return neg(n-1)+1/(4*n+1);
}

double neg(double n){
    if(n<0)return 0;
    else return pos(n)-1/(4*n+3);
}