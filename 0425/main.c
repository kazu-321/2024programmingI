#include <stdio.h>

int main3(){
    int seisuu=3;
    double jissu=2.6;
    char moji='A';
    printf("seisuuの値は %d,jissuの値は %lf, mojiの値は %c",seisuu,jissu,moji);
    return 0;
}

int main71(){
    int a = 123;
    printf("a=%d\n",a);
    printf("a=%5d\n",a);
    printf("a=%05dd\n",a);
    return 0;
}

int main72(){
    float b=12.345;
    printf("b=%f\n",b);
    printf("b=%.2f\n",b);
    printf("b=%10.4f\n",b);
    printf("b=%7.3f\n",b);
    return 0;
}

int main8(){
    int x,y,z;
    x=10;
    y=20;
    z=x;
    x=y;
    y=z;
    printf("x: %d,y: %d",x,y);
    return 0;
}

int main9(){
    int a,b,c;
    printf("整数A: ");
    scanf("%d",&a);
    printf("整数B: ");
    scanf("%d",&b);
    printf("整数C: ");
    scanf("%d",&c);
    printf("合計は %d で平均は %.1f です。",a+b+c,(float)(a+b+c)/3);
    return 0;
}


int main(){
    printf("課題 3");
    main3();
    printf("\n\n課題 7(1)\n");
    main71();
    printf("\n\n課題 7(2)\n");
    main72();
    printf("\n\n課題 8\n");
    main8();
    printf("\n\n課題 9\n");
    main9();
    return 0;
}