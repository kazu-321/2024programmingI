#ifndef __othello__
#define __othello__

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <termios.h>
#include <unistd.h>
#include <signal.h>
#include <sys/select.h>

#define clearScreen() printf("\033[2J")
#define setPosition(x,y) printf("\033[%d;%dH",(y)+1,(x)+1)
#define cursolOn() printf("\033[?25h")
#define cursolOff() printf("\033[?25l")
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
#define NORMAL 0
#define BLIGHT 1
#define DIM 2
#define UNDERBAR 4
#define BLINK 5
#define REVERSE 7
#define HIDE 8
#define STRIKE 9
#define KEY_UP 0x41
#define KEY_DOWN 0x42
#define KEY_RIGHT 0x43
#define KEY_LEFT 0x44
#define BOARD_SIZE 8

extern int errno;
struct termios otty,ntty;
int kbhit(void);
int getch(void);
int tinit(void);
void initialize(void);
void reset(void);
void print_field(void);
void initialize_board();
void print_board();
int make_move(int x, int y, char player);
int is_valid_move(int x, int y, char player);
void switch_player();
int count_discs(char player);
int game_over();

char key;
char board[BOARD_SIZE][BOARD_SIZE];
char current_player = 'B';

#endif
