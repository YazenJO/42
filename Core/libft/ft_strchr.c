/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 21:18:44 by marvin            #+#    #+#             */
/*   Updated: 2025/08/02 21:18:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
		{
			return ((char *)&s[i]);
		}
		i++;
	}
	if (c == '\0')
	{
		return ((char *)&s[i]);
	}
	return (NULL);
}

/*
#include <stdio.h>

int	main(void)
{
	const char *str = "Hello, World!";
	int c = 'o';
	char *result;

	result = ft_strchr(str, c);
	if (result != NULL)
		printf("First occurrence of '%c': %s\n", c, result);
	else
		printf("Character '%c' not found in the string.\n", c);

	return (0);
}*/
