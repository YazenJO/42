/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabu-sha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 12:56:00 by yabu-sha          #+#    #+#             */
/*   Updated: 2025/06/23 13:41:00 by yabu-sha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <unistd.h>
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		ft_putchar(*str);
		str++;
	}
}*/
int	ft_is_lowercase(char c)
{
	if (c >= 'a' && c <= 'z')
	{
		return (1);
	}
	return (0);
}

int	ft_is_uppercase(char c)
{
	if (c >= 'A' && c <= 'Z')
	{
		return (1);
	}
	return (0);
}

int	ft_is_number(char c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}

char	*ft_strlowcase(char *str)
{
	while (*str != '\0')
	{
		if (ft_is_uppercase(*str) == 1)
			*str += 32;
		str++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	ft_strlowcase(str);
	if (ft_is_lowercase(str[0]) == 1)
		str[i] -= 32;
	while (str[i])
	{
		i++;
		if ((ft_is_lowercase(str[i - 1]) == 0
				&& ft_is_uppercase(str[i - 1]) == 0
				&& ft_is_number(str[i - 1]) == 0))
			if (ft_is_lowercase(str[i]) == 1)
				str[i] -= 32;
	}
	return (str);
}
/*int main(void)
{
	char str[]="hi,how are you? 42words forty-two; fifty+and+one";

	ft_strcapitalize(str);
	ft_putstr(str);

}*/
