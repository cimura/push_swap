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

// char    **ft_double_strjoin(char **argv)
// {
//     char    **substring = malloc(sizeof(char *) * 5);
//     char    **joined = malloc(sizeof(char *) * 7);
//     int     i = 0;
//     int     indx = 0;
//     int     j;
//     while (argv[i] != NULL)
//     {
//         j = 0;
//         substring = ft_split(argv[i], ' ');
//         while (substring[j] != NULL)
//         {
//             joined[indx] = substring[j];
//             j++;
//             indx++;
//             // printf("joined: %s\n", joined[indx]);
//         }
//         i++;
//     }
//     joined[indx] = NULL;
//     return (joined);
// }

// int argc, char *argv
// int main()
// {
//     char *str1[] = {"1234  9  72", "2", "41", "50", NULL};

//     char    **result = ft_double_strjoin(str1);
//     // bool judge = check_duplicate_num(str, 4); // サイズを渡す
//     // if (judge == true)
//     //     printf("\x1b[32mSuccess!\n");
//     // else
//     //     printf("\x1b[34mFail...\n");
//     int i = 0;
//     while (result[i] != NULL)
//     {
//         printf("result: %s\n", result[i]);
//         i++;
//     }
//     return 0;
// }

int main() {
    long a = INT_MAX;
    long b = INT_MIN;
    long c = a - b;
    printf("%ld", c);
}

NAME            =   push_swap
BONUS           =   checker
LIBFT_DIR       =   libft/

SRCS            =   srcs/sort/basic_utils_list.c \
                    srcs/sort/calculate_push_cost.c \
                    srcs/sort/operation_to_a.c \
                    srcs/sort/operation_to_b.c \
                    srcs/sort/operations_list.c \
                    srcs/sort/same_operation.c \
                    srcs/sort/sort_small_stacks.c \
                    srcs/sort/rotation.c \
                    srcs/sort/error_handling.c \
                    srcs/sort/util_error_handling.c \
                    srcs/sort/setup_stack.c \
                    srcs/sort/decide_best_node.c \
                    srcs/sort/push_swap.c \
                    srcs/sort/to_substring.c

SORT_MAIN_SRCS  =   srcs/sort/gpt_test.c

GNL_SRCS        =   get_next_line/get_next_line.c \
                    get_next_line/get_next_line_utils.c

CHECKER_SRCS    =   srcs/checker/checker.c

CC              =   cc
LIBFT           =   libft/libft.a
CFLAGS          =   -Wall -Wextra -Werror

OBJS            =   $(SOURCES:%.c=%.o)

ifeq ($(BONUS_FLAG),true)
    SOURCES = $(SRCS) $(GNL_SRCS) $(CHECKER_SRCS)
else
    SOURCES = $(SRCS) $(SORT_MAIN_SRCS)
endif

$(LIBFT):
    $(MAKE) -C $(LIBFT_DIR)

%.o: %.c
    $(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT)
    $(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

$(BONUS): $(OBJS) $(LIBFT)
    $(CC) $(CFLAGS) -o $(BONUS) $(OBJS) $(LIBFT)

all: $(NAME)

bonus:
    $(MAKE) BONUS_FLAG=true $(BONUS)

clean:
    rm -f $(OBJS)
    $(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
    rm -f $(NAME) $(BONUS)
    $(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus