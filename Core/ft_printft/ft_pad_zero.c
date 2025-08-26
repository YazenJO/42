/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pad_zero.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 14:40:08 by marvin            #+#    #+#             */
/*   Updated: 2025/08/26 14:40:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_get_num_length(char specifier, va_list args)
{
    if (specifier == 'd' || specifier == 'i')
    {
        int num = va_arg(args, int);
        if (num < 0)
            return ft_numlen(-num) + 1;
        else
            return ft_numlen(num);
    }
    else if (specifier == 'u')
    {
        unsigned int num = va_arg(args, unsigned int);
        return ft_numlen(num);
    }
    else if (specifier == 'x' || specifier == 'X')
    {
        unsigned int hex = va_arg(args, unsigned int);
        return ft_hexlen(hex);
    }
    else if (specifier == 'p')
    {
        void *ptr = va_arg(args, void *);
        return ft_hexlen((unsigned long)ptr);
    }
    return 0;
}

int ft_calculate_content_length(char specifier, va_list args)
{
    if (specifier == 'd' || specifier == 'i' || specifier == 'u' 
        || specifier == 'x' || specifier == 'X'|| specifier == 'p')
        return ft_get_num_length(specifier, args);
    else if (specifier == 'c')
    {
        va_arg(args, int);
        return 1;
    }
    else if (specifier == 's')
    {
        char *str = va_arg(args, char *);
        if (!str)
            return 6;
        return ft_strlen(str);
    }
    else if (specifier == '%')
        return 1;
    return 0;
}

void    ft_pad_zero(const char *format, va_list args, int *count)
{
    int width;
    int i;
    int content_length;
    int zeros_needed;
    va_list args_copy;

    width = 0;
    i = 0;
    while (ft_isdigit(format[i]))
    {
        width = width * 10 + (format[i] - '0');
        i++;
    }
    va_copy(args_copy, args);
    content_length = ft_calculate_content_length(format[i], args_copy);
    va_end(args_copy);
    zeros_needed = width - content_length;
    if (zeros_needed > 0)
    {
        ft_putnchar('0', zeros_needed);
        *count += zeros_needed;
    }
    *count += ft_flag(format[i], args);
}

int     ft_handle_pad_zero(const char *format, va_list args, int *count, int *i)
{
    (*i)++;
    ft_pad_zero(&format[*i], args, count);
    while (ft_isdigit(format[*i]))
        (*i)++;
    (*i)++;
    return (1);
}

   
