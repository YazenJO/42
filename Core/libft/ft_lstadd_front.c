/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 20:16:07 by marvin            #+#    #+#             */
/*   Updated: 2025/08/10 20:16:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new) //**lst  */
{
	t_list *new_node;

	new_node = ft_lstnew(new->content);
	if (!new_node)
		return ;
	new_node->next = *lst;
}
