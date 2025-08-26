/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_combinations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 15:45:00 by marvin            #+#    #+#             */
/*   Updated: 2025/08/26 15:45:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parse_flags(const char *format, int *i, int *left_align, int *zero_pad)
{
	*left_align = 0;
	*zero_pad = 0;
	while (format[*i] == '-' || format[*i] == '0')
	{
		if (format[*i] == '-')
			*left_align = 1;
		else if (format[*i] == '0')
			*zero_pad = 1;
		(*i)++;
	}
	return (*left_align || *zero_pad);
}

int	ft_handle_combined_flags(const char *format, va_list args, int *count, int *i)
{
	int	left_align;
	int	zero_pad;

	if (!ft_parse_flags(format, i, &left_align, &zero_pad))
		return (0);
	if (left_align)
	{
		(*i)--;
		ft_handle_left_align(format, args, count, i);
		return (1);
	}
	else if (zero_pad)
	{
		(*i)--;
		ft_handle_pad_zero(format, args, count, i);
		return (1);
	}
	return (0);
}
