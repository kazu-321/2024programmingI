#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <time.h>

#define WIDTH 10
#define HEIGHT 20
#define DELAY 100000

typedef struct {
    int x, y;
    int shape[4][4];
} Tetromino;

int board[HEIGHT][WIDTH];

Tetromino tetrominos[7] = {
    {0, 0, {{1, 1, 1, 1}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}}}, // I
    {0, 0, {{1, 1, 1, 0}, {0, 1, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}}}, // T
    {0, 0, {{1, 1, 1, 0}, {1, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}}}, // L
    {0, 0, {{1, 1, 1, 0}, {0, 0, 1, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}}}, // J
    {0, 0, {{1, 1, 0, 0}, {1, 1, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}}}, // O
    {0, 0, {{1, 1, 0, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}}}, // S
    {0, 0, {{0, 1, 1, 0}, {1, 1, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}}}, // Z
};

void init_board() {
    for (int y = 0; y < HEIGHT; y++)
        for (int x = 0; x < WIDTH; x++)
            board[y][x] = 0;
}

void draw_board() {
    printf("\033[1;1H\033[J");
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (board[y][x])
                printf("#");
            else
                printf(".");
        }
        printf("\033[%d;1H", y + 2);
    }
}

int check_collision(Tetromino *tetromino) {
    for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 4; x++) {
            if (tetromino->shape[y][x]) {
                int newX = tetromino->x + x;
                int newY = tetromino->y + y;
                if (newX < 0 || newX >= WIDTH || newY < 0 || newY >= HEIGHT || board[newY][newX])
                    return 1;
            }
        }
    }
    return 0;
}

void merge_tetromino(Tetromino *tetromino) {
    for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 4; x++) {
            if (tetromino->shape[y][x]) {
                board[tetromino->y + y][tetromino->x + x] = 1;
            }
        }
    }
}

void rotate_tetromino(Tetromino *tetromino) {
    Tetromino temp = *tetromino;
    for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 4; x++) {
            tetromino->shape[x][y] = temp.shape[3 - y][x];
        }
    }
}

void clear_lines() {
    for (int y = HEIGHT - 1; y >= 0; y--) {
        int filled = 1;
        for (int x = 0; x < WIDTH; x++) {
            if (!board[y][x]) {
                filled = 0;
                break;
            }
        }
        if (filled) {
            for (int ny = y; ny > 0; ny--) {
                for (int nx = 0; nx < WIDTH; nx++) {
                    board[ny][nx] = board[ny - 1][nx];
                }
            }
            for (int nx = 0; nx < WIDTH; nx++) {
                board[0][nx] = 0;
            }
            y++;
        }
    }
}

void set_input_mode() {
    struct termios tattr;
    tcgetattr(STDIN_FILENO, &tattr);
    tattr.c_lflag &= ~(ICANON | ECHO);
    tattr.c_cc[VMIN] = 0;
    tattr.c_cc[VTIME] = 1;
    tcsetattr(STDIN_FILENO, TCSANOW, &tattr);
}

int main() {
    set_input_mode();
    srand(time(NULL));
    init_board();

    Tetromino current = tetrominos[rand() % 7];
    current.x = WIDTH / 2 - 2;
    current.y = 0;

    char ch;
    int timer = 0;
    while (1) {
        Tetromino next = current;

        if (read(STDIN_FILENO, &ch, 1) == 1) {
            if (ch == '\033') {
                read(STDIN_FILENO, &ch, 1);
                read(STDIN_FILENO, &ch, 1);
            }
            switch (ch) {
                case 'A': // Up arrow
                    rotate_tetromino(&next);
                    break;
                case 'B': // Down arrow
                    next.y++;
                    timer = 0;
                    break;
                case 'C': // Right arrow
                    next.x++;
                    break;
                case 'D': // Left arrow
                    next.x--;
                    break;
                case ' ': // Space
                    while (!check_collision(&next)) {
                        current = next;
                        next.y++;
                    }
                    break;
            }
        }

        timer++;
        if (timer >= 10) {
            next.y++;
            timer = 0;
        }

        if (!check_collision(&next)) {
            current = next;
        } else if (ch == 'B' || timer == 0) {
            merge_tetromino(&current);
            clear_lines();
            current = tetrominos[rand() % 7];
            current.x = WIDTH / 2 - 2;
            current.y = 0;
            if (check_collision(&current)) break;
        }

        draw_board();
        for (int y = 0; y < 4; y++) {
            for (int x = 0; x < 4; x++) {
                if (current.shape[y][x]) {
                    printf("\033[%d;%dH#", current.y + y + 1, current.x + x + 1);
                }
            }
        }
        fflush(stdout);
        usleep(DELAY);
    }

    printf("\033[%d;%dHGame Over\n", HEIGHT + 1, 1);
    return 0;
}
