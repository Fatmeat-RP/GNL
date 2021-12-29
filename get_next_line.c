/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarle-m <acarle-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 01:35:03 by acarle-m          #+#    #+#             */
/*   Updated: 2021/12/29 01:25:51 by acarle-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

char	*get_next_line(int fd)
{
	char		*line;
	t_s64		i;

	if (fd < 0)
	{
		printf("error fd");
		return (NULL);
	}
	return (ft_read(line, fd));
}

char	*ft_read(char *line, int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	t_s64		n;

	if (!read(fd, buff, BUFFER_SIZE))
		return ("bad read\n");
	n = ft_eol(buff);
	if (n == -1)
		n = ft_strlen(buff);
	if (!line)
		line = ft_strndup(buff, n);
	if (ft_strlen(buff) < BUFFER_SIZE)
		line = ft_strnjoinlast(line, buff, n);
	else
		line = ft_strnjoin(line, buff, n);
	if (ft_eol(line) == -1)
		ft_read(line, fd);
	else
		ft_shiftbuff(buff, n);
	return (line);
}

char	*ft_strndup(char *buff, t_s64 n)
{
	char	*s;
	t_s64	i;

	i = 0;
	s = malloc(n + 1);
	if (!s)
	{
		printf("error malloc");
		return (NULL);
	}
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
	{
		printf("error malloc");
		return (NULL);
	}
	while (i++ < j)
		s[i] = dst[i];
	while (i++ < (j + n))
		s[i] = buf[i - j];
	s[i] = 0;
	return (s);
}

char	*ft_strnjoinlast(char *dst, char *buf, t_s64 n)
{
	char	*s;
	t_s64	i;
	t_s64	j;

	i = 0;
	j = ft_strlen(dst);
	s = malloc(j + n + 2);
	if (!s)
	{
		printf("error malloc");
		return (NULL);
	}
	while (i++ < j)
		s[i] = dst[i];
	while (i++ < (j + n))
		s[i] = buf[i - j];
	s[i++] = '\n';
	s[i] = 0;
	return (s);
}

void	ft_shiftbuff(char *buf, t_s64 n)
{
	t_s64	i;
	t_s64	j;
	char	*s;

	i = 0;
	s = malloc(BUFFER_SIZE - n + 1);
	while (buf[i++ + n])
		s[i] = buf[i + n];
	i = 0;
	while (i < BUFFER_SIZE)
		buf[i++] = 0;
	i = 0;
	while (s[i++])
		buf[i] = s[i];
	free (s);
}

t_s64	ft_strlen(char *s)
{
	t_s64	i;

	if (s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

t_s64	ft_eol(char *s)
{
	t_s64	i;

	if (s)
		return (0);
	while (s[i] != '\n')
	{
		if (s[i] == 0)
			return (-1);
		i++;
	}
	return (i);
}

int	main(void)
{
	int		fd;
	char	buff[BUFFER_SIZE];
	int		i = 1;

	fd = open("new", O_RDONLY);
	if (!read(fd, buff, BUFFER_SIZE))
		printf("bad read\n");
	printf("%s", buff);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	return (0);
}
