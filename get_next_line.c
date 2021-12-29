#include "head.h"

static char	*ft_read(char *line, int fd)
/*{
	char		buf[BUFFER_SIZE + 1];
	char		*ret;
	int			rd;
	t_s64		n;

	n = -1;
	while (n < 0)
	{
		rd = read(fd, buf, BUFFER_SIZE);
		line = ft_strnjoin(line, buf, rd);
		n = ft_eol(line);
	}
	ret = ft_strndup(line, n);
	return (ret);
}*/
/*	rd = read(fd, buf, BUFFER_SIZE);
	if (!line)
		line = ft_strndup(buf, rd);
	else
		line = ft_strnjoin(line, buf, n);
	while (ft_eol(line) < 0)
	{
		rd = read(fd, buf, BUFFER_SIZE);
		line = ft_strnjoin(line, buf, n);
	}
	n = ft_eol(line);
	if (n >= 0)
	{
		ret = ft_strndup(line, n + 1);
		line += (size_t)(n + 1);
	}
	if (!rd && !line)
		return(NULL);
	return (NULL);
	while (rd)
	{
		if (rd < 0 || (!rd && !line))
			return (NULL);
		n = ft_eol(line);
		if (n >= 0)
		{
			ret = ft_strndup(line, n + 1);
			line += (size_t)(n + 1);
			break ;
		}
		rd = read(fd, buf, BUFFER_SIZE);
		line = ft_strnjoin(line, buf, n);
	}
	return (ret);
}*/

char	*get_next_line(int fd)
{
	static char	*line;

	if (fd < 0)
		return (NULL);
	return (ft_read(line, fd));
}

int	main(void)
{
	int	fd;
	int	i = 1;

	fd = open("new", O_RDONLY);
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