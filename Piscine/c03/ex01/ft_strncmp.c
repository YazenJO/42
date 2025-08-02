/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabu-sha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 13:54:42 by yabu-sha          #+#    #+#             */
/*   Updated: 2025/06/30 15:35:56 by yabu-sha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_comp(char c1, char c2)
{
	if (c1 == c2)
		return (0);
	else
		return (c1 - c2);
}

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;
	unsigned int	result;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n && (s1[i] || s2[i]))
	{
		result = ft_comp(s1[i], s2[i]);
		if ((result != 0))
		{
			return (ft_comp(s1[i], s2[i]));
		}
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	char *c="ABC";
	char *c1="AB";

		printf("The Result =  %d",ft_strncmp(c,c1,4));
}*/
