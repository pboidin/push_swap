/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_destroyer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piboidin <piboidin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 22:48:47 by piboidin          #+#    #+#             */
/*   Updated: 2022/01/20 14:26:40 by piboidin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_destroy_stack_elem(void *stack_elem)
{
	free(stack_elem);
}

void	ft_lstclear(t_list *lst, void (*free_fct)(void*))
{
	t_list	*current;
	t_list	*next;

	current = lst;
	next = NULL;
	while (current)
	{
		next = current->next;
		free_fct(current->content);
		free(current);
		current = next;
	}
}

void	*ft_list_destroyer(t_slist **list)
{
	ft_lstclear((*list)->stack_a, ft_destroy_stack_elem);
	(*list)->stack_a = NULL;
	ft_lstclear((*list)->stack_b, ft_destroy_stack_elem);
	(*list)->stack_b = NULL;
	free((*list)->sorted_values);
	(*list)->sorted_values = NULL;
	free((*list)->parts_limits);
	(*list)->parts_limits = NULL;
	free(*list);
	list = NULL;
	return (NULL);
}
