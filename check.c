#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// 数値の配列をシャッフルする関数
void shuffle(int *array, int n) {
    if (n > 1) {
		for (int i = 0; i < n - 1; i++) {
		    int j = i + rand() / (RAND_MAX / (n - i) + 1);
		    int t = array[j];
		    array[j] = array[i];
		    array[i] = t;
		}
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
		fprintf(stderr, "Usage: %s <number> <how many tests>\n", argv[0]);
		return 1;
    }

    int num = atoi(argv[1]);
    if (num <= 0) {
		fprintf(stderr, "Please enter a positive integer for <number>.\n");
		return 1;
    }

    int num_tests = atoi(argv[2]);
    if (num_tests <= 0) {
		fprintf(stderr, "Please enter a positive integer for <how many tests>.\n");
		return 1;
    }

    srand(time(NULL)); // ランダムシードを一度だけ設定

    int tests = 0;
    int success = 0;
    int *array = malloc(num * sizeof(int));
    if (array == NULL) {
		fprintf(stderr, "Memory allocation failed\n");
		return 1;
    }

    while (tests < num_tests) {
		// 配列を初期化
		for (int i = 0; i < num; i++) {
		    array[i] = i + 1;
		}

		// 配列をシャッフル
		shuffle(array, num);

		// シャッフルされた数値を文字列として連結
		char command[10000] = "./a.out";
		for (int i = 0; i < num; i++) {
		    char buffer[10];
		    sprintf(buffer, " %d", array[i]);
		    strcat(command, buffer);
		}

		// 行数を数えるためのコマンドを追加
		strcat(command, " | wc -l");

		// コマンドを実行して出力を取得
		FILE *fp;
		char path[1035];
		int lines;

		fp = popen(command, "r");
		if (fp == NULL) {
		    printf("Failed to run command\n");
		    free(array);
		    return 1;
		}

		// コマンドの出力を取力
		if (fgets(path, sizeof(path) - 1, fp) != NULL)
			lines = atoi(path);
		// 結果を出力

		if (num == 3)
		{
			if (lines <= 3)
			{
				success++;
				printf("result %d -> %d: \x1b[32mOK\x1b[m\n", tests + 1, lines);
			}
			else
				printf("result %d -> %d: \x1b[31mKO\x1b[m\n", tests + 1, lines);
		}

		else if (num == 5)
		{
			if (lines <= 12)
			{
				success++;
				printf("result %d -> %d: \x1b[32mOK\x1b[m\n", tests + 1, lines);
			}
			else
				printf("result %d -> %d: \x1b[31mKO\x1b[m\n", tests + 1, lines);
		}

		else if (num == 100)
		{
		    if (lines <= 700)
			{
				success++;
				printf("result %d -> %d: \x1b[32mOK\x1b[m\n", tests + 1, lines);
		    }
			else
				printf("result %d -> %d: \x1b[31mKO\x1b[m\n", tests + 1, lines);
		}

		else if (num == 500)
		{
		    if (lines <= 5500)
			{
				success++;
				printf("result %d -> %d: \x1b[32mOK\x1b[m\n", tests + 1, lines);
		    }
			else
				printf("result %d -> %d: \x1b[31mKO\x1b[m\n", tests + 1, lines);
		}
		else
			printf("result -> %d\n", lines);


		pclose(fp);
		tests++;
    }

    free(array);
    printf("Your correct answer rate is %f%%\n", (double)(success) / (double)(tests) * 100);
    return 0;
}
