/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabu-sha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 17:49:45 by yabu-sha          #+#    #+#             */
/*   Updated: 2025/06/21 18:03:01 by yabu-sha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}*/
int	ft_str_is_printable(char *str)
{
	while (*str != '\0')
	{
		if (!(*str >= 32 && *str <= 126))
			return (0);
		str++;
	}
	return (1);
}
/*int main(void)
{
	char *str="\n";
	char *str2="aaa";

	int a=ft_str_is_printable(str);
	int b=ft_str_is_printable(str2);

	ft_putchar(a+'0');
	ft_putchar(b+'0');

}*/
