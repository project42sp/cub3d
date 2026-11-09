/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buehara <buehara@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 01:13:27 by buehara           #+#    #+#             */
/*   Updated: 2026/11/09 17:27:50 by buehara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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

static void	set_player_direction(char value, t_camera *cam)
{
	double	fov;

	if (value == 'N')
		cam->dir_y = -1.0;
	else if (value == 'S')
		cam->dir_y = 1.0;
	else if (value == 'E')
		cam->dir_x = 1.0;
	else if (value == 'W')
		cam->dir_x = -1.0;
	fov = 0.42;
	cam->plane_x = -cam->dir_y * fov;
	cam->plane_y = cam->dir_x * fov;
}

static int	player_check(char value, t_camera *cam, int line, int column)
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
		ft_split_free(map, len.map_size);
		return (FAILED);
	}
	if (invalid_wall_check(map, len, cam))
	{
		ft_split_free(map, len.map_size);
		return (FAILED);
	}
	ft_split_free(map, len.map_size);
	return (SUCESS);
}

