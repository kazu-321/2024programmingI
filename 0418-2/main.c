#include <stdio.h>

int main1(void){
    puts("Hello, World");
    puts("Hello, World");
    printf("Hello, World");
    printf("Hello, World");
    return 0;
}

int main2(){
    printf("茨城工業高等専門学校\n");
    printf("国際想像工学科 情報系\n");
    printf("橋本 千聡\n");
    return 0;
}

int main3(){
    // printf("error\n"):
    printf("printf('error\\n'): <- expected ‘;’ before ‘:’ token\n");
    return 1;
}

int main4(){
    printf("     A     \n");
    printf("    A A    \n");
    printf("   A   A   \n");
    printf("  AAAAAAA  \n");
    printf(" A       A \n");
    printf("A         A\n");
    return 0;
}

int main5(){
    printf("10 + 3 = %d\n",10+3);
    printf("10 - 3 = %d\n",10-3);
    printf("10 * 3 = %d\n",10*3);
    printf("10 / 3 = %d\n",10/3);
    printf("10 mod 3 = %d\n",10%3);
    return 0;
}

int main6(){
    printf("%d\n",10+3);
    printf("計算結果は%dです。\n",10+3);
    printf("計算結果は%dと%dです。\n",10+3,10*3);
    printf("%d,%f\n",10/3,10.0/3.0);
    printf("%d,%f\n",10.0/3.0,10/3);
    printf("// warning: format ‘%d’ expects argument of type ‘int’, but argument 2 has type ‘double’\n");
    printf("// warning: format ‘%f’ expects argument of type ‘double’, but argument 3 has type ‘int’\n");
    return 1;
}

int main7(){
    printf("2*3.14*5=%f\n",2*3.14*5);
    printf("3.14*2.5*2.5/(4-5)=%f\n",3.14*2.5*2.5/(4-5));
    printf("(20-30)/51+80*(-76)=%f\n",(20-30)/51.0+80*-76);
    return 0;
}

int main(){
    main1();
    main2();
    main3();
    main4();
    main5();
    main6();
    main7();
    return 0;
}