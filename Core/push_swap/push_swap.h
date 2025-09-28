/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazan <yazan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 16:42:00 by marvin            #+#    #+#             */
/*   Updated: 2025/09/28 19:34:20 by yazan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printft/ft_printf.h"
# include "ft_printft/libft/libft.h"
# include <limits.h>

int		validate_input(int argc, char **argv);
void	print_error(void);
int		*ft_parse_input(int argc, char **argv);
int		ft_isspace(int c);
int		isdigits(char *str);
int		count_numbers_from_args(int argc, char **argv);
int		count_numbers(char *str);

#endif