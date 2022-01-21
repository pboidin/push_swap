/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_nl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piboidin <piboidin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 22:28:47 by piboidin          #+#    #+#             */
/*   Updated: 2022/01/20 13:59:25 by piboidin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_putchar_fd(int fd, char c)
{
	write(fd, &c, 1);
	return (1);
}

size_t	ft_putstr_fd(int fd, char *str)
{
	size_t	len;

	len = ft_strlen((const char *)str);
	write(fd, str, len);
	return (len);
}

size_t	ft_putstr_fdnl(int fd, char *str)
{
	size_t	len;

	len = ft_putstr_fd(fd, str);
	ft_putchar_fd(fd, '\n');
	return (len + 1);
}

size_t	ft_putstr_nl(char *str)
{
	return (ft_putstr_fdnl(1, str));
}
