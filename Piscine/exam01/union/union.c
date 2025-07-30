/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 23:06:05 by yazen             #+#    #+#             */
/*   Updated: 2025/06/25 00:26:04 by yazen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
int	ft_is_apperd(char *str, char c, int limit)
{
	int	i;

	i = 0;
	while(i < limit)
	{
		if(str[i] == c)
			return 1;
		i++;
	}
	return 0;
}

int	ft_str_isappered(char *str,char c)
{
	 int     i;

        i = 0;
        while(str[i])
        {
                if(str[i] == c)
                        return 1;
                i++;
        }
        return 0;
}

void	ft_union(char *str1,char *str2)
{
	int	i;

	i = 0;
	while(str1[i])
	{
		 if(!ft_is_apperd(str1,str1[i],i))
			 write(1,&str1[i],1);
		 i++;
	}
	i = 0;
	while(str2[i]){
	if(!ft_is_apperd(str2,str2[i],i) && !ft_str_isappered(str1,str2[i]))
	{
		 write(1,&str2[i],1);
	}
	i++;
	}
}
int	main(int argc,char *argv[])
{
	if(argc == 3)
	{
	ft_union(argv[1],argv[2]);
	}
	write(1,"\n",1);
}
