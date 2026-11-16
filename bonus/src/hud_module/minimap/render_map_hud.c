/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map_hud.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-s <csilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 22:41:59 by csilva-s          #+#    #+#             */
/*   Updated: 2026/11/15 22:35:28 by csilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/cub3d.h"

int	count_line(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int	count_column(char **map)
{
	int	i;
	int	j;
	int	max;

	i = 0;
	j = 0;
	max = j;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			j++;
		}
		if (j > max)
			max = j;
		i++;
	}
	return (max);
}

void	should_draw(t_scene *scene, t_pos player, t_pos start)
{
	int		map_height;
	int		line_length;
	t_vec2	start_vec;

	start_vec.x = (int)start.x * 32;
	start_vec.y = (int)start.y * 32;
	map_height = count_line(scene->map);
	line_length = count_column(scene->map);
	if ((int)player.x >= 0 && (int)player.y >= 0 && (int)player.y < map_height
		&& (int)player.x < line_length)
	{
		if (scene->map[(int)player.y][(int)player.x] == '1')
			draw_tile(scene->image_obj, start_vec, WHITE, 32);
	}
}

void	player_around(t_scene *scene)
{
	t_pos	player;
	t_pos	limits;
	t_pos	start;

	start.y = 0;
	player.y = (int)floor(scene->camera.pos_y) - 3;
	limits.y = player.y + 7;
	limits.x = (int)floor(scene->camera.pos_x) + 3;
	while ((int)player.y <= (int)limits.y)
	{
		player.x = (int)floor(scene->camera.pos_x) - 4;
		start.x = 0;
		while ((int)player.x <= (int)limits.x)
		{
			should_draw(scene, player, start);
			player.x++;
			start.x++;
		}
		player.y++;
		start.y++;
	}
}

void	render_map_hud(t_scene *scene)
{
	t_vec2	map;
	t_vec2	index;

	map.x = WIDTH / 4;
	map.y = HEIGHT / 3;
	index.x = 0;
	index.y = 0;
	while (index.x <= map.x)
	{
		index.y = 0;
		while (index.y <= map.y)
		{
			draw_pixel(scene->image_obj, index.x, index.y, BLACK);
			if (index.y % 32 == 0)
				draw_pixel(scene->image_obj, index.x, index.y, WHITE);
			if (index.x % 32 == 0)
				draw_pixel(scene->image_obj, index.x, index.y, WHITE);
			index.y++;
		}
		index.x++;
	}
	map.y = (map.y - 64) / 2;
	map.x = map.x / 2;
	player_around(scene);
	draw_tile(scene->image_obj, map, RED, 16);
}
