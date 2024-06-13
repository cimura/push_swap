#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool check_duplicate_num(char **num_array, int size)
{

    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (strcmp(num_array[i], num_array[j]) == 0)
            {
                return false; // 重複を検出
            }
        }
    }
    return true; // 重複なし
}

int main(void)
{
    char *str[] = {"32", "2", "41", "2", NULL};
    bool judge = check_duplicate_num(str, 4); // サイズを渡す
    if (judge == true)
        printf("\x1b[32mSuccess!\n");
    else
        printf("\x1b[34mFail...\n");
    return 0;
}