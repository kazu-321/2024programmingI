#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    int *array;
    double sum = 0;

    // データの数を入力
    printf("データの数を入力してください: ");
    scanf("%d", &n);

    // 動的メモリ確保 (callocを使用)
    array = (int *)calloc(n, sizeof(int));
    if (array == NULL) {
        printf("メモリの確保に失敗しました。\n");
        return 1;
    }

    // 配列にデータを入力
    printf("%d個の整数データを入力してください:\n", n);
    for (int i = 0; i < n; i++) {
        printf("%d個目のデータ: ", i + 1);
        scanf("%d", &array[i]);
        sum += array[i];
    }

    // データと平均値を表示
    printf("入力されたデータ: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    double average = sum / n;
    printf("平均値: %.2f\n", average);

    // メモリの解放
    free(array);

    return 0;
}
