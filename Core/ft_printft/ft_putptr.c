/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 12:12:17 by marvin            #+#    #+#             */
/*   Updated: 2025/08/23 13:34:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex(unsigned long n, char flag)
{
	char	*base;

	if (flag == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	ft_puthex_base(n, base);
}

void	ft_putptr(void *ptr)
{
	char	*sign;

	sign = "0x";
	if (!ptr)
		return ;
	ft_putstr_fd(sign, 1);
	ft_puthex((unsigned long)ptr, 'x');
}
