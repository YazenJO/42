/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 21:54:40 by yazen             #+#    #+#             */
/*   Updated: 2025/07/02 22:19:28 by yazen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
int	appeared_before(char *str,char c,int pos)
{
	int	i;

	i = 0;

	while(i < pos)
	{
		if(str[i] == c)
			return 1;
		i++;
	}
	return (0);
}
void	inter(char *s1, char *s2)
{
	int	i = 0;
	int	j;

	// runs the two strings index by index
	while (s1[i])
	{
		// 'J' always returns to the beginning
		j = 0;
		while (s2[j])
		{
			// If what is in s1 is equal to s2
			if (s1[i] == s2[j])
			{
				// If the character didn't appear before, it is printed
				if (!appeared_before(s1, s1[i], i))
				{
					write(1, &s1[i], 1);

					// Get out of the current loop
					break ;
				}
			}
			j++;
		}
		i++;
	}
}

int	main(int argc,char *argv[])
{
	if(argc == 3)
	{
		//inter(argv[1],argv[2]);
		int	i;
		int	j;

		i = 0;
		while(argv[1])
		{
			j = 0;
			while(argv[2])
			{
				if(argv[1][i] == argv[2][j])
                                {
					if(!appeared_before(argv[1],argv[1][i],i))
					{
						write(1,&argv[1][i],1);
						break;	
					}
				}
				j++;
			}
			i++;
		}
	}
	write(1, "\n", 1);
}
