/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabu-sha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 18:43:02 by yabu-sha          #+#    #+#             */
/*   Updated: 2025/07/09 16:36:59 by yabu-sha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_range(int **range, int min, int max)
{
	int	i;
	int	*arr;
	int	len;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	i = 0;
	len = max - min;
	arr = (int *)malloc(sizeof(int) * (len));
	if (!arr)
	{
		return (-1);
	}
	else
	{
		while (min < max)
			arr[i++] = min++;
	}
	*range = arr;
	return (len);
}
/*
#include <stdio.h>
int	main()
{
	int *arr;
	int	length;

	length = ft_range(&arr,3,6);
	printf("%d",length);
}*/
