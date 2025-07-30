/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 18:36:39 by yazen             #+#    #+#             */
/*   Updated: 2025/06/04 20:57:49 by yazen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char * ft_strncpy(char *dest,char *src,unsigned int n){
	int i;
	i=0;
	
	while(i<n && src[i]!='\0'){
	dest[i]=src[i];
	i++;
	}
	while ( i < n){
	dest[i]='\0';
	i++;
	}
	return dest;



}
int main(void){











return 0;}
