/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 23:41:46 by yazen             #+#    #+#             */
/*   Updated: 2025/07/03 00:05:18 by yazen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include <stdio.h>
 #include <stdlib.h>
int	ft_atoi(char *str)
{
	int	sum;
	int	i;
	int	sign;

	sum = 0;
	i = 0;
	sign = 1;

	while(str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	while(str[i] >= '0' && str[i] <= '9')
	{
		sum = sum *10 + str[i] - '0';
		i++;
	}
	return (sum * sign);
}
 
int	main(void)
{
	char *n = "     -1234ab567";

	// The original atoi is in the Library <stdlib.h>
	printf("Or: %d\n", atoi(n));
	printf("My: %d\n", ft_atoi(n));
} 
