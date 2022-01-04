#include "get_next_line.h"

char	*ft_cleanlione(char *line)
{
	char	*tmp;
	char	*p;
	t_s64	k;

	if (line != NULL)
	{
		p = ft_strchr(line, '\n');
		k = ft_strlen(p, 2) - 1;
		tmp = ft_strjoin(NULL, (p + 1), k);
		free (line);
		return (tmp);
	}
	else
		tmp = NULL;
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*line;
	t_struct	st;

	st.rd = read(fd, st.buf, BUFFER_SIZE);
	if ((!st.rd && ft_strchr(line, '\n') == NULL) || (st.rd == -1))
	{
		if (line != NULL)
			free(line);
		return (NULL);
	}
	if (st.rd)
		st.buf[st.rd] = 0;
	if (st.rd)
		line = ft_strjoin(line, st.buf, st.rd);
	while (ft_strchr(line, '\n') == NULL && st.rd > 0)
	{
		st.rd = read(fd, st.buf, BUFFER_SIZE);
		if (!st.rd)
			break ;
		st.buf[st.rd] = 0;
		line = ft_strjoin(line, st.buf, st.rd);
	}
	st.n = ft_strlen(line, 1) + 1;
	st.ret = ft_strjoin(NULL, line, st.n);
	line = ft_cleanlione(line);
	return (st.ret);
}
/*
int	main(void)
{
	char	*line;
	int	fd;

	fd = open("test/bible.txt", O_RDONLY);
	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free (line);
	}
	close(fd);
	return (0);
}*/
