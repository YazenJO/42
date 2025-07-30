/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 00:21:27 by yazen             #+#    #+#             */
/*   Updated: 2025/07/03 00:28:25 by yazen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;

	while(str[len])
		len++;
	return (len)
}

char	*ft_strdup(char *src)
{
	char	*tmp;
	int	size;
	int	i;

	i = 0;
	size = ft_strlen(src) +1;
	*temp = (char *)malloc(sizeof(char) * size);
	while(i < size -1)
	{
		temp[i] = src[i];
		i++;
	}
	temp[i] = '\0';
	return temp;
}
