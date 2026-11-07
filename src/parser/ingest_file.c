/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ingest_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buehara <buehara@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 23:14:20 by buehara           #+#    #+#             */
/*   Updated: 2026/11/06 23:14:49 by buehara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	**clean_gnl(int fd, t_map_size map_size)
{
	int		idx;
	char	**data;
	char	*line;

	data = (char **)ft_calloc(sizeof(char *), map_size.map_size + 6);
	if (!data)
		return (NULL);
	idx = 0;
	line = get_next_line(fd);
	while (line && idx < map_size.map_size + 6)
	{
		if (!empty_line(line))
			data[idx++] = line;
		else
			free(line);
		line = get_next_line(fd);
	}
	data[idx] = NULL;
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
