/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 10:12:05 by marvin            #+#    #+#             */
/*   Updated: 2025/08/28 15:13:46 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, format);
	ft_printfutil(format, args, &count);
	va_end(args);
	return (count);
}

int	ft_flag(char flag, va_list args)
{
	int	count;

	count = 0;
	if (flag == 'c')
		ft_charcase(args, &count);
	else if (flag == 'd' || flag == 'i')
		ft_numcase(args, &count);
	else if (flag == 's')
		ft_strcase(args, &count);
	else if (flag == '%')
		ft_percentcase(&count);
	else if (flag == 'u')
		ft_unumcase(args, &count);
	else if (flag == 'x' || flag == 'X')
		ft_hexcase(args, &count, flag);
	else if (flag == 'p')
		ft_ptrcase(args, &count);
	return (count);
}
