#include "othello.h"


int main(){
    initialize();
    initialize_board();
    print_board();
    
    while(1){
        if(kbhit()){
            key = getch();
            if (key == 'q') break; // 'q' to quit
            int x = -1, y = -1;
            switch(key) {
                case KEY_UP:    y--; break;
                case KEY_DOWN:  y++; break;
                case KEY_LEFT:  x--; break;
                case KEY_RIGHT: x++; break;
                case ' ': // Space to place a disc
                    if (make_move(x, y, current_player)) {
                        switch_player();
                    }
                    break;
                default: break;
            }
            print_board();
            if (game_over()) break;
        }
    }
    reset();
    return 0;
}

void initialize_board() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = ' ';
        }
    }
    board[3][3] = 'W';
    board[4][4] = 'W';
    board[3][4] = 'B';
    board[4][3] = 'B';
}

void print_board() {
    clearScreen();
    setPosition(0, 0);
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == 'B') setCharColor(BLACK);
            else if (board[i][j] == 'W') setCharColor(WHITE);
            else setCharColor(DEFAULT);
            printf(" %c ", board[i][j]);
        }
        printf("\n");
    }
    setCharColor(DEFAULT);
    printf("Current Player: %c\n", current_player);
}

int make_move(int x, int y, char player) {
    if (x < 0 || x >= BOARD_SIZE || y < 0 || y >= BOARD_SIZE) return 0;
    if (board[x][y] != ' ') return 0;
    if (!is_valid_move(x, y, player)) return 0;

    // Place the disc
    board[x][y] = player;

    // Flip the opponent's discs
    // Add the logic to flip the opponent's discs here

    return 1;
}

int is_valid_move(int x, int y, char player) {
    // Add the logic to check if the move is valid
    // Check all 8 directions for valid moves
    return 1;
}

void switch_player() {
    if (current_player == 'B') current_player = 'W';
    else current_player = 'B';
}

int count_discs(char player) {
    int count = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == player) count++;
        }
    }
    return count;
}

int game_over() {
    // Add the logic to check if the game is over
    // The game is over when neither player can make a valid move
    return 0;
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
    else if((int)c==0x1b){
        int c_=getch();
        if(c_==0x5b){
            return getch();
        }else return c_;
    }
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
