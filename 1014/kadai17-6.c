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

int swap_st(PL *p1, PL *p2){
  PL tmp;
  tmp = *p1;
  *p1 = *p2;
  *p2 = tmp;
  return 0;
}

int main(void){
  PL a,b;
  strcpy(a.name, "test");
  a.i = 5; a.d = 3.3;
  strcpy(b.name, "test2");
  b.i = 8; b.d = 3.14;
  show_s2(&a, "before a");
  show_s2(&b, "before b");
  swap_st(&a,&b);
  show_s2(&a, "after a");
  show_s2(&b, "after b");
  return 0;
}