/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazan <yazan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 20:51:37 by marvin            #+#    #+#             */
/*   Updated: 2025/09/28 19:34:50 by yazan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_numbers_from_args(int argc, char **argv)
{
	if (argc == 2)
		return (count_numbers(argv[1]));
	else
		return (argc - 1);
}

int	main(int argc, char **argv)
{
	int	*numbers;
	int	count;
	int	i;

	if (validate_input(argc, argv))
	{
		numbers = ft_parse_input(argc, argv);
		if (!numbers)
		{
			return (1);
		}
		count = count_numbers_from_args(argc, argv);
		i = 0;
		while (i < count)
		{
			ft_printf("%d\n", numbers[i]);
			i++;
		}
		free(numbers);
	}
	return (0);
}
