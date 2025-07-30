/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wdmatch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 23:08:15 by yazen             #+#    #+#             */
/*   Updated: 2025/07/02 23:38:22 by yazen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		i++;
	}
	return (i);
}

void	ft_putstr(char *str)
{
        int     i;

        i = 0;
        while(str[i])
        {
		write(1 ,&str[i],1);
		i++;
        }
}
void	wdmatch(char *str,char *str2)
{
	int i = 0;
	int match = 0;
	int j = 0;
	while(str[i])
	{
		while(str2[j])
		{
			if(str[i] == str2[j])
			{
				match++;
				break;		
			}
			j++;
		}
		i++;

	}
	if(match == ft_strlen(str))
		ft_putstr(str);

}

int	main(int argc,char *argv[])
{
	if (argc == 3)
	{
		wdmatch(argv[1],argv[2]);

	}
	write(1,"\n",1);
}

