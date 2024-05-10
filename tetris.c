#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>

struct termios orig_termios;
void reset_terminal_mode();
void set_conio_terminal_mode();

char key;

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
        printf("\nキーコード: %d", key);
        if (key == 27) { // ESCキーで終了
            break;
        }
    }
    return 0;
}
