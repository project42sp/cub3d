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

#include "../../includes/cub3d.h"

char	**parse_map(int fd, t_map_size len)
{
	int		parsed_map;
	char	*line;
	char	**map;

	parsed_map = FALSE;
	while (len.control != len.line_start)
	{
		line = get_next_line(fd);
		free(line);
		len.control++;
	}
	line = get_next_line(fd);
	// TODO: After reaching line where map start, start ingesting map.
	// Still needs to ft_calloc the char** map for moving pointers.
	return (NULL);
}

t_scene	*get_data(char *argv, t_map_size len_map)
{
	int		fd;
	t_scene	*data;

	fd = get_file(argv);
	if (fd <= 0)
		return (NULL);
	printf("Cub3D: Start Parsing file...\n");
	data = init_map();
	if (!data)
		return (NULL);
	data->map = parse_map(fd, len_map);
	if (!data->map)
		return (NULL);
	printf("Cub3D: Closing file.");
	close(fd);
	return (data);
}

t_scene	*parser(char *argv)
{
	int			fd;
	t_scene		*scene;
	t_map_size	len_map;

	if (invalid_name(argv))
		return (NULL);
	fd = get_file(argv);
	if (fd <= 0)
		return (NULL);
	len_map = check_map_size(fd);
	if (!len_map.map_size)
		return (NULL);
	scene = get_data(argv, len_map);
	if (!scene)
		return (NULL);
	return (scene);
}
