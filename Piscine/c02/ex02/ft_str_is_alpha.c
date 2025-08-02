/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabu-sha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 17:08:10 by yabu-sha          #+#    #+#             */
/*   Updated: 2025/06/21 17:22:16 by yabu-sha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <unistd.h>
/*
void	ft_putchar(char c)
{
	write(1, &c, 1);
}*/
int	ft_str_is_alpha(char *str)
{
	while (*str != '\0')
	{
		if (!((*str >= 'a' && *str <= 'z')
				|| (*str >= 'A' && *str <= 'Z')))
			return (0);
		str++;
	}
	return (1);
}
/*int main(void)
{
	char *str="ABC";
	char *str2="1ABC";

	int a=ft_str_is_alpha(str);
	int b=ft_str_is_alpha(str2);

	ft_putchar(a+'0');
	ft_putchar(b+'0');

}*/
