/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 14:27:56 by marvin            #+#    #+#             */
/*   Updated: 2025/08/03 18:26:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && i < n)
	{
		if (s1[i] != s2[i])
		{
			return (s2[i] - s1[i]);
		}
		i++;
	}
	return (0);
}
/*
//Test The Code
#include <stdio.h>

int	main(void) {
	const char *str1 = "Hello";
	const char *str2 = "HelloWorld";
	size_t n = 9;

	int result = ft_strncmp(str1, str2, n);
	if (result == 0) {
		printf("The first %zu characters are equal.\n", n);
	} else {
		printf("The first %zu characters are not equal. Result: %d\n", n,
			result);
	}

	return (0);
}*/
