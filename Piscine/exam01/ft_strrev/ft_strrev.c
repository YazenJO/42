/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 16:55:38 by yazen             #+#    #+#             */
/*   Updated: 2025/06/24 17:10:58 by yazen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	swap(char *a,char *b)
{
	char temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
char	*ft_strrev(char *str)
{
	int	i;
	int	size;
	i=0;
	size = 0;

	while(str[size])
		size++;
	
	size--;
	while (i < size)
	{
		swap(&str[i],&str[size]);
		size--;
		i++;
	}
	return (str);

}

int main(int argc,char *argv[])
{
	if (argc == 2)
        	printf("%s\n", ft_strrev(argv[1]));
    	else
        	printf("\n");
    	return 0;
}
