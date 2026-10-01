/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_strnstr.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: yabusher <yazenbilal2005@gmail.com>       #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/09/26 21:39:30 by yabusher         #+#    #+#              */
/*   Updated: 2026/09/30 16:35:42 by yabusher        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	littile_len;

	i = 0;
	littile_len = ft_strlen(little);
	if (littile_len == 0)
		return ((char *) big);
	while (big[i] != '\0' && i + littile_len <= len)
	{
		if (ft_strncmp(&big[i], little, littile_len) == 0)
			return ((char *) & big[i]);
		i++;
	}
}
