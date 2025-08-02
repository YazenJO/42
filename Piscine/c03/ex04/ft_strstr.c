/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabu-sha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 14:25:44 by yabu-sha          #+#    #+#             */
/*   Updated: 2025/07/01 13:29:02 by yabu-sha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>

int	is_tofind_sub_of_str(char *str, char *to_find)
{
	int	i;

	i = 0;
	while (to_find[i])
	{
		if (str[i] != to_find[i])
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;

	i = 0;
	if (*to_find == '\0')
		return (str);
	while (str[i])
	{
		if (str[i] == to_find[0])
			if (is_tofind_sub_of_str(&str[i], to_find))
				return (&str[i]);
		i++;
	}
	return (NULL);
}
/*int	main()
{
	char str[]="Hello World AA";
	char needle[]="WorldAA";

	printf("The Standerd : %s\n",strstr(str,needle));
	printf("My Str : %s\n",ft_strstr(str,needle));
}*/
