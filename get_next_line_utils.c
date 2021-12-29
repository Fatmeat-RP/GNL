/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarle-m <acarle-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 01:35:03 by acarle-m          #+#    #+#             */
/*   Updated: 2021/12/29 03:55:51 by acarle-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

char	*ft_strndup(char *buff, t_s64 n)
{
	char	*s;
	t_s64	i;

	i = 0;
	s = malloc(n + 1);
	if (!s)
		return (NULL);
	while (i < n)
	{
		s[i] = buff[i];
		i++;
	}
	s[i] = 0;
	return (s);
}

char	*ft_strnjoin(char *dst, char *buf, t_s64 n)
{
	char	*s;
	t_s64	i;
	t_s64	j;

	i = 0;
	j = ft_strlen(dst);
	s = malloc(j + n + 1);
	if (!s)
		return (NULL);
	while (i++ < j)
		s[i] = dst[i];
	while (i++ < (j + n))
		s[i] = buf[i - j];
	s[i] = 0;
	free(dst);
	return (s);
}

t_s64	ft_strlen(char *s)
{
	t_s64	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

t_s64	ft_eol(char *s)
{
	t_s64	i;

	if (!s)
		return (-1);
	i = 0;
	while (s[i] != '\n')
	{
		if (s[i] == 0)
			return (-1);
		i++;
	}
	return (i);
}
