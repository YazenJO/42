/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazan <yazan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 00:42:32 by yazan             #+#    #+#             */
/*   Updated: 2025/09/29 00:54:43 by yazan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
static int check_duplicates(char *numbers)
{
    int i;
    int j;

    i = 0;
    while (numbers[i])
    {
        if (ft_strchr(&numbers[i + 1], numbers[i]))
            return (1);
        i++;
    }
    return (0);
}
