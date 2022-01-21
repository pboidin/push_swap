/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_new.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piboidin <piboidin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 16:06:46 by piboidin          #+#    #+#             */
/*   Updated: 2022/01/20 14:27:41 by piboidin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_front_elem(t_list **begin_list, t_list *elem)
{
	if (elem == NULL)
		return ;
	if (*begin_list)
		elem->next = *begin_list;
	*begin_list = elem;
}

void	ft_lstadd_front_new(t_list **begin_list, void *data)
{
	ft_lstadd_front_elem(begin_list, ft_lst_create_elem(data));
}
