/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piboidin <piboidin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 23:48:58 by piboidin          #+#    #+#             */
/*   Updated: 2022/01/20 14:35:49 by piboidin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_3(t_slist *list)
{
	int	first;
	int	second;
	int	third;

	first = ft_get_stack_value(list->stack_a, 0);
	second = ft_get_stack_value(list->stack_a, 1);
	third = ft_get_stack_value(list->stack_a, 2);
	if (first > second && first < third)
		ft_swap(list, list->stack_a, TRUE);
	else if (first > second && second > third)
	{
		ft_swap(list, list->stack_a, TRUE);
		ft_reverse(list, &list->stack_a, TRUE);
	}
	else if (first > second && first > third && second < third)
		ft_rotate(list, &list->stack_a, TRUE);
	else if (first < second && first < third && second > third)
	{
		ft_swap(list, list->stack_a, TRUE);
		ft_rotate(list, &list->stack_a, TRUE);
	}
	else if (first < second && first > third)
		ft_reverse(list, &list->stack_a, TRUE);
}

void	ft_sort_2(t_slist *list, t_list *stack)
{
	int	first;
	int	second;

	first = ft_get_stack_value(stack, 0);
	second = ft_get_stack_value(stack, 1);
	if (first > second)
		ft_swap(list, stack, TRUE);
}

t_bool	ft_check(t_slist *list)
{
	int	i;
	int	c;
	int	n;

	if (ft_lstsize(list->stack_b) > 0)
		return (FALSE);
	i = -1;
	while (++i < ft_lstsize(list->stack_a) - 1)
	{
		c = ft_get_stack_value(list->stack_a, i);
		n = ft_get_stack_value(list->stack_a, i + 1);
		if (c >= n)
			return (FALSE);
	}
	return (TRUE);
}

void	ft_sort(t_slist *list)
{
	if (ft_check(list))
		return ;
	if (list->size >= 500)
		ft_big_sort(list, 10);
	else if (list->size >= 100)
		ft_big_sort(list, 5);
	else if (list->size >= 50)
		ft_big_sort(list, 4);
	else if (list->size >= 6)
		ft_big_sort(list, 2);
	else if (list->size >= 4)
		ft_sort_4(list);
	else if (list->size == 3)
		ft_sort_3(list);
	else if (list->size == 2)
		ft_sort_2(list, list->stack_a);
}
