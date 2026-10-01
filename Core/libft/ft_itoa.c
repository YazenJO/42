/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_itoa.c                                         :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: yabusher <yazenbilal2005@gmail.com>       #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2025/08/08 23:09:18 by yabusher         #+#    #+#              */
/*   Updated: 2026/09/26 20:32:16 by yabusher        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_num_len(long n)
{
	int	len;

	len = 1;
	while (n >= 10)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		sign;
	long	nb;

	sign = 0;
	if (n == 0)
		return (ft_strdup("0"));
	nb = n;
	if (nb < 0)
	{
		sign = 1;
		nb = -nb;
	}
	str = (char *) malloc(get_num_len(nb) + 1 + sign);
	if (!str)
		return (NULL);
	if (sign)
		str[0] = '-';
	str[get_num_len(nb) + sign] = '\0';
	while (nb > 0)
	{
		str[get_num_len(nb) + sign - 1] = (nb % 10) + '0';
		nb /= 10;
	}
	return (str);
}
