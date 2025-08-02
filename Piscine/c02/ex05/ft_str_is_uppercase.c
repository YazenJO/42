/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabu-sha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 17:45:39 by yabu-sha          #+#    #+#             */
/*   Updated: 2025/06/21 17:48:42 by yabu-sha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}*/
int	ft_str_is_uppercase(char *str)
{
	while (*str != '\0')
	{
		if (!(*str >= 'A' && *str <= 'Z'))
			return (0);
		str++;
	}
	return (1);
}
/*int main(void)
{
	char *str="ABA";
	char *str2="aaa";

	int a=ft_str_is_lowercase(str);
	int b=ft_str_is_lowercase(str2);

	ft_putchar(a+'0');
	ft_putchar(b+'0');

}*/
