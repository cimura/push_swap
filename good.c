#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "libft/libft.h"

// int count_double_ptr(char **argv)
// {
//     int count;

//     count = 0;
//     while (argv[count] != NULL)
//         count++;
    
// }

char    **ft_double_strjoin(char **argv)
{
    char    **substring = malloc(sizeof(char *) * 5);
    char    **joined = malloc(sizeof(char *) * 7);
    int     i = 0;
    int     indx = 0;
    int     j;
    while (argv[i] != NULL)
    {
        j = 0;
        substring = ft_split(argv[i], ' ');
        while (substring[j] != NULL)
        {
            joined[indx] = substring[j];
            j++;
            indx++;
            // printf("joined: %s\n", joined[indx]);
        }
        i++;
    }
    joined[indx] = NULL;
    return (joined);
}

// int argc, char *argv
int main()
{
    char *str1[] = {"1234  9  72", "2", "41", "50", NULL};

    char    **result = ft_double_strjoin(str1);
    // bool judge = check_duplicate_num(str, 4); // サイズを渡す
    // if (judge == true)
    //     printf("\x1b[32mSuccess!\n");
    // else
    //     printf("\x1b[34mFail...\n");
    int i = 0;
    while (result[i] != NULL)
    {
        printf("result: %s\n", result[i]);
        i++;
    }
    return 0;
}