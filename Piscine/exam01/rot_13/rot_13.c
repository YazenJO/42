/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_13.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 17:52:40 by yazen             #+#    #+#             */
/*   Updated: 2025/06/24 18:51:45 by yazen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c,1);
}

void	ft_printstr(char *str)
{
	while(*str)
	{
		ft_putchar(*str);
		str++;
	}
}

int	ft_islowercase(char c)
{
	if(c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

int     ft_isuppercase(char c)
{
        if(c >= 'A' && c <= 'Z')
                return (1);
        return (0);
}

char	AddToUpper(char c)
{
	
	return(((c - 'A' +13)%26)+'A');
}

char    AddToLower(char c)
{
	return (((c - 'a' + 13) % 26) + 'a');
}
void	rot(char *str)
{
	while(*str != '\0')
	{
		if (ft_islowercase(*str) == 1)
			*str=AddToLower(*str);
		else if (ft_isuppercase(*str) == 1) 
			*str = AddToUpper(*str);

	str++;
	}
}

int	main(int argc ,char *argv[])
{
	if(argc == 2)
	{
		rot(argv[1]);
		ft_printstr(argv[1]);
	}
	write(1,"\n",1);
}
