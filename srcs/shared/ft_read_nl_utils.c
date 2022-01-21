/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_nl_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piboidin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 14:29:22 by piboidin          #+#    #+#             */
/*   Updated: 2022/01/20 14:31:57 by piboidin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

size_t	ft_strcpy(const char *src, char *dst)
{
	size_t	i;
	size_t	len_src;

	if (!dst || !src)
		return (0);
	len_src = ft_strlen(src);
	i = 0;
	while (i < len_src)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (len_src);
}

char	*ft_add_strs(char *s1, char *s2, t_bool free1, t_bool free2)
{
	size_t	size;
	char	*result;
	size_t	len_s1;

	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	result = ft_calloc(size, sizeof(char));
	if (!result)
		return (NULL);
	len_s1 = ft_strcpy(s1, result);
	ft_strcpy(s2, &result[len_s1]);
	if (free1)
		free((void *)s1);
	if (free2)
		free((void *)s2);
	return (result);
}

ssize_t	ft_find_char(char *str, char c)
{
	ssize_t	i;

	if (!str)
		return (-1);
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

t_bool	ft_cont_char(char *str, char c)
{
	if (ft_find_char(str, c) == -1)
		return (FALSE);
	return (TRUE);
}
