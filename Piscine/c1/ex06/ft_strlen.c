/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 00:39:03 by yazen             #+#    #+#             */
/*   Updated: 2025/06/01 00:42:38 by yazen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str){
	int count=0;
	while(*str != 0){
		count++;
	}



return count;
}

int main(void){
	char *str="hi";
	ft_strlen(str);





return 0;
}

