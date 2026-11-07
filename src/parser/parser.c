/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buehara <buehara@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 22:31:59 by buehara           #+#    #+#             */
/*   Updated: 2026/11/06 23:53:19 by buehara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// TODO: After reaching line where map start, start ingesting map.
// Still needs to ft_calloc the char** map for moving pointers.
// 
/*
static char	**parse_map(int fd, t_map_size len)
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
*/

static char	**data_check(char *argv, t_map_size len_map)
{
	char		**data;

	data = ingest_file(argv, len_map);
	if (!data)
		return (NULL);
	if (invalid_parameters(data, len_map))
	{
		ft_split_free(data, len_map.control);
		return (NULL);
	}
	printf("Cub3D: Parameters Accepted.\n");
	if (invalid_content(data, len_map))
	{
		ft_split_free(data, len_map.control);
		return (NULL);
	}
	printf("Cub3D: Parameter Values Accepted.\n");
	return (data);
}

t_scene	*parser(char *argv)
{
	char		**data;
	t_scene		*scene;
	t_map_size	len_map;

	if (invalid_name(argv, "cub"))
		return (NULL);
	len_map = check_map_size(argv);
	if (!len_map.map_size)
		return (NULL);
	data = data_check(argv, len_map);
	if (!data)
		return (NULL);
	ft_split_free(data, len_map.control);
	scene = NULL;
	return (scene);
}
