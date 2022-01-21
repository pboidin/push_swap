/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_new.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piboidin <piboidin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 21:40:29 by piboidin          #+#    #+#             */
/*   Updated: 2022/01/20 14:27:12 by piboidin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lst_create_elem(t_list *data)
{
	t_list	*list_elem;

	list_elem = ft_calloc(1, sizeof(t_list));
	if (list_elem == NULL)
		return (NULL);
	list_elem->next = NULL;
	list_elem->content = data;
	return (list_elem);
}

t_list	*ft_list_last(t_list *begin_list)
{
	t_list	*current;

	current = begin_list;
	if (current)
	{
		while (current->next)
			current = current->next;
		return (current);
	}
	return (NULL);
}

void	ft_list_add_back_elem(t_list **begin_list, t_list *elem)
{
	if (elem == NULL)
		return ;
	if (*begin_list)
		ft_list_last(*begin_list)->next = elem;
	else
		*begin_list = elem;
}

void	ft_lstadd_back_new(t_list **begin_list, void *data)
{
	ft_list_add_back_elem(begin_list, ft_lst_create_elem(data));
}
