/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buehara <buehara@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 01:13:27 by buehara           #+#    #+#             */
/*   Updated: 2026/11/08 02:24:44 by buehara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	flood_fill(char **map, t_map_size len)
{
	(void)map;
	(void)len;
	return (SUCESS);
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
	}
	if (!ft_strchr("NWSE01", value) && !ft_isspace(value))
	{
		printf("Map Error: Invalid character found: '%c'\n", value);
		return (FAILED);
	}
	return (SUCESS);
}

//TODO: Player Direction:
//N: column (x) 0, line (y) -1.0
//S: column (x) 0, line (y) 1.0
//E: column (x) 1.0, line (y) 0.0
//W: column (x) -1,0. line (y) 0.0
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

	(void)cam;
	map = extract_map(data, len);
	if (!map)
		return (FAILED);
	for (int i = 0; i < len.map_size; i++)
		printf("Map: %s", map[i]);
	cam = get_player_coord(map);
	if (cam.pos_x == 0 || cam.pos_y == 0)
		return (FAILED);
	printf("Player pos_x: %f | pos_y: %f\n", cam.pos_x, cam.pos_y);
	return (SUCESS);
}
