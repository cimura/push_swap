NAME			=	push_swap
BONUS			= 	checker
LIBFT_DIR		=	libft/

SRCS			=	srcs/sort/basic_utils_list.c \
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
					srcs/sort/to_substring.c \

SORT_MAIN_SRCS	=	srcs/sort/gpt_test.c \

GNL_SRCS		=	get_next_line/get_next_line.c \
					get_next_line/get_next_line_utils.c \

CC				=	cc
CHECKER_SRCS	=	srcs/checker/checker.c

LIBFT			=	libft/libft.a
CFLAGS			=	-Wall -Wextra -Werror

ifeq ($(BONUS_FLAG),true)
		SOURCES = $(SRCS) $(GNL_SRCS) $(CHECKER_SRCS)
else
		SOURCES = $(SRCS) $(SORT_MAIN_SRCS)
endif

$(LIBFT):
		$(MAKE) -C $(LIBFT_DIR)

OBJS			=	$(SOURCES:%.c=%.o)

$(NAME): $(OBJS) $(LIBFT)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

$(BONUS): $(OBJS) $(LIBFT)
		$(CC) $(CFLAGS) -o $(BONUS) $(OBJS) $(LIBFT)

all:	$(NAME)

bonus:
		$(MAKE) BONUS_FLAG=true $(BONUS)

clean:
		rm -f $(OBJS)
		$(MAKE) -C $(LIBFT_DIR) clean

fclean:	clean
		rm -f $(NAME) $(BONUS)
		$(MAKE) -C $(LIBFT_DIR) fclean

re:		fclean all

.PHONY: all clean fclean re bonus