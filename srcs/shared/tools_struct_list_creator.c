/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_struct_list_creator.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piboidin <piboidin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 20:59:08 by piboidin          #+#    #+#             */
/*   Updated: 2022/01/20 14:42:56 by piboidin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*pt;

	pt = malloc(nmemb * size);
	if (!pt)
		return (NULL);
	ft_bzero(pt, nmemb);
	return (pt);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

t_bool	is_space(char c)
{
	if (c == ' ')
		return (TRUE);
	return (FALSE);
}

t_bool	is_whitespace(char c)
{
	if (c >= 9 && c <= 13)
		return (TRUE);
	return (is_space(c));
}

long long	ft_atoll(char *str)
{
	unsigned long long	result;
	unsigned long long	is_neg;
	int					i;

	i = 0;
	result = 0;
	is_neg = 1;
	while (str[i] && is_whitespace(str[i]))
		i++;
	while (str[i] && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			is_neg *= -1;
		i++;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		result = result * 10 + str[i] - 48;
		i++;
	}
	return ((long long)result * is_neg);
}
