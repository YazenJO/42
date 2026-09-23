/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_strrchr.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: yabusher <yazenbilal2005@gmail.com>       #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/09/23 21:24:26 by yabusher         #+#    #+#              */
/*   Updated: 2026/09/23 22:14:25 by yabusher        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libtf.h"

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
