/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfutil.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 14:32:17 by marvin            #+#    #+#             */
/*   Updated: 2025/08/28 15:13:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_handle_regular_char(char c, int *count)
{
	ft_putchar_fd(c, 1);
	(*count)++;
}

int	ft_handle_format_specifier(const char *format, va_list args, int *count,
		int *i)
{
	(*i)++;
	if (ft_handle_combined_flags(format, args, count, i))
		return (1);
	*count += ft_flag(format[*i], args);
	return (0);
}

void	ft_printfutil(const char *format, va_list args, int *count)
{
	int	i;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (ft_handle_format_specifier(format, args, count, &i))
				continue ;
		}
		else
			ft_handle_regular_char(format[i], count);
		i++;
	}
}
