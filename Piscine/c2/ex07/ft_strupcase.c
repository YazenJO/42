/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 22:48:03 by yazen             #+#    #+#             */
/*   Updated: 2025/06/04 23:01:49 by yazen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int ft_is_lowercase(char chr)
{
	if(chr >='a' && chr<='z')
		return 1;
	return 0;
}
char *ft_strupcase(char *str){
	int i;
i=0;	
		while(str[i]!='\0'){
			if(ft_is_lowercase(str[i])==1){
				str[i]-=32;
				
			}
			i++;
		}
	
	return str;
} 
