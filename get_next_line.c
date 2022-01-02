#include "get_next_line.h"

char	*ft_cleanlione(char *line)
{
	char	*tmp;
	char	*p;
	t_s64	k;

	p = ft_strchr(line, '\n');
	k = ft_strlen(p);
	tmp = ft_strndup((p + 1), k);
	free (line);
	line = ft_strndup(tmp, k);
	free (tmp);
	return (line);
}

char	*ft_strrchr(char *s, int c)
{
	char	*p;
	char	*tmp;

	p = s + ft_strlen(s);
	tmp = s;
	while ((p >= s) && (p != tmp))
	{
		if (*p == (char)c)
			return (p);
		p--;
		if (*tmp != (char)c)
			tmp++;
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char			buf[BUFFER_SIZE + 1];
	char			*ret;
	int			rd;
	t_s64			n;

	if (fd < 0)
		return (NULL);
	rd = read(fd, buf, BUFFER_SIZE);
	buf[rd] = 0;
	if (!rd && ft_strrchr(line, '\n') == NULL)
		return (NULL);
	line = ft_strjoin(line, buf, rd);
	while (ft_eol(line) < 0 && rd)
	{
		rd = read(fd, buf, BUFFER_SIZE);
		buf[rd] = 0;
		line = ft_strjoin(line, buf, rd);
	}
	n = ft_eol(line) + 1;
	ret = ft_strndup(line, n);
	line = ft_cleanlione(line);
	return (ret);
}

int	main(void)
{
	char	*line;
	int	fd;

	fd = open("bible.txt", O_RDONLY);
	while (line = get_next_line(fd))
	{
		printf("%s", line);
		free (line);
	}
	close(fd);
	return (0);
}