/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pad_zero.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 14:40:08 by marvin            #+#    #+#             */
/*   Updated: 2025/08/28 16:42:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_handle_negative_zero_pad(va_list args, int *count,
		int zeros_needed)
{
	int	num;

	num = va_arg(args, int);
	if (num < 0)
	{
		ft_putchar_fd('-', 1);
		ft_putnchar('0', zeros_needed);
		ft_putnbr_fd(-num, 1);
		*count += 1 + zeros_needed + ft_numlen(-num);
		return (1);
	}
	else
	{
		ft_putnchar('0', zeros_needed);
		ft_putnbr_fd(num, 1);
		*count += zeros_needed + ft_numlen(num);
		return (1);
	}
}

static int	ft_parse_width_and_calculate(const char *format, va_list args,
		int *zeros_needed)
{
	int		width;
	int		i;
	int		content_length;
	va_list	args_copy;

	width = 0;
	i = 0;
	while (ft_isdigit(format[i]))
	{
		width = width * 10 + (format[i] - '0');
		i++;
	}
	va_copy(args_copy, args);
	content_length = ft_calculate_content_length(format[i], args_copy);
	va_end(args_copy);
	*zeros_needed = width - content_length;
	return (i);
}

void	ft_pad_zero(const char *format, va_list args, int *count)
{
	int	zeros_needed;
	int	i;

	i = ft_parse_width_and_calculate(format, args, &zeros_needed);
	if (zeros_needed > 0 && (format[i] == 'd' || format[i] == 'i'))
	{
		ft_handle_negative_zero_pad(args, count, zeros_needed);
		return ;
	}
	if (zeros_needed > 0)
	{
		ft_putnchar('0', zeros_needed);
		*count += zeros_needed;
	}
	*count += ft_flag(format[i], args);
}

int	ft_handle_pad_zero(const char *format, va_list args, int *count, int *i)
{
	(*i)++;
	ft_pad_zero(&format[*i], args, count);
	while (ft_isdigit(format[*i]))
		(*i)++;
	(*i)++;
	return (1);
}
