/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabu-sha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 17:28:00 by yabu-sha          #+#    #+#             */
/*   Updated: 2025/07/09 16:10:18 by yabu-sha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int		len;
	char	*temp;
	int		i;

	i = 0;
	len = ft_strlen(src) + 1;
	temp = (char *) malloc(len);
	if (!temp)
		return (NULL);
	while (i < len)
	{
		temp[i] = src[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}
/*
#include <stdio.h>
int	main()
{
	char str[] = "ABC";
	printf("%s",ft_strdup(str));

}*/
