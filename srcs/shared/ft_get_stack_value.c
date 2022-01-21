/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_stack_value.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piboidin <piboidin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 21:23:10 by piboidin          #+#    #+#             */
/*   Updated: 2022/01/20 14:25:04 by piboidin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_list *lst)
{
	unsigned int	size;

	size = 0;
	while (lst)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}

int	ft_get_value_index(t_list *stack, int value)
{
	int	i;

	i = -1;
	while (++i < ft_lstsize(stack))
	{
		if (ft_get_stack_value(stack, i) == value)
			return (i);
	}
	return (-1);
}

int	ft_get_stack_value(t_list *stack, int i)
{
	return (((t_stack_elem *)ft_lstget(stack, i)->content)->value);
}
