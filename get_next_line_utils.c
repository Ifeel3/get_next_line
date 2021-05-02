/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvallie <lvallie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 00:44:12 by lvallie           #+#    #+#             */
/*   Updated: 2021/05/02 01:55:29 by lvallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(char *string, size_t size)
{
	char	*tmp;

	tmp = string;
	while (size--)
		*tmp++ = 0;
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != 0)
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	char	*tmp1;
	char	*tmp2;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	new = malloc(sizeof(*s1) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (new == NULL)
		return (NULL);
	tmp1 = new;
	tmp2 = (char *)s1;
	while (*tmp2)
		*tmp1++ = *tmp2++;
	tmp2 = (char *)s2;
	while (*tmp2)
		*tmp1++ = *tmp2++;
	*tmp1 = '\0';
	return (new);
}
