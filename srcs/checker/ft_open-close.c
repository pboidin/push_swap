/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open-close.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piboidin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 13:57:43 by piboidin          #+#    #+#             */
/*   Updated: 2022/01/20 13:58:20 by piboidin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strndup(const char *str, size_t n, t_bool free_str)
{
	size_t	i;
	char	*res;

	res = ft_calloc(n + 1, sizeof(char));
	if (!str || res == NULL)
		return (NULL);
	i = 0;
	while (str[i] && i < n)
	{
		res[i] = str[i];
		i++;
	}
	while (i <= n)
	{
		res[i] = 0;
		i++;
	}
	if (free_str)
		free((char *)str);
	return (res);
}

char	*ft_strdup(const char *str, t_bool free_str)
{
	if (!str)
		return (NULL);
	if (free_str == TRUE)
		return (ft_strndup(str, ft_strlen(str), TRUE));
	return (ft_strndup(str, ft_strlen(str), FALSE));
}

t_file	*ft_open_file(const char *path, int flags)
{
	t_file	*file;
	int		fd;

	if (path == NULL)
		fd = 0;
	else
		fd = open(path, flags);
	if (fd == -1)
		return (NULL);
	file = ft_calloc(1, sizeof(t_file));
	if (!file)
	{
		close(fd);
		return (NULL);
	}
	file->s_fd = fd;
	file->file_path = ft_strdup(path, FALSE);
	file->read_line = 0;
	file->backup = 0;
	return (file);
}

void	ft_putstring(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

t_bool	ft_close_file(t_file *file)
{
	if (close(file->s_fd) == 1)
		return (FALSE);
	file->s_fd = 0;
	if (file->file_path != 0)
		free(file->file_path);
	if (file->backup != 0)
		free(file->backup);
	if (file->read_line != 0)
		free(file->read_line);
	free(file);
	return (TRUE);
}
