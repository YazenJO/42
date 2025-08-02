/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabu-sha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 10:07:28 by yabu-sha          #+#    #+#             */
/*   Updated: 2025/07/09 17:35:33 by yabu-sha         ###   ########.fr       */
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

int	total_length(char **str, char *sep, int size)
{
	int	i;
	int	len;

	len = 0;
	i = 0;
	while (i < size)
	{
		len += ft_strlen(str[i]);
		i++;
	}
	len += (ft_strlen(sep) * (size - 1));
	return (len);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*str;
	int		i;
	int		tempc;
	int		j;

	i = 0;
	tempc = 0;
	str = malloc(total_length(strs, sep, size) + 1);
	if (!str)
		return (NULL);
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
		{
			str[tempc++] = strs[i][j++];
		}
		j = 0;
		while (sep[j] && i < size - 1)
			str[tempc++] = sep[j++];
		i++;
	}
	str[tempc] = '\0';
	return (str);
}
/*
#include <stdio.h>
int	main(void)
{
	char *str[] = {"Yaza","Bilal","AbuSharkh"};
	printf("%d",total_length(str,",$",3));
	printf("%s" ,ft_strjoin(3, str ,",$") );
}
*/
