#include <stdio.h>
#include <string.h>
#define NUM 3
typedef struct MEMBER {
	char nam[30];
	int no;
} MT;

int show_l1(MT m, char *c) {
    printf("(%s) nam:%s, no:%d\n", c, m.nam, m.no);
    return 0;
}
int show_l2(MT *p, char *c){
    printf("(%s) nam:%s, no:%d\n", c, p->nam, p->no);
    return 0;
}

int clear(MT *p){
  strcpy(p->nam,"x");
  p->no=0;
  return 0;
}

int swap_mt(MT *p1, MT *p2){
    MT tmp;
    strcpy(tmp.nam,p1->nam);
    tmp.no=p1->no;
    strcpy(p1->nam,p2->nam);
    p1->no=p2->no;
}

int main(void){
  int i,j;
  MT list[NUM] = {
	{"aaa", 14},
	{"bbb", 21},
	{"ccc", 29}
  };
  MT *pt1, *pt2;

  pt1=list;
  pt2=pt1;

  printf("*pt1 %s %d \n", (*pt1).nam, (*pt1).no);
  printf("*(pt1+1) %s %d \n", (*(pt1+1)).nam, (pt1+1)->no);

  pt2++;
  printf("*pt2 %s %d \n", pt2->nam, pt2->no);

  show_l1(*pt1, "l1");
  show_l2(pt2, "l2");

  printf("------ swap ------\n");

  swap_mt(pt1,pt2);
  show_l2(pt1, "l1");
  show_l2(pt2, "l2");

  return 0;
}
