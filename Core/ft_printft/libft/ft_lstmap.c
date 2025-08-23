/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 21:34:25 by marvin            #+#    #+#             */
/*   Updated: 2025/08/19 18:04:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	void	*new_content;

	if (!lst || !f)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		new_content = f(lst->content);
		new_node = ft_lstnew(new_content);
		if (!new_node)
		{
			if (del && new_content)
				del(new_content);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}

/*
#include "stdio.h"

void	print_list(t_list *lst)
{
	while (lst)
	{
		printf("%d\n", *(int *)lst->content);
		lst = lst->next;
	}
}
void	*increment(void *content)
{
	int	*value;
	int	*new_value;

	value = (int *)content;
	new_value = malloc(sizeof(int));
	if (new_value)
		*new_value = *value + 1;
	return (new_value);
}

void	del(void *content)
{
	free(content);
}

int	main(void)
{
	t_list	*list;
	int		values[] = {1, 2, 3, 4, 5};
	t_list	*mapped_list;

	list = NULL;
	for (size_t i = 0; i < 5; i++)
	{
		ft_lstadd_back(&list, ft_lstnew(&values[i]));
	}
	printf("Original list:\n");
	print_list(list);
	mapped_list = ft_lstmap(list, increment, del);
	printf("Mapped list:\n");
	print_list(mapped_list);
	return (0);
}
*/