/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_nl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piboidin <piboidin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 18:50:48 by piboidin          #+#    #+#             */
/*   Updated: 2022/01/20 14:28:52 by piboidin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*ft_first_line(char *src)
{
	size_t	i;
	char	*result;

	if (!src)
		return (NULL);
	i = 0;
	while (src[i] && src[i] != '\n')
		i++;
	result = ft_calloc(i + 1, sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	while (src[i] && src[i] != '\n')
	{
		result[i] = src[i];
		i++;
	}
	result[i] = 0;
	return (result);
}

static char	*ft_second_line(char *src)
{
	size_t	i;
	size_t	j;
	char	*result;

	if (!src)
		return (NULL);
	i = ft_find_char(src, '\n') + 1;
	result = ft_calloc(ft_strlen(src) - i + 1, sizeof(char));
	if (!result)
		return (NULL);
	j = 0;
	while (src[i + j])
	{
		result[j] = src[i + j];
		j++;
	}
	result[j] = 0;
	free(src);
	src = NULL;
	return (result);
}

static void	ft_clear_line_read(t_file *file)
{
	free(file->read_line);
	file->read_line = NULL;
}

static void	ft_clear_backup(t_file *file)
{
	free(file->backup);
	file->backup = NULL;
}

t_read	ft_read_next_line(t_file *file)
{
	int		result;
	char	buf[BUFFER_SIZE + 1];

	if (file->s_fd < 0 || file->s_fd >= OPEN_MAX || BUFFER_SIZE < 1)
		return (read_error);
	result = 1;
	while (!ft_cont_char(file->backup, '\n') && result != 0)
	{
		result = read(file->s_fd, &buf, BUFFER_SIZE);
		if (result == -1)
			return (read_error);
		buf[result] = '\0';
		file->backup = ft_add_strs(file->backup, buf, TRUE, FALSE);
	}
	if (file->read_line)
		ft_clear_line_read(file);
	file->read_line = ft_first_line(file->backup);
	if (result == 0)
		ft_clear_backup(file);
	if (result == 0)
		return (read_success_end);
	file->backup = ft_second_line(file->backup);
	return (read_success);
}
