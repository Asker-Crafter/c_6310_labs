NAME    = search
CC      = gcc
CFLAGS  = -Wall -Wextra -Werror -I./inc

LIBFT_DIR = ./libft
LIBFT     = $(LIBFT_DIR)/libft.a

SRC_DIR = src
SRCS    = $(SRC_DIR)/main.c
OBJS    = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
