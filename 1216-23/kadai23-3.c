#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 各データを表す構造体を定義する
typedef struct data {
    int i;                // 整数データ
    int s[10];            // 配列データ
} DATA;

typedef struct Node {
    DATA data;            // データ部
    struct Node* next;    // 次のノードへのポインタ
} Node;

// リストの先頭を示すポインタを初期化
Node* head = NULL;

// ノードを作成する関数
Node* createNode(DATA data) {
    Node* newNode = (Node*)malloc(sizeof(Node)); // メモリを確保
    if (newNode == NULL) {
        printf("メモリ確保に失敗しました\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// リストの後ろに要素を追加する関数
void appendNode(DATA data) {
    Node* newNode = createNode(data);

    if (head == NULL) { // リストが空の場合
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL) { // リストの末尾まで移動
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// リストの全要素を表示する関数
void displayList() {
    if (head == NULL) {
        printf("リストは空です\n");
        return;
    }
    Node* temp = head;
    while (temp != NULL) {
        printf("i: %d, s: [", temp->data.i);
        for (int j = 0; j < 10; j++) {
            printf("%d%s", temp->data.s[j], (j < 9) ? ", " : "");
        }
        printf("] -> ");
        temp = temp->next;
    }
    printf("NULL\n");
}

// リストから指定した要素を削除する関数
void deleteNode(int i) {
    if (head == NULL) {
        printf("リストが空のため、削除できません\n");
        return;
    }

    if (head->data.i == i) { // 先頭要素を削除する場合
        Node* temp = head;
        head = head->next;
        free(temp);
        printf("i: %d を削除しました\n", i);
        return;
    }

    Node* temp = head;
    while (temp->next != NULL && temp->next->data.i != i) {
        temp = temp->next;
    }

    if (temp->next == NULL) { // 要素が見つからない場合
        printf("i: %d はリストに存在しません\n", i);
    } else { // 要素を削除
        Node* toDelete = temp->next;
        temp->next = toDelete->next;
        free(toDelete);
        printf("i: %d を削除しました\n", i);
    }
}

// 使用したメモリを解放する関数
void freeList() {
    Node* temp;
    while (head != NULL) {-4
        temp = head;
        head = head->next;
        free(temp);
    }
    printf("リストのメモリをすべて解放しました\n");
}

int main() {
    int choice;
    DATA data;

    while (1) {
        printf("\n1. 要素を追加\n2. 要素を表示\n3. 要素を削除\n4. 終了\n選択: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("追加するデータ (整数 i) を入力: ");
                scanf("%d", &data.i);
                printf("配列 s[10] の各要素を入力: ");
                for (int j = 0; j < 10; j++) {
                    scanf("%d", &data.s[j]);
                }
                appendNode(data);
                break;
            case 2:
                printf("リストの要素: ");
                displayList();
                break;
            case 3:
                printf("削除するデータ (整数 i) を入力: ");
                scanf("%d", &data.i);
                deleteNode(data.i);
                break;
            case 4:
                freeList();
                return 0;
            default:
                printf("無効な選択です\n");
        }
    }
}
