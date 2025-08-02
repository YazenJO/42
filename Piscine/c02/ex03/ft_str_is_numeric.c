/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabu-sha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 17:23:46 by yabu-sha          #+#    #+#             */
/*   Updated: 2025/06/21 17:37:53 by yabu-sha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}*/
int	ft_str_is_numeric(char *str)
{
	while (*str != '\0')
	{
		if (!(*str >= '0' && *str <= '9'))
			return (0);
		str++;
	}
	return (1);
}
/*int main(void)
{
	char *str="ABC";
	char *str2="234";

	int a=ft_str_is_numeric(str);
	int b=ft_str_is_numeric(str2);

	ft_putchar(a+'0');
	ft_putchar(b+'0');

}*/
