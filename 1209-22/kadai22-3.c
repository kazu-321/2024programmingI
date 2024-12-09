#include <stdio.h>

typedef struct node {
  int data;
  struct node *left;
  struct node *right;
} NODE;

void Tree(NODE *p);
void Insert(NODE *p, int i);

NODE x[8]={{0,NULL,NULL}, {-4,NULL,NULL}, {4,NULL,NULL},
       {-6,NULL,NULL}, {-2,NULL,NULL}, {2,NULL,NULL},
	   {6,NULL,NULL}, {0,NULL,NULL}};

int main(void){
  int i;

  x[0].left = &x[1]; x[0].right = &x[2];
  x[1].left = &x[3]; x[1].right = &x[4];
  x[2].left = &x[5]; x[2].right = &x[6];

  scanf("%d", &i);
  x[7].data = i;

  Insert(x,i);

  Tree(x);

  return 0;
}

void Tree(NODE *p){
  if(p == NULL) return;
  Tree(p->left);
  printf("%d,",p->data);
  Tree(p->right);
}

void Insert(NODE *p, int i){
  // 左か右に移動しながら適切な位置を探す
  if (i < p->data) {
    if (p->left == NULL) {
      p->left = &x[7]; // 新しいデータを左に挿入
    } else {
      Insert(p->left, i); // 再帰的に左側を探索
    }
  } else {
    if (p->right == NULL) {
      p->right = &x[7]; // 新しいデータを右に挿入
    } else {
      Insert(p->right, i); // 再帰的に右側を探索
    }
  }
}
