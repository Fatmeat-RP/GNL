/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarle-m <acarle-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 22:59:47 by acarle-m          #+#    #+#             */
/*   Updated: 2022/01/04 23:22:23 by acarle-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_s64	ft_strlen(char *s, int a)
{
	t_s64	i;

	if (!s)
		return (0);
	i = 0;
	if (a >= 2)
		while (s[i])
			i++;
	else
		while (s[i] != '\n' && s[i])
			i++;
	return (i);
}

static char	*ft_strchr(char *s, int c)
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

static char	*ft_strjoin(char *s1, char *s2, int rd)
{
	char	*s;
	int		i;
	int		j;

	i = 0;
	j = ft_strlen(s1, 2);
	s = malloc(j + rd + 2);
	if (!s || (!s1 && !s2))
		return (NULL);
	while (i < j)
	{
		s[i] = s1[i];
		i++;
	}
	if (s1)
		free (s1);
	while (i < (j + rd))
	{
		s[i] = s2[i - j];
		i++;
	}
	s[i] = 0;
	return (s);
}

static char	*ft_cleanlione(char *line)
{
	char	*tmp;
	char	*p;
	t_s64	k;

	p = ft_strchr(line, '\n');
	k = ft_strlen(p, 2) - 1;
	tmp = ft_strjoin(NULL, (p + 1), k);
	free (line);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*line = NULL;
	t_struct	st;

	if (line)
		line = ft_cleanlione(line);
	st.rd = read(fd, st.buf, BUFFER_SIZE);
	st.buf[st.rd] = 0;
	if ((!st.rd && ft_strchr(line, '\n') == NULL && !ft_strlen(line, 2))
		|| (st.rd == -1))
	{
		if (line)
			free(line);
		return (NULL);
	}
	line = ft_strjoin(line, st.buf, st.rd);
	while (ft_strchr(line, '\n') == NULL && st.rd == BUFFER_SIZE)
	{
		st.rd = read(fd, st.buf, BUFFER_SIZE);
		st.buf[st.rd] = 0;
		line = ft_strjoin(line, st.buf, st.rd);
	}
	st.n = ft_strlen(line, 1) + 1;
	st.ret = ft_strjoin(NULL, line, st.n);
	return (st.ret);
}
