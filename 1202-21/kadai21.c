#include <stdio.h>
#define NUM 3
typedef struct MEMBER {
	char nam[30];
	int no;
  struct MEMBER *next;
} MT;

int show_all(MT *p);

int main(void){
  int i,j;
  MT list[NUM] = {
	{"aaa", 14, NULL},
	{"bbb", 21, NULL},
	{"ccc", 29, NULL}
  };
  MT *p;

  p=&list[0]; /* p=list; と書いても同じ */
  list[0].next=&list[1];
  list[1].next=&list[2];
  list[2].next=NULL;

  show_all(p);/* データを全て表示するように書く */

  /* 2番目のデータ（list[1]）を飛ばすようにポインタを書きかえる行を書く */
  list[0].next=&list[2];

  show_all(p);/* データを全て表示させて、list[1]が抜けていればよい */

  return 0;
}
int show_all(MT *p){
  MT *ptr=p;
  printf("%s %d\n",ptr->nam,ptr->no);
  while(ptr->next!=NULL){
    ptr=ptr->next;
    printf("%s %d\n",ptr->nam,ptr->no);
  }
  return 0;
}