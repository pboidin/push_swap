/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piboidin <piboidin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 19:36:59 by piboidin          #+#    #+#             */
/*   Updated: 2022/01/20 14:19:27 by piboidin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	char	**argmts;
	t_slist	*list;

	if (argc <= 1)
		return (0);
	if (argc == 2)
		argmts = ft_split(argv[1], ' ');
	else
		argmts = &argv[1];
	list = ft_struct_list_creator(argmts);
	if (list == NULL)
	{
		ft_puterror();
		return (0);
	}
	ft_sort(list);
	if (argc == 2)
		ft_destroy_splitted(&argmts);
	ft_list_destroyer(&list);
	return (0);
}
