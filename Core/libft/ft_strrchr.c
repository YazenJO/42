/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_strrchr.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: yabusher <yazenbilal2005@gmail.com>       #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2025/08/02 20:59:31 by yabusher         #+#    #+#              */
/*   Updated: 2026/09/26 20:32:43 by yabusher        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*p;

	p = NULL;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
		{
			p = (char *) & s[i];
		}
		i++;
	}
	if ((char) c == '\0')
	{
		return ((char *) & s[i]);
	}
	return (p);
}
