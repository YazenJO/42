/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 19:05:01 by yazen             #+#    #+#             */
/*   Updated: 2025/06/25 00:40:55 by yazen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_has_char(char *str, char c, int limit)
{
    int i = 0;
    while (i < limit)
    {
        if (str[i] == c)
            return 1;
        i++;
    }
    return 0;
}

int	main(int argc,char *argv[])
{
	if(argc == 3){
		int	i;
		int	j;
		char 	c;

		j = 0;
		i = 0;
		while(argv[1][i])
		{
			c=argv[1][i];
			if(!ft_has_char(argv[1],c,i))
			{
			j=0;
			while(argv[2][j])
			{
				if(argv[2][j] == c)
				{
				write(1,&c,1);//looking for the first occurrence of the characte
					break;
				}
				j++;
			}
			}
			i++;
		}
	}
	write(1,"\n" ,1);
}
