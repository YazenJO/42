/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lastword.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 19:50:58 by yazen             #+#    #+#             */
/*   Updated: 2025/06/24 22:08:15 by yazen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc,char *argv[])
{
	if(argc == 2)
	{
		int	i;
		int	end;
		int	start;
		
		i = 0;
		while(argv[1][i])
			i++;

		i--;
		while(i >= 0 && (argv[1][i] == ' ' || argv[1][i] == '\t'))
			i--;

		end = i;

		while (i >= 0 && argv[1][i] != ' ' && argv[1][i] != '\t')
			i--;

		start = i+1;

		while(start <= end)
		{
			write(1,&argv[1][start],1);
			start++;
		}
	write(1,"\n",1);	
	return  0;
}
}
