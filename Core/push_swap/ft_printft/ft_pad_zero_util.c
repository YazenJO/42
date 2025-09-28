/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pad_zero_util.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 19:50:51 by marvin            #+#    #+#             */
/*   Updated: 2025/08/28 00:22:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_get_hex_ptr_length(char specifier, va_list args)
{
	unsigned int	unum;
	void			*ptr;

	if (specifier == 'x' || specifier == 'X')
	{
		unum = va_arg(args, unsigned int);
		return (ft_hexlen(unum));
	}
	if (specifier == 'p')
	{
		ptr = va_arg(args, void *);
		return (ft_hexlen((unsigned long)ptr));
	}
	return (0);
}

int	ft_get_num_length(char specifier, va_list args)
{
	int				num;
	unsigned int	unum;

	if (specifier == 'd' || specifier == 'i')
	{
		num = va_arg(args, int);
		if (num < 0)
			return (ft_numlen(-num) + 1);
		return (ft_numlen(num));
	}
	if (specifier == 'u')
	{
		unum = va_arg(args, unsigned int);
		return (ft_numlen(unum));
	}
	if (specifier == 'x' || specifier == 'X' || specifier == 'p')
		return (ft_get_hex_ptr_length(specifier, args));
	return (0);
}

int	ft_calculate_content_length(char specifier, va_list args)
{
	char	*str;

	if (specifier == 'd' || specifier == 'i' || specifier == 'u'
		|| specifier == 'x' || specifier == 'X' || specifier == 'p')
		return (ft_get_num_length(specifier, args));
	else if (specifier == 'c')
	{
		va_arg(args, int);
		return (1);
	}
	else if (specifier == 's')
	{
		str = va_arg(args, char *);
		if (!str)
			return (6);
		return (ft_strlen(str));
	}
	else if (specifier == '%')
		return (1);
	return (0);
}
