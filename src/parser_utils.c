/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buehara <buehara@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 21:31:58 by buehara           #+#    #+#             */
/*   Updated: 2026/10/12 21:32:03 by buehara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ignore_space(char *line, int index)
{
	if (!line)
		return index;
	while (ft_isspace(line[index]))
		index++;
	return (index);
}

int	empty_line(char *line)
{
	int	index;

	if (!line)
		return (TRUE);
	index = 0;
	while(ft_isspace(line[index]))
		index++;
	if (line[index] == '\n' || line[index] == '\0')
	{
		printf("%s\n", "Cub3D: Empty line.");
		return (TRUE);
	}
	return (FALSE);
}

int	ismap(char *line)
{
	int	index;

	index = 0;
	while (ft_isspace(line[index]))
		index++;
	if (ft_isalnum(line[index]))
		return (TRUE);
	return (FALSE);
}

t_scene	*init_map(void)
{
	t_scene	*map;

	map = ft_calloc(1, sizeof(t_scene));
	if (!map)
	{
		perror("Error");
		free(map);
		return (NULL);
	}
	return (map);
}

int	get_file(char *filename)
{
	int	fd;

	if (!filename)
		return (FALSE);
	fd = 0;
	fd = open(filename, O_RDONLY);
	if (fd <= 0)
	{
		perror("Error");
		return (FALSE);
	}
	printf("Cub3D: File %s opened.\n", filename);
	return (fd);
}
