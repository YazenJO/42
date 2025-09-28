/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 21:02:10 by marvin            #+#    #+#             */
/*   Updated: 2025/08/10 22:13:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

/*
#include <stdio.h>
int main(void)
{
	t_list *list;
	t_list *last;

	list = ft_lstnew("Hello");
	ft_lstadd_back(&list, ft_lstnew("World"));
	last = ft_lstlast(list);
	if (last)
		printf("Last element: %s\n", (char *)last->content);
	return (0);
}
*/