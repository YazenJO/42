/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazan <yazan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 12:29:17 by marvin            #+#    #+#             */
/*   Updated: 2025/08/23 14:46:38 by yazan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_charcase(va_list args, int *count)
{
	ft_putchar_fd(va_arg(args, int), 1);
	*count = 1;
}

void	ft_numcase(va_list args, int *count)
{
	int	num;

	num = va_arg(args, int);
	ft_putnbr_fd(num, 1);
	*count = ft_numlen(num);
}

void	ft_hexcase(va_list args, int *count)
{
	unsigned int	hex;

	hex = va_arg(args, unsigned int);
	ft_puthex(hex, 'x');
	*count = ft_hexlen(hex);
}

void	ft_strcase(va_list args, int *count)
{
	char	*str;

	str = va_arg(args, char *);
	if (!str)
		str = "(null)";
	ft_putstr_fd(str, 1);
	*count = ft_strlen(str);
}
