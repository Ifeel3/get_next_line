/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvallie <lvallie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 00:44:12 by lvallie           #+#    #+#             */
/*   Updated: 2021/05/02 14:07:00 by lvallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i] != 0)
		i++;
	return (i);
}

char	*ft_strchr(char *string, int c)
{
	if (string != NULL)
	{
		while (*string)
		{
			if (*string++ == c)
				return (string - 1);
		}
	}
	return (NULL);
}

char	*ft_strdup(char *src)
{
	char	*destination;
	char	*source;
	char	*tmp;
	size_t	srclen;

	source = src;
	srclen = ft_strlen(src);
	destination = (char *)malloc(sizeof(char) * (srclen + 1));
	if (!destination)
		return (NULL);
	tmp = destination;
	while (srclen--)
		*tmp++ = *source++;
	*tmp = 0;
	return (destination);
}
