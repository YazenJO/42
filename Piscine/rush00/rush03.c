/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 10:38:59 by yazen             #+#    #+#             */
/*   Updated: 2025/06/20 11:56:41 by yazen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void rush(int width, int height) {
    int h = 1;
    int w = 1;

    while (h <= height) {
        w = 1;
        while (w <= width) {
		if((h==1 || h== height) && w==1)
			ft_putchar('A');
		else if((h==1 || h== height) && w== width)
			ft_putchar('C');
		else if((h  >1 && h< height) && (w > 1 && w< width))
			ft_putchar(' ');
			else
			ft_putchar('B');
            w++;
        }
        ft_putchar('\n'); 
        h++;
    }
}
