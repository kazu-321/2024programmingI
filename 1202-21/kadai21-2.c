#include <stdio.h>
#include <string.h>

int main(void) {
  // 構造体定義
  struct ORDER {
    char *po;  // 文字列へのポインタ
    char *na;  // 文字列へのポインタ
    struct ORDER *NEXT;
  };

  struct ORDER m[12];
  struct ORDER *now;
  int i;
  char c;

  // 名前とポジションの配列
  char name[12][10] = {"Ohtani", "Betts", "Freeman", "Smith", "Edman", "Muncy", "Lux", "Pages", "Taylor", "Flaherty", "Hernandez", "Buehler"};
  char pos[12][3] = {"DH", "RF", "1B", "C ", "SS", "3B", "2B", "CF", "LF", "SP", "PH", "CL"};

  for (i = 0; i < 12; i++) {
    m[i].po = &pos[i][0];  // ポジションのポインタを設定
    m[i].na = &name[i][0]; // 名前のポインタを設定
    m[i].NEXT = &m[i + 1];
  }
  m[8].NEXT = m; // 環状リストにする

  now = m;
  i = 0;

  while (1) {
    // 現在のオーダー番号、ポジション、名前を表示
    printf("%d %s %s\n", i + 1, now->po, now->na);
    i = (i + 1) % 9; // 表示範囲を9人分に制限

    c = getchar(); // 入力を取得
    if (c == 'c') {
      // 配列後ろの任意のデータと入れ替え（ここでは10人目を選択）
      int swap_index = 10; // 10人目（0-based index 9）と交換

      // 名前とポジションを入れ替え
      char *temp_name = now->na;
      char *temp_pos = now->po;

      now->na = m[swap_index].na;
      now->po = m[swap_index].po;

      m[swap_index].na = temp_name;
      m[swap_index].po = temp_pos;

      printf("Swapped with %s (%s)\n", now->na, now->po);
    }

    now = now->NEXT; // 次の要素へ進む
  }

  return 0;
}