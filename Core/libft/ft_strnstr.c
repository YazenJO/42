/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 14:39:29 by marvin            #+#    #+#             */
/*   Updated: 2025/08/08 17:28:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* [1] function locates the first
	occurrence of the  null-terminated
		string little in the string big*/
// [2] where not more than len characters are searched
// [3] Characters that appear after	a `\0'	character  are not  searched

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	little_len;

	i = 0;
	little_len = ft_strlen(little);
	if (little[0] == '\0')
		return ((char *)big);
	while (big[i] && i + little_len <= len)
	{
		if (ft_strncmp(&big[i], little, little_len) == 0)
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}
