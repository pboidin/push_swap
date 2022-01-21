/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse-rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piboidin <piboidin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 22:47:41 by piboidin          #+#    #+#             */
/*   Updated: 2022/01/20 14:35:14 by piboidin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstremove(t_list **begin_list, void (*free_fct)(void *), int i)
{
	int		l_size;
	int		previous;
	t_list	*current;

	l_size = ft_lstsize(*begin_list);
	if (l_size <= 0 || i >= l_size)
		return ;
	current = ft_lstget(*begin_list, i);
	previous = i - 1;
	if (previous == -1)
		*begin_list = current->next;
	else
		ft_lstget(*begin_list, previous)->next = current->next;
	free_fct(current->content);
	free(current);
}

void	ft_reverse(t_slist *list, t_list **stack, t_bool display)
{
	if (ft_lstsize(*stack) <= 0)
		return ;
	ft_lstadd_front_new(stack,
		ft_create_stack_elem(((t_stack_elem *)ft_lstget(*stack,
					ft_lstsize(*stack) - 1)->content)->value));
	ft_lstremove(stack, ft_destroy_stack_elem, ft_lstsize(*stack) - 1);
	ft_display_action(list, *stack, "rr", display);
}

void	ft_rotate(t_slist *list, t_list **stack, t_bool display)
{
	if (ft_lstsize(*stack) <= 0)
		return ;
	ft_lstadd_back_new(stack,
		ft_create_stack_elem(
			((t_stack_elem *)ft_lstget(*stack, 0)->content)->value));
	ft_lstremove(stack, ft_destroy_stack_elem, 0);
	ft_display_action(list, *stack, "r", display);
}
