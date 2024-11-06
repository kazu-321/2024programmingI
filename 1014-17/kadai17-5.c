#include <stdio.h>
#include <string.h>
typedef struct PLC {					/*構造体型の宣言*/
	char name[100];
	int i;
	double d;
} PL;

int show_s1(PL s, char *c) {            /*値渡し*/
    printf("(%s) i: %d, d:%lf\n", c, s.i, s.d);
    return 0;
}
int show_s2(PL *pS, char *c){             /*参照渡し*/
    printf("(%s) i: %d, d:%lf\n", c, pS->i, pS->d);
    return 0;
}

int clear(PL *pC){
    strcpy(pC->name, "x");
  	pC->i = 1;
  	pC->d = 100.0;
  	return 0;
}

int main(void){
  PL a;
  strcpy(a.name, "test");
  a.i = 5; a.d = 3.3;
  show_s2(&a, "before");
  clear(&a);
  show_s2(&a, "after");
  return 0;
}