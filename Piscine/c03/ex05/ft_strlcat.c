/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabu-sha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 17:39:15 by yabu-sha          #+#    #+#             */
/*   Updated: 2025/07/02 14:24:56 by yabu-sha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bsd/string.h>
#include <stdio.h>
unsigned int	ft_strlen(char *dest)
{
	unsigned int	i;

	i = 0;
	while (dest[i])
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dest_len;
	unsigned int	src_len;
	unsigned int	space_left;
	unsigned int	i;

	i = 0;
	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	space_left = size - dest_len - 1;
	if (size <= dest_len)
		return (size + src_len);
	while (i < space_left && src[i])
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest_len + src_len);
}

int	main()
{
	char c[]="DEF";
	char c2[]="BC";
	
	printf("The length : %u \n",ft_strlcat(c2,c,5));
	printf("The Standerd : %zu \n",strlcat(c2,c,5));

	printf("%s\n",c2);
	///printf("%s",c);
}
