NAME			=	push_swap
BONUS			= 	checker
LIBFT_DIR		=	srcs/libft/

SRCS			=	srcs/sort/min_max_helper.c \
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
					srcs/sort/is_sorted.c

SORT_MAIN_SRCS	=	srcs/sort/main.c \

GNL_SRCS		=	srcs/get_next_line/get_next_line.c \
					srcs/get_next_line/get_next_line_utils.c

CHECKER_SRCS	=	srcs/checker/checker.c \
					srcs/checker/checker_util.c

GNL_OBJS		=	$(GNL_SRCS:%.c=%.o)
CHECKER_OBJS	=	$(CHECKER_SRCS:%.c=%.o)

LIBFT			=	$(LIBFT_DIR)/libft.a
CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror
OBJS			=	$(SOURCES:%.c=%.o)

ifeq ($(BONUS_FLAG),true)
		SOURCES = $(SRCS) $(CHECKER_SRCS) $(GNL_SRCS)
else
		SOURCES = $(SRCS) $(SORT_MAIN_SRCS)
endif

$(NAME): $(OBJS) $(LIBFT)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

$(LIBFT):
		$(MAKE) -C $(LIBFT_DIR)

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(BONUS): $(OBJS) $(LIBFT)
		$(CC) $(CFLAGS) -o $(BONUS) $(OBJS) $(LIBFT)

all:	$(NAME)

bonus:
		$(MAKE) BONUS_FLAG=true $(BONUS)

clean:
		rm -f $(OBJS) $(GNL_OBJS) $(CHECKER_OBJS)
		$(MAKE) -C $(LIBFT_DIR) clean

fclean:	clean
		rm -f $(NAME) $(BONUS)
		$(MAKE) -C $(LIBFT_DIR) fclean

re:		fclean all

.PHONY: all clean fclean re bonus