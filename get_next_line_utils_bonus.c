/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvallie <lvallie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 00:44:12 by lvallie           #+#    #+#             */
/*   Updated: 2021/05/02 14:07:00 by lvallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

int	gnl_strcat(char **dest, char *src)
{
	char	*tmp;
	char	*new;
	size_t	dstlen;
	size_t	srclen;
	size_t	newlen;

	dstlen = ft_strlen(*dest);
	srclen = ft_strlen(src);
	newlen = dstlen + srclen;
	new = malloc(sizeof(char) * (newlen + 1));
	if (!new)
		return (0);
	new[newlen] = 0;
	while (srclen--)
		new[--newlen] = src[srclen];
	while (dstlen--)
		new[--newlen] = (*dest)[dstlen];
	tmp = *dest;
	*dest = new;
	if (tmp)
		free(tmp);
	return (1);
}
