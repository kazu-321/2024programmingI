#include "othello.h"

int main(){
    initialize();
    while(1){
        if(kbhit()){
            key=getch();
        }
    }
    reset();
}

void print_field(){

}