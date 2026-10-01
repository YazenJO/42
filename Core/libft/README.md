*This project has been created as part of the 42 curriculum by yabusher.*

# Libft

## Description

Libft is my first C library: a static archive (`libft.a`) that re-implements a
set of standard libc functions and adds extra string, output and linked-list
helpers. The goal is to understand how these basic functions work internally
and to reuse the library in later 42 projects.

## Instructions

```bash
make        # builds libft.a
make clean  # removes object files
make fclean # removes object files and libft.a
make re     # rebuilds everything
```

To use it in a program:

```bash
cc -Wall -Wextra -Werror main.c -L. -lft
```

and add `#include "libft.h"` to your source.

## Library contents

### Part 1 — Libc functions


| Function                                                             | Description                                              |
| -------------------------------------------------------------------- | -------------------------------------------------------- |
| `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint` | Character classification; return 1 on match, 0 otherwise |
| `ft_toupper`, `ft_tolower`                                           | Convert letter case                                      |
| `ft_strlen`                                                          | Length of a string                                       |
| `ft_strchr`, `ft_strrchr`                                            | First / last occurrence of a character in a string       |
| `ft_strncmp`                                                         | Compare up to`n` characters of two strings               |
| `ft_strnstr`                                                         | Find a substring within the first`len` characters        |
| `ft_strlcpy`, `ft_strlcat`                                           | Size-bounded string copy / concatenation                 |
| `ft_atoi`                                                            | Convert a string to an`int`                              |
| `ft_memset`, `ft_bzero`                                              | Fill memory with a byte / with zeros                     |
| `ft_memcpy`, `ft_memmove`                                            | Copy memory (`memmove` handles overlapping areas)        |
| `ft_memchr`, `ft_memcmp`                                             | Search / compare memory areas                            |
| `ft_calloc`                                                          | Allocate zero-initialised memory                         |
| `ft_strdup`                                                          | Allocate a copy of a string                              |

### Part 2 — Additional functions


| Function                                                         | Description                                                             |
| ---------------------------------------------------------------- | ----------------------------------------------------------------------- |
| `ft_substr`                                                      | Allocate a substring of`s` starting at `start`, at most `len` long      |
| `ft_strjoin`                                                     | Allocate the concatenation of two strings                               |
| `ft_strtrim`                                                     | Allocate a copy of a string with`set` characters removed from both ends |
| `ft_split`                                                       | Split a string on a delimiter into a NULL-terminated array of strings   |
| `ft_itoa`                                                        | Allocate the string representation of an`int`                           |
| `ft_strmapi`                                                     | Allocate a new string built by applying`f` to each character            |
| `ft_striteri`                                                    | Apply`f` to each character of a string in place                         |
| `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd` | Write a char / string / string + newline / integer to a file descriptor |

### Part 3 — Linked list

Uses the `t_list` structure (`void *content`, `t_list *next`).


| Function                            | Description                                                     |
| ----------------------------------- | --------------------------------------------------------------- |
| `ft_lstnew`                         | Allocate a new node                                             |
| `ft_lstadd_front`, `ft_lstadd_back` | Add a node at the start / end of a list                         |
| `ft_lstsize`                        | Count the nodes of a list                                       |
| `ft_lstlast`                        | Return the last node                                            |
| `ft_lstdelone`                      | Free one node and its content                                   |
| `ft_lstclear`                       | Free a whole list and set the pointer to NULL                   |
| `ft_lstiter`                        | Apply a function to every node's content                        |
| `ft_lstmap`                         | Build a new list by applying a function to every node's content |

## Resources

- `man 3` pages for each libc function (`man 3 strlcpy`, `man 3 memmove`, …)
- The 42 Norm (norminette) documentation
- GNU Make manual: https://www.gnu.org/software/make/manual/
- `ar(1)` man page for building static libraries
