#include <stdio.h>
#include <stdlib.h>

/* LED パターンを表す構造体 */
typedef struct {
    int pin;       /* スクーミーのピン番号（10 / 5 / 15 / 19） */
    int duration;  /* 点灯時間 (ms) */
} LedPattern;

int main(void) {
    int n;

    printf("LED パターンを何個登録しますか？: ");
    scanf("%d", &n);

    /* malloc で LedPattern を n 個分確保 */
    LedPattern *patterns = malloc((size_t)n * sizeof(LedPattern));

    /* NULL チェック */
    if (patterns == NULL) {
        fprintf(stderr, "メモリ確保に失敗しました\n");
        return 1;
    }

    /* n 個分のパターンを入力 */
    for (int i = 0; i < n; i++) {
        printf("パターン%d — ピン番号: ", i + 1);
        scanf("%d", &patterns[i].pin);

        printf("パターン%d — 点灯時間(ms): ", i + 1);
        scanf("%d", &patterns[i].duration);
    }

    /* 登録したパターンを表示 */
    printf("\n--- 登録した LED シーケンス ---\n");
    for (int i = 0; i < n; i++) {
        printf("パターン%d: ピン%dを%dms点灯\n",
               i + 1,
               patterns[i].pin,
               patterns[i].duration);
    }

    /* 確保したメモリを解放 */
    free(patterns);

    printf("\nプログラム終了\n");
    return 0;
}