/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 21:32:37 by marvin            #+#    #+#             */
/*   Updated: 2025/08/10 22:10:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

/*
# include <stdio.h>

void	print_content(void *content)
{
	printf("%s\n", (char *)content);
}

int	main(void)
{
	t_list	*list;

	list = ft_lstnew("Hello");
	ft_lstadd_back(&list, ft_lstnew("World"));
	ft_lstiter(list, print_content);
	return (0);
}
*/