/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_leftalign.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 13:38:23 by marvin            #+#    #+#             */
/*   Updated: 2025/08/24 13:38:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnchar(char c, int n)
{
	while (n-- > 0)
		ft_putchar_fd(c, 1);
}

void	ft_leftaligncase(const char *format, va_list args, int *count)
{
	int	width;
	int	i;
	int	start_count;
	int	content_length;

	width = 0;
	i = 0;
	while (ft_isdigit(format[i]))
	{
		width = width * 10 + (format[i] - '0');
		i++;
	}
	start_count = *count;
	*count += ft_flag(format[i], args);
	content_length = *count - start_count;
	if (content_length < width)
	{
		ft_putnchar(' ', width - content_length);
		*count += (width - content_length);
	}
}

int	ft_handle_left_align(const char *format, va_list args, int *count, int *i)
{
	(*i)++;
	ft_leftaligncase(&format[*i], args, count);
	while (ft_isdigit(format[*i]))
		(*i)++;
	(*i)++;
	return (1);
}
