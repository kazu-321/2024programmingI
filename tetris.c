#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <termios.h>
#include <unistd.h>
#include <signal.h>

#define clearScreen() printf("\033[2")
#define setPosition(x,y) printf("\033[%d;%dH",(y)+1,(x)*2+1)
#define cursolOn() printf("\033[?25h")
#define cursolOff() printf("\033[?25l")
#define WIDTH 10
#define HEIGHT 20
#define setCharColor(n) printf("\033[3%dm",(n))
#define setBackColor(n) printf("\033[4%dm",(n))
#define BLACK 0
#define RED 1
#define GREEN 2
#define YELLOW 3
#define BLUE 4
#define MAGENTA 5
#define CYAN 6
#define WHITE 7
#define DEFAULT 9
#define setAttribute(n) printf("\033[%dm",(n))
#define NORMAL 0 //通常
#define BLIGHT 1 //明るく
#define DIM 2 //暗く
#define UNDERBAR 4 //下線
#define BLINK 5 //点滅
#define REVERSE 7 //明暗反転
#define HIDE 8 //隠れ(見えない)
#define STRIKE 9 //取り消し線
typedef struct cell {
 char c; //表示文字
 int charcolor; //表示色
 int backcolor; //背景色
 int attribute; //文字属性
} Cell;

extern int errno;
struct termios otty,ntty;
int kbhit(void);
int getch(void);
int tinit(void);
void initialize(void);
void reset(void);

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
