/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_Validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazan <yazan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 20:53:41 by marvin            #+#    #+#             */
/*   Updated: 2025/09/29 00:33:35 by yazan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isspace(int c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r');
}

int	isdigits(char *str)
{
	int	i;
	int	signscount;

	signscount = 0;
	i = 0;
	while (str[i])
	{
		if (!(ft_isdigit(str[i]) || str[i] == '-' || str[i] == '+'
				|| ft_isspace(str[i])))
			return (0);
		else
		{
			if (str[i] == '-' || str[i] == '+')
			{
				signscount++;
				if (signscount > 1)
					return (0);
			}
			else
				signscount = 0;
		}
		i++;
	}
	return (1);
}

static int	ft_spaces_validation(char *str)
{
	int	i;
	int	space_count;

	i = 0;
	space_count = 0;
	while (str[i])
	{
		if (ft_isspace(str[i]))
		{
			space_count++;
			if (space_count > 1)
				return (0);
		}
		else
			space_count = 0;
		i++;
	}
	return (1);
}

static char	*convert_to_one_string(char **argv)
{
	int		i;
	char	*result;
	char	*temp;

	i = 1;
	result = ft_strdup("");
	if (!result)
		return (NULL);
	while (argv[i])
	{
		temp = ft_strjoin(result, argv[i]);
		free(result);
		if (!temp)
			return (NULL);
		result = temp;
		i++;
	}
	return (result);
}

int	validate_input(int argc, char **argv)
{
	char	*numbers;

	if (argc < 2)
		return (ft_printf("Error\n"), 0);
	if (argc > 2)
	{
		numbers = convert_to_one_string(argv);
		if (!numbers)
			return (ft_printf("Error\n"), 0);
	}
	else
		numbers = ft_strdup(argv[1]);
	if (!(isdigits(numbers) && ft_spaces_validation(numbers)))
	{
		return (ft_printf("Error\n"), 0);
	}
	return (1);
}
