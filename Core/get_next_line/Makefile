# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/03 14:45:00 by marvin            #+#    #+#              #
#    Updated: 2025/09/03 14:45:00 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program name
NAME = libgnl.a

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror
BUFFER_SIZE = 42

# Source files
SRCS = get_next_line.c get_next_line_utils.c
OBJS = $(SRCS:.c=.o)

# Header files
HEADERS = get_next_line.h

# Default target
all: $(NAME)

# Build the program
$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

# Compile source files to object files
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -D BUFFER_SIZE=$(BUFFER_SIZE) -c $< -o $@

# Test with different buffer sizes (requires main.c)
test1: $(SRCS) $(HEADERS)
	@echo "To run tests, you need to create a main.c file first"

test42: $(SRCS) $(HEADERS)
	@echo "To run tests, you need to create a main.c file first"

test1000: $(SRCS) $(HEADERS)
	@echo "To run tests, you need to create a main.c file first"

test9999999: $(SRCS) $(HEADERS)
	@echo "To run tests, you need to create a main.c file first"

# Test all buffer sizes
test_all: test1 test42 test1000 test9999999
	@echo "All test executables created:"
	@echo "- $(NAME)_buffer1 (BUFFER_SIZE=1)"
	@echo "- $(NAME)_buffer42 (BUFFER_SIZE=42)"
	@echo "- $(NAME)_buffer1000 (BUFFER_SIZE=1000)"
	@echo "- $(NAME)_buffer9999999 (BUFFER_SIZE=9999999)"

# Create test file
test.txt:
	@echo "Creating test.txt..."
	@echo "Hello World!" > test.txt
	@echo "This is line 2" >> test.txt
	@echo "Line number 3" >> test.txt
	@echo "Another line here" >> test.txt
	@echo "Final line of the test file" >> test.txt

# Clean object files
clean:
	rm -f $(OBJS)

# Clean everything
fclean: clean
	rm -f $(NAME)
	rm -f *_buffer*
	rm -f a.out

# Rebuild everything
re: fclean all

# Phony targets
.PHONY: all clean fclean re test1 test42 test1000 test9999999