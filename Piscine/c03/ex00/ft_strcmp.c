/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabu-sha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 17:02:36 by yabu-sha          #+#    #+#             */
/*   Updated: 2025/06/30 14:20:42 by yabu-sha         ###   ########.fr       */
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

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	result;

	i = 0;
	while (s1[i] || s2[i])
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
int main(void)
{
	char *str="ABC ";
	char *str2="AB";
	int check=ft_strcmp(str,str2) ;
	
	printf("Check result : %d ",check );
	
}*/
