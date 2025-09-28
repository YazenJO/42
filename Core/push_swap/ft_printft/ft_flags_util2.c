/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_util2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazan <yazan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 12:32:36 by marvin            #+#    #+#             */
/*   Updated: 2025/08/23 14:37:30 by yazan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_ptrcase(va_list args, int *count)
{
	void	*ptr;

	ptr = va_arg(args, void *);
	if (!ptr)
	{
		ft_putstr_fd("(nil)", 1);
		*count = 5;
		return ;
	}
	ft_putptr((unsigned long *)ptr);
	*count = 2 + ft_hexlen((unsigned long)ptr);
}

void	ft_percentcase(int *count)
{
	ft_putchar_fd('%', 1);
	*count = 1;
}
