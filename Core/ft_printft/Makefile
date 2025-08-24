NAME = libftprintf.a

SRC = ft_printf.c ft_utils.c ft_flags_util.c ft_flags_util2.c ft_putptr.c  ft_leftalign.c ft_printfutil.c

OBJ = $(SRC:.c=.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJ)

$(LIBFT):
	make -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

test: $(NAME)
	$(CC) $(CFLAGS) main.c -L. -lftprintf -o test

.PHONY: all clean fclean re test