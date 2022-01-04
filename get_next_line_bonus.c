/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarle-m <acarle-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 23:16:16 by acarle-m          #+#    #+#             */
/*   Updated: 2022/01/04 23:27:12 by acarle-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	static char	*line[_SC_OPEN_MAX];
	t_struct	st;

	st.rd = read(fd, st.buf, BUFFER_SIZE);
	if ((!st.rd && ft_strchr(line[fd], '\n') == NULL && !ft_strlen(line[fd], 2))
		|| (st.rd == -1))
	{
		if (line[fd] && st.rd != -1)
			free (line[fd]);
		return (NULL);
	}
	st.buf[st.rd] = 0;
	if (st.rd)
		line[fd] = ft_strjoin(line[fd], st.buf, st.rd);
	while (ft_strchr(line[fd], '\n') == NULL && st.rd > 0)
	{
		st.rd = read(fd, st.buf, BUFFER_SIZE);
		st.buf[st.rd] = 0;
		line[fd] = ft_strjoin(line[fd], st.buf, st.rd);
	}
	st.n = ft_strlen(line[fd], 1) + 1;
	st.ret = ft_strjoin(NULL, line[fd], st.n);
	line[fd] = ft_cleanlione(line[fd]);
	return (st.ret);
}
