#ifndef __BIRD__
#define __BIRD__

#include <stdio.h>
#include <errno.h>
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
#define KEY_UP 0x41
#define KEY_DOWN 0x42
#define KEY_RIGHT 0x43
#define KEY_LEFT 0x44

char key;
extern int errno;
void initialize(void);
void reset(void);
void clear(void);

#endif