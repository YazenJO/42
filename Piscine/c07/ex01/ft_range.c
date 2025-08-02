/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabu-sha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 18:02:54 by yabu-sha          #+#    #+#             */
/*   Updated: 2025/07/09 17:48:09 by yabu-sha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*arr;
	int	len;

	if (min >= max)
		return (NULL);
	i = 0;
	len = max - min;
	arr = (int *) malloc(sizeof(int) * (len));
	if (arr == NULL)
		return (NULL);
	while (i < len)
	{
		arr[i] = min + i;
		i++;
	}
	return (arr);
}
/*
#include <stdio.h>

int main()
{
	int	*temp = ft_range(1 , 8);
	int i;
	i = 0;
	while(temp[i])
	{
		printf("%d",temp[i]);
		i++;
	}


}*/
