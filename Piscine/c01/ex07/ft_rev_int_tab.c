/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabu-sha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 17:56:02 by yabu-sha          #+#    #+#             */
/*   Updated: 2025/06/20 18:44:59 by yabu-sha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(int *str)
{
	while (*str != '\0')
	{
		ft_putchar(*str + '0');
		str++;
	}
}
*/
void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	j = size - 1;
	size--;
	while (i < j)
	{
		ft_swap(&tab[i], &tab[j]);
		j--;
		i++;
	}
}
/*int main(void)
{
	int a[] = {1, 2, 3, 4, 5, 6, 7};

	ft_rev_int_tab(a,7);

	ft_putstr(a);

}*/
