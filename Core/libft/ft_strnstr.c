/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_strnstr.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: yabusher <yazenbilal2005@gmail.com>       #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2025/08/03 14:39:29 by yabusher         #+#    #+#              */
/*   Updated: 2026/09/26 21:44:03 by yabusher        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	little_len;

	i = 0;
	little_len = ft_strlen(little);
	if (little[0] == '\0')
		return ((char *) big);
	while (big[i] && i + little_len <= len)
	{
		if (ft_strncmp(&big[i], little, little_len) == 0)
			return ((char *) & big[i]);
		i++;
	}
	return (NULL);
}
