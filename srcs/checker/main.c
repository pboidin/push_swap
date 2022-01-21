/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piboidin <piboidin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 22:11:59 by piboidin          #+#    #+#             */
/*   Updated: 2022/01/20 14:05:05 by piboidin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reader(t_slist *list)
{
	t_file	*file;

	file = ft_open_file(NULL, 0);
	while (ft_read_next_line(file) == 1)
		ft_switcher(list, file->read_line);
	ft_close_file(file);
}

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
	ft_reader(list);
	if (ft_check(list))
		ft_putstr_nl("OK");
	else
		ft_putstr_nl("KO");
	if (argc == 2)
		ft_destroy_splitted(&argmts);
	ft_list_destroyer(&list);
	return (0);
}
