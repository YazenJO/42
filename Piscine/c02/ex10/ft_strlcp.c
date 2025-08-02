/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabu-sha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 14:14:28 by yabu-sha          #+#    #+#             */
/*   Updated: 2025/06/29 14:55:59 by yabu-sha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <unistd.h>
void	ft_putchar(char c)
{
	 write(1,&c,1);
}*/
unsigned int	get_length(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	if (size > 0)
	{
		while (i < size - 1 && src[i])
		{
			dest[i] = src[i];
			i++;
		}
 	}
	dest[i] = '\0';
	return (get_length(src));
}
int main(void)
{
	char *c="aaa";
	char d[] ="ba";
	
	ft_putchar(ft_strlcpy(d,c,2)+'0');
}
