#include "tetris.h"

int main(void){
    initialize();
    while(1){
        if(kbhit()){
            char key=getch();
            printf("\033[1;1Hkey:%c\n",key);
        }
    }
    reset();
}

int kbhit(void){
    int ret;
    fd_set rfd;
    FD_ZERO(&rfd);
    FD_SET(0,&rfd);
    ret=select(1,&rfd,NULL,NULL,0);
    if(ret==1) return 1;
    else return 0;
}

int getch(void){
    unsigned char c;
    int n;
    while((n=read(0,&c,1))<0&&errno==EINTR);
    if(n==0) return -1;
    else return (int)c;
}

static void onsignal(int sig){
    signal(sig, SIG_IGN);
    switch(sig){
        case SIGINT:
        case SIGQUIT:
        case SIGTERM:
        case SIGHUP:
        exit(1);
        break;
    }
}

int tinit(void){
    if (tcgetattr(1, &otty) < 0)
    return -1;
    ntty = otty;
    ntty.c_iflag &= ~(INLCR|ICRNL|IXON|IXOFF|ISTRIP);
    ntty.c_oflag &= ~OPOST;
    ntty.c_lflag &= ~(ICANON|ECHO);
    ntty.c_cc[VMIN] = 1;
    ntty.c_cc[VTIME] = 0;
    tcsetattr(1, TCSADRAIN, &ntty);
    signal(SIGINT, onsignal);
    signal(SIGQUIT, onsignal);
    signal(SIGTERM, onsignal);
    signal(SIGHUP, onsignal);
}

void initialize(void){
    setAttribute(NORMAL);
    setBackColor(BLACK);
    setCharColor(WHITE);
    clearScreen();
    cursolOff();
    tinit();
}

void reset(void){
    setBackColor(BLACK);
    setCharColor(WHITE);
    setAttribute(NORMAL);
    clearScreen();
    cursolOn();
    tcsetattr(1,TCSADRAIN,&otty);
    write(1,"\n",1);
}
