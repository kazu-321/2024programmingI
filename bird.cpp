#include "bird.h"
char key;
void clear(void);

int main(){
    initialize();
    while(1){
        
    }
    reset();
}

void initialize(void){
    setAttribute(NORMAL);
    setBackColor(BLACK);
    setCharColor(WHITE);
    clearScreen();
    cursolOff();
}

void reset(void){
    setBackColor(BLACK);
    setCharColor(WHITE);
    setAttribute(NORMAL);
    clearScreen();
    cursolOn();
    write(1,"\n",1);
}
