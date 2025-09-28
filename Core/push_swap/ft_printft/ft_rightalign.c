/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rightalign.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazan <yazan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 14:49:19 by marvin            #+#    #+#             */
/*   Updated: 2025/08/27 23:48:26 by yazan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_rightaligncase(const char *format, va_list args, int *count)
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
	if (content_length < width)
	{
		ft_putnchar(' ', width - content_length);
		*count += (width - content_length);
	}
	*count += ft_flag(format[i], args);
}

int	ft_handle_right_align(const char *format, va_list args, int *count, int *i)
{
	ft_rightaligncase(&format[*i], args, count);
	while (ft_isdigit(format[*i]))
		(*i)++;
	(*i)++;
	return (1);
}
