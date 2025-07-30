/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 16:32:19 by yazen             #+#    #+#             */
/*   Updated: 2025/06/24 16:52:44 by yazen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char *ft_rev_print (char *str)
{
	int	i;
	int	size;
	i=0;
	size = 0;
	while (str[size])
	{
		size++;
	}
	while(size > 0)
	{
		size--;
		write(1,&str[size],1);
		
	}
	write(1,"\n",1);
	return str;

}
int main(int argc,char *argv[])
{
	ft_rev_print(argv[1]);

}
