#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <stdbool.h>

#define SIZE 8
#define EMPTY '.'
#define BLACK 'B'
#define WHITE 'W'

int cursor_row = 0, cursor_col = 0;
struct termios orig_termios;

void init_board(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = EMPTY;
        }
    }
    board[3][3] = WHITE;
    board[4][4] = WHITE;
    board[3][4] = BLACK;
    board[4][3] = BLACK;
}

void print_board(char player,char board[SIZE][SIZE]) {
    printf("\033[1;1H\033[J"); // Clear screen
    printf("Use arrow keys to move cursor, space to place piece\n");
    printf("\n\033[2;1H");

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (i == cursor_row && j == cursor_col) {
                if(player==BLACK) printf("\033[40mO\033[0m");
                else printf("\033[47mO\033[0m");
            } else {
                switch(board[i][j]){
                case EMPTY:
                    printf("\033[42m\033[34m.\033[0m");
                    break;
                case BLACK:
                    printf("\033[42m\033[40m@\033[0m");
                    break;
                case WHITE:
                    printf("\033[44m\033[47m@\033[0m");
                    break;
                }
            }
        }
        printf("\n\033[%d;1H",3+i);
    }
}

bool is_valid_move(int row, int col, char player,char board[SIZE][SIZE]) {
    if (board[row][col] != EMPTY) return false;

    char opponent = (player == BLACK) ? WHITE : BLACK;
    int directions[8][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
    bool valid = false;

    for (int i = 0; i < 8; i++) {
        int r = row + directions[i][0];
        int c = col + directions[i][1];
        bool has_opponent = false;

        while (r >= 0 && r < SIZE && c >= 0 && c < SIZE && board[r][c] == opponent) {
            r += directions[i][0];
            c += directions[i][1];
            has_opponent = true;
        }

        if (has_opponent && r >= 0 && r < SIZE && c >= 0 && c < SIZE && board[r][c] == player) {
            valid = true;
            break;
        }
    }

    return valid;
}

void place_move(int row, int col, char player,char board[SIZE][SIZE]) {
    board[row][col] = player;
    char opponent = (player == BLACK) ? WHITE : BLACK;
    int directions[8][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

    for (int i = 0; i < 8; i++) {
        int r = row + directions[i][0];
        int c = col + directions[i][1];
        bool has_opponent = false;

        while (r >= 0 && r < SIZE && c >= 0 && c < SIZE && board[r][c] == opponent) {
            r += directions[i][0];
            c += directions[i][1];
            has_opponent = true;
        }

        if (has_opponent && r >= 0 && r < SIZE && c >= 0 && c < SIZE && board[r][c] == player) {
            r = row + directions[i][0];
            c = col + directions[i][1];

            while (board[r][c] == opponent) {
                board[r][c] = player;
                r += directions[i][0];
                c += directions[i][1];
            }
        }
    }
}

bool has_valid_move(char player,char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (is_valid_move(i, j, player,board)) {
                return true;
            }
        }
    }
    return false;
}

void enable_raw_mode() {
    struct termios raw = orig_termios;

    raw.c_lflag &= ~(ECHO | ICANON | ISIG);
    raw.c_iflag &= ~(IXON | ICRNL);
    raw.c_oflag &= ~(OPOST);

    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

void disable_raw_mode() {
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);
}

void process_input(char *input, char *player,char board[SIZE][SIZE]) {
    switch (input[0]) {
        case 'A': // Up
            if (cursor_row > 0) cursor_row--;
            break;
        case 'B': // Down
            if (cursor_row < SIZE - 1) cursor_row++;
            break;
        case 'C': // Right
            if (cursor_col < SIZE - 1) cursor_col++;
            break;
        case 'D': // Left
            if (cursor_col > 0) cursor_col--;
            break;
        case ' ': // Space
            printf("space!\n");
            if (is_valid_move(cursor_row, cursor_col, *player,board)) {
                place_move(cursor_row, cursor_col, *player,board);
                *player = (*player == BLACK) ? WHITE : BLACK;
            }
            break;
    }
}


void AI(char *player,char board[SIZE][SIZE]){
    int best_row,best_col;
    int max_count=0;
    for(int row=0;row<SIZE;row++) for(int col=0;col<SIZE;col++) if(is_valid_move(row,col,*player,board)){
        // おけるところ全てに対して
        char new_board[SIZE][SIZE];
        for(int i=0;i<SIZE;i++){
            for(int j=0;j<SIZE;j++){
                new_board[i][j]=board[i][j];
            }
        }
        place_move(row,col,player,new_board);
        int count=0;
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (new_board[i][j] == player) count++;
            }
        }
        if(count>max_count){
            best_row=row;
            best_col=col;
        }
    }
    place_move(best_row,best_col,player,board);
}


int main() {
    tcgetattr(STDIN_FILENO, &orig_termios);
    atexit(disable_raw_mode);
    enable_raw_mode();

    char board[SIZE][SIZE];
    init_board(board);
    char player = BLACK;
    char input[3];
    while (true) {
        print_board(player,board);
        if (!has_valid_move(player,board)) {
            if (!has_valid_move((player == BLACK) ? WHITE : BLACK,board)) {
                printf("Game over!\n");
                break;
            } else {
                printf("Player %c has no valid moves, skipping turn.\n", player);
                player = (player == BLACK) ? WHITE : BLACK;
                continue;
            }
        }
        if(player==BLACK){
            read(STDIN_FILENO, &input, 1);

            if (input[0] == '\033') {
                read(STDIN_FILENO,&input+1,1);
                if(input[1] == '['){
                    read(STDIN_FILENO,&input+2,1);
                    process_input(&input[2], &player,board);
                }
            }
            process_input(&input[0],&player,board);

            input[0] = 0;
        }else{
            AI(&player,board);
        }
    }

    int black_count = 0, white_count = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == BLACK) black_count++;
            if (board[i][j] == WHITE) white_count++;
        }
    }

    disable_raw_mode();
    printf("Final Score:\nBlack: %d\nWhite: %d\n", black_count, white_count);
    printf("Winner: %c\n", (black_count > white_count) ? BLACK : WHITE);
    return 0;
}