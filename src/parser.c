/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buehara <buehara@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 22:31:59 by buehara           #+#    #+#             */
/*   Updated: 2026/09/12 22:32:01 by buehara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	**parsing_map(char *line, int fd)
{
	int		map_size;
	int		index;
	char	**map;

	map_size = 1;
	index = 0;
	map = NULL;
	while (ismap(line))
	{
		map_size++;
		map = ft_calloc(map_size, sizeof(char *));
		if (!map_size)
		{
			ft_split_free(map, map_size);
			return (NULL);
		}
		map[index] = line;
		line = get_next_line(fd);
	}
	return (NULL);
}

t_scene	*parse_data(int	fd)
{
	int		parsed_map;
	char	*line;
	t_scene	*data;

	data = init_map();
	if (!data)
		return (NULL);
	printf("Cub3D: Start Parsing file...\n");
	parsed_map = FALSE;
	line =  get_next_line(fd);
	while(line)
	{
		if (!empty_line(line))
		{
			if (!parsed_map && ismap(line))
			{
				parsed_map = TRUE;
				//data->map = parsing_map(line, fd);
			}
		}
		free(line);
		line = get_next_line(fd);
	}
	return (NULL);
}

t_scene	*get_data(char *argv)
{
	int		fd;
	t_scene	*map;

	if (!argv)
		return (NULL);
	fd = get_file(argv);
	if (fd <= 0)
		return (NULL);
	map = parse_data(fd);
	if (!map)
		return (NULL);
	printf("Cub3D: Closing file.");
	close(fd);
	return (map);
}

t_scene	*parser(char *argv)
{
	//t_scene	*map;
	t_map_size	len_map;
	int			fd;

	if (invalid_name(argv))
		return (NULL);
	fd = get_file(argv);
	if (fd <= 0)
		return (NULL);
	len_map = check_map_size(fd);
	if (!len_map.map_size)
	{
		printf("Cub3D: Error: Return to Main.\n");
		return (NULL);
	}
	//map = get_data(argv);
	//if (!map)
		//return (NULL);
	return (NULL);
}
