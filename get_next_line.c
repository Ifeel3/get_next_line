/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvallie <lvallie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 05:30:39 by lvallie           #+#    #+#             */
/*   Updated: 2021/05/02 14:22:07 by lvallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	gnl_init(int fd, char **reminder, char **line)
{
	char	*tmp;

	if (!line || fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
		return (0);
	if (!*reminder)
	{
		*reminder = ft_strdup("");
		if (!*reminder)
			return (0);
	}
	tmp = *line;
	*line = ft_strdup("");
	if (tmp != NULL)
		free(tmp);
	if (!*line)
	{
		free(*reminder);
		return (0);
	}
	return (1);
}

int	gnl_pushtoline(char **reminder, char **line)
{
	char	*chrpos;

	chrpos = ft_strchr(*reminder, '\n');
	if (chrpos)
		*chrpos = '\0';
	if (!gnl_strcat(&(*line), *reminder))
	{
		free(*reminder);
		return (0);
	}
	if (chrpos)
		*chrpos = '\n';
	return (1);
}

int	gnl_subn(char **reminder)
{
	char	*tmp;

	tmp = ft_strchr(*reminder, '\n');
	if (tmp)
	{
		if (*(tmp + 1) != '\0')
		{
			tmp = *reminder;
			*reminder = ft_strdup(ft_strchr(*reminder, '\n') + 1);
			free(tmp);
			if (!*reminder)
				return (0);
		}
		else
			*reminder[0] = 0;
	}
	else
	{
		tmp = *reminder;
		*reminder = ft_strdup("");
		free(tmp);
		if (!*reminder)
			return (0);
	}
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static char	*reminder;
	char		buffer[BUFFER_SIZE + 1];
	size_t		size;

	size = 1;
	if (!gnl_init(fd, &reminder, &(*line)))
		return (-1);
	while (!ft_strchr(reminder, '\n') && size)
	{
		size = read(fd, buffer, BUFFER_SIZE);
		buffer[size] = 0;
		if (!gnl_strcat(&reminder, buffer))
			return (-1);
	}
	if (!gnl_pushtoline(&reminder, line) || !gnl_subn(&reminder))
		return (-1);
	if (reminder[0] == 0 && size < 1)
	{
		free(reminder);
		reminder = NULL;
	}
	if (size == 0)
		return (0);
	return (1);
}
