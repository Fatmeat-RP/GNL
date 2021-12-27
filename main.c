char	*get_next_line(int fd)
{
	static char	**line;
	char		buff[BUFFER_SIZE];
	static t_s64		ln;
	t_s64		i;
	t_s64		j;

	if (fd > 0)
		return (NULL);
	if (!read(fd, buff, BUFFER_SIZE))
		return (NULL);
	len = ft_strlen(buff);
	j = ln;
	while (len)
	{
		if (!line[fd][ln])
			line[fd][ln] = ft_strndup(buff, i);
		else
			ft_strnjoin(line[fd][ln], buff, i);
		if (!ft_strchr(line[ln], '\n'))
			line[fd][ln] = get_next_line(fd);
		else
			ln++;
		len--;
	}
	return (line[fd][i]);
}

