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

char	*ft_strchr(char *s, int c)
{
	char	*p;

	if (!s)
		return (NULL);
	p = s;
	while (*p != (char)c)
	{
		if (*p == 0)
			return (NULL);
		p++;
	}
	return (p);
}


char	*ft_strjoin(char *s1, char *s2)
{
	char	*s;
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen(s1);
	s = malloc(j + ft_strlen(s2) + 1);
	if (!s)
		return (NULL);
	while (i < j)
	{
		s[i] = s1[i];
		i++;
	}
	while (i < (j + ft_strlen(s2)))
	{
		s[i] = s2[i - j];
		i++;
	}
	s[i] = 0;
	if (s1)
		free(s1);
	return (s);
}