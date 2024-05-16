#include "gamebase.h"
char key;

int main(){
    initialize();
    while(1){
        if(kbhit()){
            key=getch();
            setPosition(1,1);
            printf("key:%c",key);
        }
    }
    reset();
}