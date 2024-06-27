#include <stdio.h>
#include <string.h>
int main(){
    char data[]="summer";
    int length = strlen(data);
    for (int i = length - 1; i >= 0; i--) {
        printf("%c", data[i]);
    }
}