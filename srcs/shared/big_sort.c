/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piboidin <piboidin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 23:48:11 by piboidin          #+#    #+#             */
/*   Updated: 2022/01/20 14:22:23 by piboidin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_fill_parts_limits(t_slist *list, int part)
{
	int	i;
	int	*sorted_values;
	int	*parts_limits;
	int	parts_values;

	sorted_values = list->sorted_values;
	parts_limits = ft_calloc(part, sizeof(int));
	if (parts_limits == NULL)
	{
		ft_list_destroyer(&list);
		ft_puterror();
		exit(0);
		return ;
	}
	parts_values = list->size / part;
	i = -1;
	while (++i < part - 1)
		parts_limits[i] = sorted_values[parts_values * (i + 1)];
	parts_limits[i] = sorted_values[list->size - 1];
	list->parts_limits = parts_limits;
}

static void	ft_push_parts(t_slist *list, int part)
{
	int	parts_limits_i;
	int	stack_size;
	int	i;
	int	a;

	parts_limits_i = -1;
	while (++parts_limits_i < part)
	{
		if (ft_lstsize(list->stack_a) <= 3)
			break ;
		stack_size = ft_lstsize(list->stack_a);
		i = -1;
		while (++i < stack_size)
		{
			if (ft_lstsize(list->stack_a) <= 3)
				break ;
			a = ft_get_first_a(list);
			if (a < list->parts_limits[parts_limits_i])
				ft_push(list, &list->stack_a, &list->stack_b, TRUE);
			else
				ft_rotate(list, &list->stack_a, TRUE);
		}
	}
}

static int	ft_sort_behaviour(t_slist *list)
{
	int	lowest;

	lowest = ft_get_first_a(list);
	while (ft_lstsize(list->stack_b) > 0)
	{
		if (ft_get_first_b(list) > ft_get_first_a(list))
		{
			while (ft_get_first_b(list) > ft_get_first_a(list))
				ft_rotate(list, &list->stack_a, TRUE);
		}
		else if (ft_get_first_b(list) < lowest)
		{
			ft_lowest_to_top(list, &list->stack_a, lowest);
			lowest = ft_get_first_b(list);
		}
		else if (ft_get_first_b(list) < ft_get_first_a(list))
		{
			while (ft_get_last_a(list) > ft_get_first_b(list))
				ft_reverse(list, &list->stack_a, TRUE);
		}
		ft_push(list, &list->stack_b, &list->stack_a, TRUE);
	}
	return (lowest);
}

void	ft_big_sort(t_slist *list, int part)
{
	ft_fill_sorted_values(list, list->stack_a);
	ft_fill_parts_limits(list, part);
	ft_push_parts(list, part);
	ft_sort_3(list);
	ft_lowest_to_top(list, &list->stack_a, ft_sort_behaviour(list));
}
