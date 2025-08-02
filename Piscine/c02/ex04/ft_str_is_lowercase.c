/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabu-sha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 17:39:38 by yabu-sha          #+#    #+#             */
/*   Updated: 2025/06/21 17:44:29 by yabu-sha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}*/
int	ft_str_is_lowercase(char *str)
{
	while (*str != '\0')
	{
		if (!(*str >= 'a' && *str <= 'z'))
			return (0);
		str++;
	}
	return (1);
}
/*int main(void)
{
	char *str="ABa";
	char *str2="aaa";

	int a=ft_str_is_lowercase(str);
	int b=ft_str_is_lowercase(str2);

	ft_putchar(a+'0');
	ft_putchar(b+'0');

}*/
