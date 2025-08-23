/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 10:45:34 by marvin            #+#    #+#             */
/*   Updated: 2025/08/23 16:11:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(unsigned int n, int fd)
{
	if (n >= 10)
		ft_putnbr(n / 10, fd);
	ft_putchar_fd((n % 10) + '0', fd);
}

size_t	ft_numlen(unsigned int n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

size_t	ft_hexlen(unsigned long n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}

void	ft_puthex_base(unsigned long n, char *base)
{
	if (n == 0)
	{
		ft_putchar_fd('0', 1);
		return ;
	}
	if (n >= 16)
		ft_puthex_base(n / 16, base);
	ft_putchar_fd(base[n % 16], 1);
}
