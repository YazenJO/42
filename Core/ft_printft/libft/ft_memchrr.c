/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchrr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 22:52:25 by marvin            #+#    #+#             */
/*   Updated: 2025/08/08 22:52:25 by marvin           ###   ########.fr       */
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
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return ((void *)s + i);
	}
	return (NULL);
}
