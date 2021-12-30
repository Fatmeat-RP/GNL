#include "get_next_line.h"

char	*ft_cleanlione(char *line)
{
	char			*tmp;

	tmp = ft_strndup((ft_strchr(line, '\n') + 1)
		, ft_strlen(ft_strchr(line, '\n')));
	free (line);
	line = ft_strndup(tmp, ft_strlen(tmp));
	free (tmp);
	return (line);
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
	if (!rd && ft_strchr(line, '\n') == NULL)
		return (NULL);
	line = ft_strjoin(line, buf);
	while (ft_eol(line) < 0 && rd)
	{
		rd = read(fd, buf, BUFFER_SIZE);
		line = ft_strjoin(line, buf);
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
	int	i = 100182;

	fd = open("bible.txt", O_RDONLY);
	while (i)
	{
		line = get_next_line(fd);
		i--;
		free (line);
	}
	close(fd);
	return (0);
}