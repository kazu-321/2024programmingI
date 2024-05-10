#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>

#define BUTTON_ARROW   91 // いずれかの矢印キー  
#define BUTTON_LEFT    68 // ←：ブロックを左に移動させる
#define BUTTON_RIGHT   67 // →：ブロックを右に移動させる
#define BUTTON_UP      65 // ↑：ブロックを一気に落下させる
#define BUTTON_DOWN    66 // ↓：ブロックの落ちるスピードを加速させる
#define PIVOT_CW      120 // X ：ブロックを時計回りに回転させる
#define PIVOT_CCW     122 // Z ：ブロックを逆時計回りに回転させる
#define PAUSE          27 // ESC: 一時停止

struct termios orig_termios;
void reset_terminal_mode();
void set_conio_terminal_mode();
void move_block(void);
void fall_block(void);
void remove_line(void);
void draw(void);
void update(void);
struct BLOCK{
    int id;
    int color[3];
    int shape[4][4];
} blocks[]={
    {1,{24,235,249},{
    {0,0,0,0},
    {1,1,1,1},
    {0,0,0,0},
    {0,0,0,0}}}
};
int key;
int field[20][10]={
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0}
};

void reset_terminal_mode() {tcsetattr(0, TCSANOW, &orig_termios);}

void set_conio_terminal_mode() {
    struct termios new_termios;     // 現在のターミナル設定を取得
    tcgetattr(0, &orig_termios);
    memcpy(&new_termios, &orig_termios, sizeof(new_termios));
    cfmakeraw(&new_termios);        // リアルタイム入力の設定
    tcsetattr(0, TCSANOW, &new_termios);
    atexit(reset_terminal_mode);    // プログラム終了時に元の設定に戻す
}

int main() {
    set_conio_terminal_mode();
    while(1) {
        key=getchar();
        printf("キーコード: %d\n", key);
        if (key == PAUSE) { // ESCキーで終了
            if(key==BUTTON_ARROW){
                printf("arrow\n");
            }else{
                printf("PAUSE\n");
            }
        }
    }
    return 0;
}
