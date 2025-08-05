/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabu-sha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 11:36:35 by yabu-sha          #+#    #+#             */
/*   Updated: 2025/06/18 18:13:23 by yabu-sha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_coma(int frst)
{
	if (frst != 7)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print_comb(void)
{
	int	frst;
	int	scnd;
	int	thrd;

	frst = 0;
	while (frst <= 7)
	{
		scnd = frst +1;
		while (scnd <= 8)
		{
			thrd = scnd +1;
			while (thrd <= 9)
			{
				ft_putchar(frst + '0');
				ft_putchar(scnd + '0');
				ft_putchar(thrd + '0');
				ft_print_coma(frst);
				thrd++;
			}
			scnd++;
		}
		frst++;
	}
}
/*int main(void)
{
	ft_print_comb();
}*/
