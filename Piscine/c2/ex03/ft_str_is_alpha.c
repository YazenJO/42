/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 20:58:35 by yazen             #+#    #+#             */
/*   Updated: 2025/06/04 21:17:21 by yazen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int ft_str_is_alpha(char *str){
	int i;
	i=0;
	while(str[i]!='\0'){
		if(!(str[i]>='A' && str[i]<='Z'||str[i]>='a' && str[i]<='z'))
			return 0;
		i++;
	}
return 1;



}
int main(void){
   printf("Only letters: %d\n", ft_str_is_alpha("HelloWorld"));  // 1
    printf("With numbers: %d\n", ft_str_is_alpha("Hello123"));    // 0
    printf("With symbol:  %d\n", ft_str_is_alpha("Hi!"));         // 0
    printf("Empty string: %d\n", ft_str_is_alpha(""));            // 1
    return 0;

}
