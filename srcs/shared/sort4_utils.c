/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort4_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piboidin <piboidin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 23:22:10 by piboidin          #+#    #+#             */
/*   Updated: 2022/01/20 14:40:11 by piboidin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap_values(int array[], int index_a, int index_b)
{
	int	tmp;

	tmp = array[index_a];
	array[index_a] = array[index_b];
	array[index_b] = tmp;
}

void	ft_quick_sort(int array[], int index_start, int index_end)
{
	int	left;
	int	right;
	int	pivot;

	left = index_start - 1;
	right = index_end + 1;
	pivot = array[index_start];
	if (index_start >= index_end)
		return ;
	while (1)
	{
		while (array[--right] > pivot)
			;
		while (array[++left] < pivot)
			;
		if (left < right)
			ft_swap_values(array, left, right);
		else
			break ;
	}
	ft_quick_sort(array, index_start, right);
	ft_quick_sort(array, right + 1, index_end);
}

int	ft_get_last_a(t_slist *list)
{
	return (ft_get_stack_value(list->stack_a, ft_lstsize(list->stack_a) - 1));
}

int	ft_get_first_a(t_slist *list)
{
	return (ft_get_stack_value(list->stack_a, 0));
}

int	ft_get_first_b(t_slist *list)
{
	return (ft_get_stack_value(list->stack_b, 0));
}
