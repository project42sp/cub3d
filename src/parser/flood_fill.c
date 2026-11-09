/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buehara <buehara@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 19:45:49 by buehara           #+#    #+#             */
/*   Updated: 2026/11/09 16:09:35 by buehara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static char	**map_copy(char **org, t_map_size len)
{
	char	**cpy;

	cpy = ft_calloc(sizeof(char *), len.map_size + 1);
	if (!cpy)
		return (NULL);
	len.index = 0;
	while (len.index < len.map_size)
	{
		cpy[len.index] = ft_strdup(org[len.index]);
		if (!cpy[len.index])
		{
			ft_split_free(cpy, len.map_size);
			return (NULL);
		}
		len.index++;
	}
	cpy[len.index] = NULL;
	return (cpy);
}

static int	flood_fill(char **map, int column, int line, t_map_size len)
{
	if (line >= len.map_size || column >= (int)ft_strlen(map[line])
		|| line < 0 || column < 0)
	{
		printf("Cub3D: Open path on map: Coord[%02d][%02d]\n", line, column);
		return (FALSE);
	}
	if (map[line][column] == '1' || map[line][column] == '2')
		return (TRUE);
	if (map[line][column] == '0' || ft_isspace(map[line][column]))
	{
		printf("Log: Painted [%02d][%02d]\n", line, column);
		map[line][column] = '2';
	}
	if (!flood_fill(map, column + 1, line, len))
		return (FALSE);
	if (!flood_fill(map, column -1, line, len))
		return (FALSE);
	if (!flood_fill(map, column, line + 1, len))
		return (FALSE);
	if (!flood_fill(map, column, line - 1, len))
		return (FALSE);
	return (TRUE);
}

char	**extract_map(char **data, t_map_size len)
{
	char	**map;

	map = ft_calloc(sizeof(char *), len.map_size + 1);
	if (!map)
	{
		perror("Error");
		return (NULL);
	}
	len.index = 0;
	len.line_start = 6;
	while (len.index < len.map_size)
	{
		map[len.index] = data[len.line_start];
		len.line_start++;
		len.index++;
	}
	map[len.index] = NULL;
	return (map);
}

int	invalid_wall_check(char **map, t_map_size len, t_camera cam)
{
	char	**cpy;

	cpy = map_copy(map, len);
	if (!cpy)
		return (FAILED);
	if (flood_fill(cpy, cam.pos_x, cam.pos_y, len))
	{
		ft_split_free(cpy, len.map_size);
		return (SUCESS);
	}
	ft_split_free(cpy, len.map_size);
	return (FAILED);
}
