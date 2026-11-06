/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buehara <buehara@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 22:31:59 by buehara           #+#    #+#             */
/*   Updated: 2026/11/04 22:57:19 by buehara          ###   ########.fr       */
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

static int	data_check(char *argv)
{
	char		**data;
	t_map_size	len_map;

	if (invalid_name(argv, "cub"))
		return (FAILED);
	len_map = check_map_size(argv);
	if (!len_map.map_size)
		return (0);
	data = ingest_file(argv, len_map);
	if (!data)
		return (0);
	ft_split_free(data, len_map.map_size + 7);
	if (invalid_parameters(argv))
		return (FAILED);
	printf("Cub3D: Parameters Accepted.\n");
	if (invalid_content(argv))
		return (FAILED);
	printf("Cub3D: Parameter Values Accepted.\n");
	return (SUCESS);
}

t_scene	*parser(char *argv)
{
	int			fd;
	t_scene		*scene;

	if (data_check(argv))
		return (NULL);
	fd = get_file(argv);
	if (fd <= 0)
		return (NULL);
	scene = NULL;
	return (scene);
}
