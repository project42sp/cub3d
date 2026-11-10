/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-s <csilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 16:06:40 by csilva-s          #+#    #+#             */
/*   Updated: 2026/11/09 23:37:13 by buehara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

//ISSUE: Change the wall, ceil and floor color.
void	draw_wall(t_scene *scene, t_ray ray, int x)
{
	int	start;
	int	end;
	int	wall_height;
	int	i;

	wall_height = (int)(HEIGHT / ray.perp_dist);
	start = -wall_height / 2 + HEIGHT / 2;
	end = wall_height / 2 + HEIGHT / 2;
	i = 0;
	if (start < 0)
		start = 0;
	if (end >= HEIGHT)
		end = HEIGHT - 1;
	while (i < start)
		draw_pixel(scene->image_obj, x, i++, scene->ceil.hex);
	i = end;
	while (i < HEIGHT)
		draw_pixel(scene->image_obj, x, i++, scene->floor.hex);
	i = 0;
	while (start < end)
	{
		
	}
}

t_pos	init_side_dist(t_scene *scene, t_ray ray)
{
	t_pos	side_dist;

	if (ray.dir.x < 0)
		side_dist.x = (scene->camera.pos_x - ray.map_x)
			* ray.delta_dist.x;
	else
		side_dist.x = (ray.map_x + 1.0 - scene->camera.pos_x)
			* ray.delta_dist.x;
	if (ray.dir.y < 0)
		side_dist.y = (scene->camera.pos_y - ray.map_y)
			* ray.delta_dist.y;
	else
		side_dist.y = (ray.map_y + 1.0 - scene->camera.pos_y)
			* ray.delta_dist.y;
	return (side_dist);
}

t_ray	init_ray(t_scene *scene, double dir_x, double dir_y)
{
	t_ray	ray;

	ray.map_x = (int)(scene->camera.pos_x);
	ray.map_y = (int)(scene->camera.pos_y);
	ray.dir.x = dir_x;
	ray.dir.y = dir_y;
	ray.step_x = 1;
	ray.step_y = 1;
	if (ray.dir.x == 0)
		ray.delta_dist.x = INFINITY;
	else
		ray.delta_dist.x = fabs(1 / ray.dir.x);
	if (ray.dir.y == 0)
		ray.delta_dist.y = INFINITY;
	else
		ray.delta_dist.y = fabs(1 / ray.dir.y);
	if (ray.dir.x < 0)
		ray.step_x = -1;
	if (ray.dir.y < 0)
		ray.step_y = -1;
	ray.side_dist = init_side_dist(scene, ray);
	ray.hit = 0;
	return (ray);
}

t_ray	dda(t_scene *scene, double dir_x, double dir_y)
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
	return (ray);
}

void	render(t_scene *scene)
{
	int		x;
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;

	x = 0;
	while (x < WIDTH)
	{
		camera_x = 2.0 * x / (double)WIDTH - 1.0;
		ray_dir_x = scene->camera.dir_x + scene->camera.plane_x * camera_x;
		ray_dir_y = scene->camera.dir_y + scene->camera.plane_y * camera_x;
		draw_wall(scene, dda(scene, ray_dir_x, ray_dir_y), x);
		x++;
	}
}
