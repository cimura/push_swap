NAME		=	push_swap
LIBFT_DIR	=	libft/
SRCS_DIR	=	src/
SRCS		=	srcs/sort/basic_utils_list.c \
				srcs/sort/calculate_push_cost.c \
				srcs/sort/gpt_test.c \
				srcs/sort/operation_to_a.c \
				srcs/sort/operation_to_b.c \
				srcs/sort/operations_list.c \
				srcs/sort/same_operation.c \
				srcs/sort/three_numbers.c \
				srcs/sort/rotation.c \
				srcs/sort/error_handling.c \
				srcs/sort/setup_stack.c \
				srcs/sort/decide_best_node.c

LIBFT		=	$(LIBFT_DIR)/libft.a
OBJS		=	$(SRCS:%.c=%.o)
CFLAGS		=	-Wall -Wextra -Werror

$(NAME): $(OBJS) $(LIBFT)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

$(LIBFT):
		$(MAKE) -C $(LIBFT_DIR)
	
run:
		$(CC) $(CFLAGS) main.c -L. -lsort -L(LIBFT_DIR) -lft -o sort

all:	$(NAME)

$(SRCS_DIR)/%.o: $(SRCS_DIR)/%.c
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		rm -f $(OBJS)
		$(MAKE) -C $(LIBFT_DIR) clean

fclean:	clean
		rm -f $(NAME)
		$(MAKE) -C $(LIBFT_DIR) fclean

re:		fclean all

.PHONY: all clean fclean re