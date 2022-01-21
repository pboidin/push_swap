/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack_elem.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piboidin <piboidin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 22:43:43 by piboidin          #+#    #+#             */
/*   Updated: 2021/12/31 10:50:13 by piboidin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_elem	*ft_create_stack_elem(int value)
{
	t_stack_elem	*stack_elem;

	stack_elem = ft_calloc(1, sizeof(t_stack_elem));
	if (stack_elem != NULL)
		stack_elem->value = value;
	return (stack_elem);
}
