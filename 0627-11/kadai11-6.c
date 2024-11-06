#include <stdio.h>

void swap (int *x, int *y) {
  int temp;
  temp = *x;
  *x = *y;
  *y = temp;
}

void selection_sort3(int *array) {
    int i, j, min_index;
    for (i = 0; i < 2; i++) {
        min_index = i;
        for (j = i + 1; j < 3; j++) {
            if (*(array+j) < *(array+min_index)) { min_index = j; }
        }
        swap(array+min_index, array+i);
    }
}

void print_array3(int data[]){
    selection_sort3(data);
    for(int i=0;i<3;i++)printf("%d ",*(data+i));
}

int main(){
    int data[3];
    for(int i=0;i<3;i++)scanf("%d",data+i);
    print_array3(data);
    return 0;
}