NAME		=	push_swap.a
LIBFT_DIR	=	./libft
LIBFT		=	$(LIBFT_DIR)/libft.a
SRCS_DIR	=	./src
SRCS		=	$(wildcard $(SRCS_DIR)/*.c)
OBJS		=	$(patsubst $(SRCS:%.c=%.o),$(SRCS_DIR)/%.o,$(SRCS))
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror

$(LIBFT):
		$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
		ar -x $(LIBFT)
		ar rcs $@ $(OBJS) *.o
	
run:
		$(CC) $(CFLAGS) main.c -L. -lpush_swap -L(LIBFT_DIR) -lft -o push_swap

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