#include "get_next_line.h"

char	*ft_cleanlione(char *line)
{
	char	*tmp = NULL;
	char	*p;
	t_s64	k;

	p = ft_strchr(line, '\n');
	k = ft_strlen(p, 2) - 1;
	if (p[k] != 0)
		tmp = ft_strjoin(NULL, (p + 1), k);
	free (line);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*line[_SC_OPEN_MAX];
	t_struct	st;

	st.rd = read(fd, st.buf, BUFFER_SIZE);
	if ((!st.rd && ft_strchr(line[fd], '\n') == NULL) || (st.rd == -1))
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
