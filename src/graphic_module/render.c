/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-s <csilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 16:06:40 by csilva-s          #+#    #+#             */
/*   Updated: 2026/11/07 03:17:28 by csilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_tile(t_data *image_obj, int y, int x, int color)
{
	int	i;
	int	j;

	i = y;
	j = x;
	while (i <= y + 16)
	{
		j = x;
		while (j <= x + 16)
		{
			draw_pixel(image_obj, j, i, color);
			j++;
		}
		i++;
	}
}

void	initialize_camera(t_scene *scene)
{
	scene->camera.pos_x = 2.5;
	scene->camera.pos_y = 2.5;
	scene->camera.dir_x = 1.0;
	scene->camera.dir_y = 0.0;
	scene->camera.plane_x = 0.0;
	scene->camera.plane_y = 0.42;
}

int	dda(t_scene *scene, double dir_x, double dir_y)
{
	t_ray	ray;

	ray.map_x = (int)floor(scene->camera.pos_x);
	ray.map_y = (int)floor(scene->camera.pos_y);
	ray.dir_x = dir_x;
	ray.dir_y = dir_y;
	if (ray.dir_x < 0)
		ray.step_x = -1;
	else
		ray.step_x = 1;
	if (ray.dir_y < 0)
		ray.step_y = -1;
	else
		ray.step_y = 1;
	if (ray.dir_x == 0)
		ray.delta_dist_x = INFINITY;
	else
		ray.delta_dist_x = fabs(1.0 / ray.dir_x);
	if (ray.dir_y == 0)
		ray.delta_dist_y = INFINITY;
	else
		ray.delta_dist_y = fabs(1.0 / ray.dir_y);
	ray.hit = 0;
	ray.side_dist_x = (ray.map_x + 1.0 - scene->camera.pos_x) * ray.delta_dist_x;
	ray.side_dist_y = (ray.map_y + 1.0 - scene->camera.pos_y) * ray.delta_dist_y;
	while (!ray.hit)
	{
		if (ray.side_dist_x < ray.side_dist_y)
		{
			ray.side_dist_x += ray.delta_dist_x;
			ray.map_x += ray.step_x;
			ray.side = 0;
		}
		else
		{
			ray.side_dist_y += ray.delta_dist_y;
			ray.map_y += ray.step_y;
			ray.side = 1;
		}
		if (scene->map[ray.map_y][ray.map_x] == '1')
			ray.hit = 1;
	}
	if (ray.side == 0)
		ray.perp_dist = ray.side_dist_x - ray.delta_dist_x;
	else
		ray.perp_dist = ray.side_dist_y - ray.delta_dist_y;
	return (ray.perp_dist);
}

// Must to do:
// Every column of screen:
//		Initialize ray  [x]
//		throw ray		[x]
//		calculate distance [ ]
//		render wall height [ ]
void	render(t_scene *scene)
{
	int		x;
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		perp_dist;

	x = 0;
	initialize_camera(scene);
	while (x < WIDTH)
	{
		camera_x = 2.0 * x / (double)WIDTH - 1.0;
		ray_dir_x = scene->camera.dir_x + scene->camera.plane_x * camera_x;
		ray_dir_y = scene->camera.dir_y + scene->camera.plane_y * camera_x;
		perp_dist = dda(scene, ray_dir_x, ray_dir_y);
		x++;
	}
}
