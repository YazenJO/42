/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazan <yazan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 23:48:40 by yazan             #+#    #+#             */
/*   Updated: 2025/08/27 23:48:41 by yazan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int	ret1;
	int	ret2;

	ret1 = ft_printf("%11s", "YAZAN");
	ft_printf("\nReturn value: %d\n", ret1);
	ret2 = printf("%11s", "YAZAN");
	printf("\nReturn value: %d\n", ret2);
	return (0);
}
