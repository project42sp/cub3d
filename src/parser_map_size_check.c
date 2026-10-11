
t_map_size init_map_size(void)
{
	t_map_size	len;

	len.index = 0;
	len.map_size = 0;
	len.control = 1;
	len.line_start = 1;
	return (len);
}

int	ignore_space(char *line, int index)
{
	if (!line)
		return index;
	while (ft_isspace(line[index]))
		index++;
	return (index);
}

char	*count_map_size(t_map_size *len, int fd, char *line)
{
	len->index = ignore_space(line, len->index);
	if (!ft_isdigit(line[len->index]))
		return (NULL);
	len->map_size++;
	len->index = 0;
	len->control++;
	free(line);
	line = get_next_line(fd);
	return (line);
}

void	map_error(t_map_size len, char *line, int fd)
{
	printf("Error: Invalid Input File Map Format.\n");
	printf("Error line %d: %s", len.control, line);
	printf("Error character: %c\n", line[len.index]);
	free(line);
	close(fd);
}

t_map_size	check_map_size(int fd)
{
	char	*line;
	t_map_size	len;

	len = init_map_size();
	line = get_next_line(fd);
	while (line)
	{
		len.index = ignore_space(line, len.index);
		if (!len.map_size && ft_isdigit(line[len.index]))
		{
			while (line)
				line = count_map_size(&len, fd, line);
		}
		else if (len.map_size && ft_isdigit(line[len.index]))
		{
			map_error(len, line, fd);
			len.map_size = 0;
			return (len);
		}
		else
			len.line_start++;
		len.control++;
		free(line);
		len.index = 0;
		line = get_next_line(fd);
	}
	close(fd);
	return (len);
}
