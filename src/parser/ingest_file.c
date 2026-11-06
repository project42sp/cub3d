# include "../../includes/cub3d.h"

char	**clean_gnl(int fd, t_map_size map_size)
{
	int		idx;
	char	**data;
	char	*line;

	data = (char **)ft_calloc(sizeof(char *), map_size.map_size + 6);
	if (!data)
		return (NULL);
	idx = 0;
	while (idx < map_size.map_size + 6)
	{
		line = get_next_line(fd);
		if (!line)
		{
			ft_split_free(data, map_size.map_size + 7);
			return (NULL);
		}
		if (!empty_line(line))
			data[idx++] = line;
		else
			free(line);
	}
	return (data);
}

char	**ingest_file(char *argv, t_map_size map_size)
{
	int			fd;
	char		**data;

	printf("Cub3D: Start ingesting function.\n");
	fd = get_file(argv);
	if (fd <= 0)
		return (NULL);
	data = NULL;
	data = clean_gnl(fd, map_size);
	if (!data)
		return (NULL);
	printf("Cub3D: Finish clean ingestion.\n");
	return (data);
}
