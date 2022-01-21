/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstinit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piboidin <piboidin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 20:21:07 by piboidin          #+#    #+#             */
/*   Updated: 2022/01/20 14:27:59 by piboidin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_slist	*ft_lstinit(int len)
{
	t_slist	*list;

	list = ft_calloc(1, sizeof(t_slist));
	if (list == NULL)
		return (NULL);
	list->size = len;
	list->stack_a = NULL;
	list->stack_b = NULL;
	list->sorted_values = NULL;
	list->parts_limits = NULL;
	return (list);
}
