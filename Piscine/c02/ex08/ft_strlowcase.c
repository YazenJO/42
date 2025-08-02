/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabu-sha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 18:34:00 by yabu-sha          #+#    #+#             */
/*   Updated: 2025/06/23 13:04:07 by yabu-sha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <unistd.h>

/*void	ft_putchar(char c)
{
	write(1, &c, 1);
}*/
int	ft_is_uppercase(char c)
{
	if ((c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}
/*void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		ft_putchar(*str);
		str++;
	}
}*/

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_is_uppercase(str[i]) == 1)
			str[i] += 32;
		i++;
	}
	return (str);
}
/*int main(void)
{
	char str[]="aBc";
	
	ft_strlowcase(str);
	ft_putstr(str);

}*/
