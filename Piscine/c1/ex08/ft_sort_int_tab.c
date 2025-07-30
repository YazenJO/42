/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 17:38:09 by yazen             #+#    #+#             */
/*   Updated: 2025/06/03 20:37:20 by yazen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
void	ft_swap(int *a, int *b)
{
	int	temp;

	// This instruction exchanges the values to which pointers are pointing
	temp = *a;
	*a = *b;
	*b = temp;
}

void ft_sort_int_tab(int *tab, int size){
	int i;
	int j;
	int tmp;
	i=0;
	
	while(i<size){
	j=0;
		while(j<size){
			if(tab[j] >tab[i]){
				ft_swap(&tab[j],&tab[i]);
			}
		j++;
		
		
		}
	i++;
	
	}
}
int	main(void){
int	tab[10] = {1, 4, 8, 3, 0, 5, 9, 7, 6, 2};
	int	size = 10;
	int	i;
	int	j;

	i = 0;
	j = 0;
	printf("Array before: \n");
	while (i < size)
	{
		printf("%d ", tab[i]);
		i++;
	}
	printf("\n");
	printf("\nArray after: \n");
	ft_sort_int_tab(tab, size);
	while (j < size)
        {
		printf("%d ", tab[j]);
		j++;
	}	

return 0;}
