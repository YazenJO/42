/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_memchrr.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: yabusher <yazenbilal2005@gmail.com>       #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/09/24 22:24:35 by yabusher         #+#    #+#              */
/*   Updated: 2026/09/24 22:24:35 by yabusher        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchrr(const void *s, int c, size_t n)
{
	size_t	i;

	if (!s)
		return (NULL);
	i = n;
	while (i > 0)
	{
		i--;
		if (((unsigned char *) s)[i] == (unsigned char) c)
			return ((void *) s + i);
	}
	return (NULL);
}
