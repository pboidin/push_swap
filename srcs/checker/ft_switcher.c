/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_switcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piboidin <piboidin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 22:34:37 by piboidin          #+#    #+#             */
/*   Updated: 2022/01/20 13:59:49 by piboidin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_switcher_rotation(t_slist *list, char *cmd, size_t len)
{
	if (len == 2)
	{
		if (ft_strcmp(cmd, "rr") == 0)
		{
			ft_rotate(list, &list->stack_a, FALSE);
			ft_rotate(list, &list->stack_b, FALSE);
		}
		else if (ft_strcmp(cmd, "ra") == 0)
			ft_rotate(list, &list->stack_a, FALSE);
		else if (ft_strcmp(cmd, "rb") == 0)
			ft_rotate(list, &list->stack_b, FALSE);
	}
	else if (len == 3)
	{
		if (ft_strcmp(cmd, "rrr") == 0)
		{
			ft_reverse(list, &list->stack_a, FALSE);
			ft_reverse(list, &list->stack_b, FALSE);
		}
		else if (ft_strcmp(cmd, "rra") == 0)
			ft_reverse(list, &list->stack_a, FALSE);
		else if (ft_strcmp(cmd, "rrb") == 0)
			ft_reverse(list, &list->stack_b, FALSE);
	}
}

void	ft_switcher_swap(t_slist *list, char *cmd)
{
	if (ft_strcmp(cmd, "ss") == 0)
	{
		ft_swap(list, list->stack_a, FALSE);
		ft_swap(list, list->stack_b, FALSE);
	}
	else if (ft_strcmp(cmd, "sa") == 0)
		ft_swap(list, list->stack_a, FALSE);
	else if (ft_strcmp(cmd, "sb") == 0)
		ft_swap(list, list->stack_b, FALSE);
}

void	ft_switcher_push(t_slist *list, char *cmd)
{
	if (ft_strcmp(cmd, "pa") == 0)
		ft_push(list, &list->stack_b, &list->stack_a, FALSE);
	else if (ft_strcmp(cmd, "pb") == 0)
		ft_push(list, &list->stack_a, &list->stack_b, FALSE);
}

void	ft_switcher(t_slist *list, char *cmd)
{
	size_t	len;

	len = ft_strlen(cmd);
	if (cmd == NULL || len < 2 || len > 3)
		return ;
	if (cmd[0] == 'r' && len >= 2 && len <= 3)
		ft_switcher_rotation(list, cmd, len);
	else if (cmd[0] == 's' && len == 2)
		ft_switcher_swap(list, cmd);
	else if (cmd[0] == 'p' && len == 2)
		ft_switcher_push(list, cmd);
}
