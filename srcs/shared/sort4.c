/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piboidin <piboidin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 23:10:23 by piboidin          #+#    #+#             */
/*   Updated: 2022/01/20 14:38:12 by piboidin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_slist *list, t_list **from, t_list **to, t_bool display)
{
	if (ft_lstsize(*from) <= 0)
		return ;
	ft_lstadd_front_new(to,
		ft_create_stack_elem(
			((t_stack_elem *)ft_lstget(*from, 0)->content)->value));
	ft_lstremove(from, ft_destroy_stack_elem, 0);
	ft_display_action(list, *to, "p", display);
}

void	ft_lowest_to_top(t_slist *list, t_list **stack, int lowest)
{
	if (ft_get_value_index(*stack, lowest) > ft_lstsize(*stack) / 2)
	{
		while (ft_get_first_a(list) != lowest)
			ft_reverse(list, stack, TRUE);
	}
	else
	{
		while (ft_get_first_a(list) != lowest)
			ft_rotate(list, stack, TRUE);
	}
}

void	ft_fill_sorted_values(t_slist *list, t_list *stack)
{
	int	len_stack;
	int	i;
	int	*sorted_values;

	len_stack = ft_lstsize(stack);
	sorted_values = ft_calloc(len_stack, sizeof(int));
	if (sorted_values == NULL)
	{
		ft_list_destroyer(&list);
		ft_puterror();
		exit(0);
		return ;
	}
	i = -1;
	while (++i < len_stack)
		sorted_values[i] = ft_get_stack_value(stack, i);
	ft_quick_sort(sorted_values, 0, len_stack - 1);
	list->sorted_values = sorted_values;
}

void	ft_sort_4(t_slist *list)
{
	while (ft_lstsize(list->stack_a) > 3)
	{
		ft_fill_sorted_values(list, list->stack_a);
		ft_lowest_to_top(list, &list->stack_a, list->sorted_values[0]);
		free(list->sorted_values);
		list->sorted_values = NULL;
		ft_push(list, &list->stack_a, &list->stack_b, TRUE);
	}
	ft_sort_3(list);
	ft_push(list, &list->stack_b, &list->stack_a, TRUE);
	ft_push(list, &list->stack_b, &list->stack_a, TRUE);
}
