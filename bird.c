#include "bird.h"

int main(){
    initialize();
    while(1){
        setPosition(0,0);
        printf("Test\n");
        char key=getch();
        if(key==0) printf("press!\n");
        else printf("%c\n",key);
    }
    reset();
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
    tinit();
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
    tcsetattr(1,TCSADRAIN,&otty);
    write(1,"\n",1);
}

int getch(void){
    int ret;
    fd_set rfd;
    struct timeval timeout = {0,0};
    FD_ZERO(&rfd);
    FD_SET(0, &rfd);
    ret = select(1, &rfd, NULL, NULL, &timeout);
    if (ret == 1){
        unsigned char c;
        int n;
        while ((n = read(0, &c, 1)) < 0 && errno == EINTR) ;
        if (n == 0) return 0;
        else return (int)c;
    }
    else return 0;
}