#include "head.h"

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
	if ((ft_strchr(line, '\n') == NULL) && !rd)
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
	int	i = 10;

	fd = open("new", O_RDONLY);
	while (i)
	{
		line = get_next_line(fd);
		printf("%s", line);
		i--;
	}
	close(fd);
	return (0);
}