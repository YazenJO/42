/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 23:09:18 by marvin            #+#    #+#             */
/*   Updated: 2025/08/08 23:09:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*str;
	int		sign;
	int		len;
	long	nb;

	sign = 0;
	nb = n;
	if (nb < 0)
	{
		sign = 1;
		nb = -nb;
	}
	len = 1;
	while (nb >= 10)
	{
		nb /= 10;
		len++;
	}
	str = (char *)malloc(len + sign + 1);
	if (!str)
		return (NULL);
	str[len + sign] = '\0';
	nb = n;
	if (nb < 0)
		nb = -nb;
	while (len--)
	{
		str[len + sign] = (nb % 10) + '0';
		nb /= 10;
	}
	if (sign)
		str[0] = '-';
	return (str);
}

