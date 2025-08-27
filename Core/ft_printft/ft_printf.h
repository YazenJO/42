/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 10:12:08 by marvin            #+#    #+#             */
/*   Updated: 2025/08/27 14:26:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

# define FT_PRINTF_FLAGS "-0."
# define SPECIFIERS "cspdiuxX"

// Main printf functions
int		ft_printf(const char *format, ...);
void	ft_printfutil(const char *format, va_list args, int *count);
int		ft_flag(char flag, va_list args);

// Printf utility helper functions
void	ft_handle_regular_char(char c, int *count);
int		ft_handle_format_specifier(const char *format, va_list args, int *count,
			int *i);

// Utility functions from ft_utils.c
void	ft_putnbr(unsigned int n, int fd);
size_t	ft_numlen(unsigned int n);
void	ft_puthex_base(unsigned long n, char *base);

// Additional utility functions you'll need
void	ft_putptr(void *ptr);
void	ft_puthex(unsigned long n, char flag);
size_t	ft_hexlen(unsigned long n);

// Flag handling functions from ft_flags_util.c
void	ft_charcase(va_list args, int *count);
void	ft_numcase(va_list args, int *count);
void	ft_unumcase(va_list args, int *count);
void	ft_hexcase(va_list args, int *count, char flag);
void	ft_strcase(va_list args, int *count);

// Flag handling functions from ft_flags_util2.c
void	ft_ptrcase(va_list args, int *count);
void	ft_percentcase(int *count);

// Input validation functions
int		ft_validate_pointer(void *ptr);

// left alignment
void	ft_leftaligncase(const char *flag, va_list args, int *count);
void	ft_putnchar(char c, int n);
int		ft_handle_left_align(const char *format, va_list args, int *count,
			int *i);
// right alignment
int		ft_handle_right_align(const char *format, va_list args, int *count,
			int *i);
// pad zero
void	ft_pad_zero(const char *format, va_list args, int *count);
int		ft_handle_pad_zero(const char *format, va_list args, int *count,
			int *i);
// pad zero length
int		ft_get_hex_ptr_length(char specifier, va_list args);
int		ft_get_num_length(char specifier, va_list args);
int		ft_calculate_content_length(char specifier, va_list args);

// flag combinations
int		ft_parse_flags(const char *format, int *i, int *left_align,
			int *zero_pad);
int		ft_handle_combined_flags(const char *format, va_list args, int *count,
			int *i);
#endif