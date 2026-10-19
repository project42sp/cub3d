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

// TODO: After reaching line where map start, start ingesting map.
// Still needs to ft_calloc the char** map for moving pointers.
char	**parse_map(int fd, t_map_size len)
{
	int		parsed_map;
	char	*line;
	char	**map;

	(void)map;
	(void)parsed_map;
	parsed_map = FALSE;
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		len.control++;
		line = get_next_line(fd);
	}
	line = get_next_line(fd);
	return (NULL);
}

t_scene	*get_data(int fd, t_map_size len_map)
{
	t_scene	*data;

	printf("Cub3D: Start Parsing file...\n");
	data = init_map();
	if (!data)
	{
		close(fd);
		return (NULL);
	}
	data->map = parse_map(fd, len_map);
	if (!data->map)
	{
		close(fd);
		free(data);
		return (NULL);
	}
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
	if (invalid_parameters(argv))
		return (NULL);
	len_map = check_map_size(argv);
	if (!len_map.map_size)
		return (NULL);
	fd = get_file(argv);
	if (fd <= 0)
		return (NULL);
	scene = get_data(fd, len_map);
	if (!scene)
		return (NULL);
	return (scene);
}
