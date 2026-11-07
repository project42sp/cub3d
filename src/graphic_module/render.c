/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-s <csilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 16:06:40 by csilva-s          #+#    #+#             */
/*   Updated: 2026/11/07 16:43:29 by csilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_wall(t_scene *scene, int wall_height, int x)
{
	int	start;
	int	end;

	start = -wall_height / 2 + HEIGHT / 2;
	end = wall_height / 2 + HEIGHT / 2;
	if (start < 0)
		start = 0;
	if (end >= HEIGHT)
		end = HEIGHT - 1;
	while (start != end)
	{
		draw_pixel(scene->image_obj, x, start, GREEN);
		start++;
	}
}

t_ray	init_ray(t_scene *scene, double dir_x, double dir_y)
{
	t_ray	ray;

	ray.dir.x = dir_x;
	ray.dir.y = dir_y;
	ray.step_x = 1;
	ray.step_y = 1;
	ray.delta_dist.x = INFINITY;
	ray.delta_dist.y = INFINITY;
	if (ray.dir.x < 0)
		ray.step_x = -1;
	if (ray.dir.y < 0)
		ray.step_y = -1;
	if (ray.dir.x != 0)
		ray.delta_dist.x = fabs(1.0 / ray.dir.x);
	if (ray.dir.y != 0)
		ray.delta_dist.y = fabs(1.0 / ray.dir.y);
	ray.map_x = (int)floor(scene->camera.pos_x);
	ray.map_y = (int)floor(scene->camera.pos_y);
	ray.hit = 0;
	ray.side_dist.x = (ray.map_x + 1.0 - scene->camera.pos_x)
		* ray.delta_dist.x;
	ray.side_dist.y = (ray.map_y + 1.0 - scene->camera.pos_y)
		* ray.delta_dist.y;
	return (ray);
}

double	dda(t_scene *scene, double dir_x, double dir_y)
{
	t_ray	ray;

	ray = init_ray(scene, dir_x, dir_y);
	while (!ray.hit)
	{
		if (ray.side_dist.x < ray.side_dist.y)
		{
			ray.side_dist.x += ray.delta_dist.x;
			ray.map_x += ray.step_x;
			ray.side = 0;
		}
		else
		{
			ray.side_dist.y += ray.delta_dist.y;
			ray.map_y += ray.step_y;
			ray.side = 1;
		}
		if (scene->map[ray.map_y][ray.map_x] == '1')
			ray.hit = 1;
	}
	if (ray.side == 0)
		ray.perp_dist = ray.side_dist.x - ray.delta_dist.x;
	else
		ray.perp_dist = ray.side_dist.y - ray.delta_dist.y;
	return (ray.perp_dist);
}

void	render(t_scene *scene)
{
	int		x;
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	double	perp_dist;

	x = 0;
	while (x < WIDTH)
	{
		camera_x = 2.0 * x / (double)WIDTH - 1.0;
		ray_dir_x = scene->camera.dir_x + scene->camera.plane_x * camera_x;
		ray_dir_y = scene->camera.dir_y + scene->camera.plane_y * camera_x;
		perp_dist = dda(scene, ray_dir_x, ray_dir_y);
		draw_wall(scene, (int)(HEIGHT / perp_dist), x);
		x++;
	}
}
