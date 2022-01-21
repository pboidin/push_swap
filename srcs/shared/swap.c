/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piboidin <piboidin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 22:24:32 by piboidin          #+#    #+#             */
/*   Updated: 2022/01/20 14:55:36 by piboidin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstget(t_list *begin_list, int i)
{
	t_list	*current;
	int		it;

	current = begin_list;
	it = 0;
	while (current)
	{
		if (it == i)
			return (current);
		current = current->next;
		it++;
	}
	return (NULL);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_display_action(t_slist *list, t_list *stack,
			char *action, t_bool display)
{
	if (!display)
		return ;
	ft_putstr(action);
	if (list->stack_a == stack)
		write(1, "a\n", 2);
	else if (list->stack_b == stack)
		write(1, "b\n", 2);
}

void	ft_swap(t_slist *list, t_list *stack, t_bool display)
{
	t_stack_elem	*tmp;
	t_stack_elem	*tmp2;

	if (ft_lstsize(stack) < 2)
		return ;
	tmp = ft_lstget(stack, 1)->content;
	tmp2 = ft_lstget(stack, 0)->content;
	ft_lstget(stack, 1)->content = tmp2;
	ft_lstget(stack, 0)->content = tmp;
	ft_display_action(list, stack, "s", display);
}
