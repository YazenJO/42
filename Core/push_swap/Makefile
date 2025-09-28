
NAME = push_swap

SRC = main.c push_swap.c input_Validation.c parsing_input.c input_validation_utils.c
OBJ = $(SRC:.c=.o)

FT_PRINTF_DIR = ft_printft
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I. -I$(FT_PRINTF_DIR)

all: $(NAME)

$(NAME): $(FT_PRINTF) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -L$(FT_PRINTF_DIR) -lftprintf -o $(NAME)

$(FT_PRINTF):
	make -C $(FT_PRINTF_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ)
	make -C $(FT_PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(FT_PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re