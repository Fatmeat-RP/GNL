/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarle-m <acarle-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 01:35:03 by acarle-m          #+#    #+#             */
/*   Updated: 2022/01/04 02:11:41 by acarle-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_s64	ft_strlen(char *s, int a)
{
	t_s64	i;

	if (!s)
		return (0);
	i = 0;
	if (a == 2)
		while (s[i])
			i++;
	else
		while (s[i] != '\n' && s[i])
			i++;
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

char	*ft_strjoin(char *s1, char *s2, int rd)
{
	char	*s;
	int		i;
	int		j;

	i = 0;
	j = ft_strlen(s1, 2);
	s = malloc(j + rd + 2);
	if (!s)
		return (NULL);
	if (s1)
	{
		while (i < j)
		{
			s[i] = s1[i];
			i++;
		}
		free (s1);
	}
	while (i < (j + rd))
	{
		s[i] = s2[i - j];
		i++;
	}
	s[i] = 0;
	return (s);
}
