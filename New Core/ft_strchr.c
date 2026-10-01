/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_strchr.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: yabusher <yazenbilal2005@gmail.com>       #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/09/22 23:10:11 by yabusher         #+#    #+#              */
/*   Updated: 2026/09/30 16:38:24 by yabusher        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *) & s[i]);
		i++;
	}
	if (s[i] == (char) c)
		return ((char *) & s[i]);
	return (NULL);
}

int	main(void)
{
	const char	*str = "Hello, World!";
	int			ch = 'W';
	char		*result = ft_strchr(str, ch);

	if (result != NULL)
		printf("Character '%c' found at position: %ld\n", ch, result - str);
	else
		printf("Character '%c' not found in the string.\n", ch);
	return (0);
}
