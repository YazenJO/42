/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazan <yazan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 16:42:00 by marvin            #+#    #+#             */
/*   Updated: 2025/09/29 00:20:12 by yazan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_numbers(char *str)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t'))
			i++;
		if (str[i] && (ft_isdigit(str[i]) || str[i] == '-' || str[i] == '+'))
		{
			count++;
			while (str[i] && !ft_isspace(str[i]))
				i++;
		}
	}
	return (count);
}

static int	*parse_from_string(char *str, int count)
{
	int	*numbers;
	int	i;
	int	j;
	int	start;

	numbers = malloc(sizeof(int) * count);
	if (!numbers)
		return (ft_printf("Error\n"), NULL);
	i = 0;
	j = 0;
	while (str[i] && j < count)
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t'))
			i++;
		if (str[i] && (ft_isdigit(str[i]) || str[i] == '-' || str[i] == '+'))
		{
			start = i;
			while (str[i] && !ft_isspace(str[i]))
				i++;
			numbers[j] = ft_atoi(&str[start]);
			j++;
		}
	}
	return (numbers);
}

static int	*parse_from_argv(int argc, char **argv, int *count)
{
	int	j;
	int	*numbers;

	(void)argc;
	j = 0;
	numbers = malloc(sizeof(int) * (*count));
	if (!numbers)
		return (ft_printf("Error\n"), NULL);
	while (j < *count)
	{
		numbers[j] = ft_atoi(argv[j + 1]);
		j++;
	}
	return (numbers);
}

int	*ft_parse_input(int argc, char **argv)
{
	int	count;
	int	*numbers;

	count = 0;
	if (argc == 2)
	{
		count = count_numbers(argv[1]);
		if (count == 0)
			return (ft_printf("Error\n"), NULL);
		numbers = parse_from_string(argv[1], count);
	}
	else
	{
		count = argc - 1;
		numbers = parse_from_argv(argc, argv, &count);
	}
	if (!numbers)
		return (ft_printf("Error\n"), NULL);
	return (numbers);
}

