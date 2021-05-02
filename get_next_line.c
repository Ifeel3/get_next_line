/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvallie <lvallie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 00:45:42 by lvallie           #+#    #+#             */
/*   Updated: 2021/05/02 02:42:45 by lvallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void clear(char *tmp)
{
	if (tmp != NULL)
	{
		free(tmp);
		tmp = NULL;
	}
}

int	gnl_cat(char **string1, char *string2)
{
	char	*tmp;

	if (*string1 == NULL)
		*string1 = ft_strjoin("","");
	tmp = *string1;
	*string1 = ft_strjoin(*string1, string2);
	clear(tmp);
	if (*string1 == NULL)
		return (0);
	return (1);
}

char	*checker(char **reminder)
{
	char	*tmp;

	tmp = *reminder;
	if (!*reminder)
		return (NULL);
	while (*tmp != 0)
	{
		if (*tmp++ == '\n')
			return (tmp - 1);
	}
	return (NULL);
}

int	gnl_toline(char **reminder, char **line)
{
	char	*tmp;
	char	*chrpos;

	chrpos = checker(&(*reminder));
	*chrpos = 0;
	if (!gnl_cat(&(*line), reminder))
		return (0);
	if (*(chrpos + 1) != 0)
	{
		tmp = *reminder;
		*reminder = ft_strjoin(chrpos + 1, "");
		clear(tmp);
		if (*reminder == NULL)
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
	if (fd < 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE < 1 || !line)
		return (-1);
	ft_bzero(buffer, BUFFER_SIZE + 1);
	while (!checker(&reminder) && size > 0)
	{
		size = read(fd, buffer, BUFFER_SIZE);
		if (!gnl_cat(&reminder, buffer))
			return (-1);
		ft_bzero(buffer, BUFFER_SIZE + 1);
	}
	if (!gnl_toline(&reminder, &(*line)))
		return (-1);
	if (!size)
		return (0);
	return (1);
}
