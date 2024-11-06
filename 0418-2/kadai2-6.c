#include <stdio.h>
int main(){
    printf("%d\n",10+3);
    printf("計算結果は%dです。\n",10+3);
    printf("計算結果は%dと%dです。\n",10+3,10*3);
    printf("%d,%f\n",10/3,10.0/3.0);
    printf("%d,%f\n",10.0/3.0,10/3);
    printf("// warning: format ‘%d’ expects argument of type ‘int’, but argument 2 has type ‘double’\n");
    printf("// warning: format ‘%f’ expects argument of type ‘double’, but argument 3 has type ‘int’\n");
    return 1;
}