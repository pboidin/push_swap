/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_list_creator_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piboidin <piboidin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 00:33:30 by piboidin          #+#    #+#             */
/*   Updated: 2022/01/20 14:40:59 by piboidin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	ft_valid_struct_list(t_slist *list)
{
	if (list->size == 0)
		return (FALSE);
	if (list->stack_a != NULL)
		return (FALSE);
	if (list->stack_b != NULL)
		return (FALSE);
	return (TRUE);
}

t_bool	ft_is_numeric(char c)
{
	if (c >= '0' && c <= '9')
		return (TRUE);
	return (FALSE);
}

t_bool	ft_is_numberstr(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] && (str[i] == '-' || str[i] == '+'))
		i++;
	if (i == ft_strlen(str))
		return (FALSE);
	while (str[i])
	{
		if (!ft_is_numeric(str[i]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

t_bool	ft_fill_struct_list(t_slist *list, char **argmts)
{
	int			i;
	long long	argmt;

	i = -1;
	while (++i < list->size)
	{
		if (ft_strlen(argmts[i]) > 11 || !ft_is_numberstr(argmts[i]))
			return (FALSE);
		argmt = ft_atoll(argmts[i]);
		if (argmt > INT_MAX || argmt < INT_MIN)
			return (FALSE);
		if (ft_get_value_index(list->stack_a, argmt) != -1)
			return (FALSE);
		ft_lstadd_back_new(&list->stack_a, ft_create_stack_elem((int)argmt));
	}
	return (TRUE);
}

t_slist	*ft_struct_list_creator(char **argmts)
{
	t_slist	*list;

	list = ft_lstinit(ft_get_size(argmts));
	if (!ft_valid_struct_list(list) || !ft_fill_struct_list(list, argmts))
		return (ft_list_destroyer(&list));
	return (list);
}
