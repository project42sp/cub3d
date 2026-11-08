/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buehara <buehara@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 01:13:27 by buehara           #+#    #+#             */
/*   Updated: 2026/11/08 19:44:17 by buehara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	**map_copy(char **org, t_map_size len)
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

int	flood_fill(char **map, int column, int line, t_map_size len)
{
	if (line >= len.map_size || column >= (int)ft_strlen(map[line])
			|| line == 0 || column == 0)
	{
		printf("Cub3D: Found open path on map: Coord[%02d][%02d]\n", line, column);
		return (FALSE);
	}
	if (map[line][column] == '1' || map[line][column] == '2')
		return (TRUE);
	if (map[line][column] == '0' || ft_isspace(map[line][column]))
		map[line][column] = '2';
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

t_camera	init_camera(void)
{
	t_camera	cam;

	cam.pos_x = 0;
	cam.pos_y = 0;
	cam.dir_x = 0;
	cam.dir_y = 0;
	cam.plane_x = 0;
	cam.plane_y = 0;
	return (cam);
}

void	set_player_direction(char value, t_camera *cam)
{
	if (value == 'N')
		cam->dir_y = -1.0;
	else if (value == 'S')
		cam->dir_y = 1.0;
	else if (value == 'E')
		cam->dir_x = 1.0;
	else if (value == 'W')
		cam->dir_x = -1.0;
}

int	player_check(char value, t_camera *cam, int line, int column)
{
	if (ft_strchr("NSEW", value))
	{
		if (cam->pos_x && cam->pos_x)
		{
			cam->pos_x = 0;
			cam->pos_y = 0;
			printf("Map Error: More than one PLayer.\n");
			return (FAILED);
		}
		printf("Cub3D: Found Character %c\n", value);
		cam->pos_x = column;
		cam->pos_y = line;
		set_player_direction(value, cam);
	}
	if (!ft_strchr("NWSE01", value) && !ft_isspace(value))
	{
		printf("Map Error: Invalid character found: '%c'\n", value);
		return (FAILED);
	}
	return (SUCESS);
}

t_camera	get_player_coord(char **map)
{
	int			line;
	int			column;
	char		value;
	t_camera	cam;

	line = 0;
	cam = init_camera();
	while (map[line])
	{
		column = 0;
		while (map[line][column])
		{
			value = map[line][column];
			if (value == '\n')
				map[line][column] = '\0';
			else if (player_check(value, &cam, line, column))
				return (cam);
			column++;
		}
		line++;
	}
	return (cam);
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

int	invalid_map(char **data, t_map_size len)
{
	char		**map;
	t_camera	cam;

	map = extract_map(data, len);
	if (!map)
		return (FAILED);
	cam = get_player_coord(map);
	if (cam.pos_x == 0 || cam.pos_y == 0)
	{
		free(map);
		return (FAILED);
	}
	if (invalid_wall_check(map, len, cam))
	{
		free(map);
		return (FAILED);
	}
	free(map);
	return (SUCESS);
}
