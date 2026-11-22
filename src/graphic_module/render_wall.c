/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buehara <buehara@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 16:17:04 by buehara           #+#    #+#             */
/*   Updated: 2026/11/22 17:31:53 by buehara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static unsigned int	my_mlx_pixel_get(t_data *img, int x, int y)
{
	char	*src;

	if (x >= img->width || y >= img->height)
		return (0);
	if (x < 0 || y < 0)
		return (0);
	src = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	return (*(unsigned int *)src);
}

static t_data	*get_wall_direction(t_scene *scene, t_ray ray)
{
	if (ray.side == 0 && ray.dir.x > 0)
		return (scene->texture->we);
	if (ray.side == 0 && ray.dir.x < 0)
		return (scene->texture->ea);
	if (ray.side && ray.dir.y > 0)
		return (scene->texture->no);
	if (ray.side && ray.dir.y < 0)
		return (scene->texture->so);
	return (NULL);
}

static void	print_wall(t_scene *scene, t_ray ray, int x, t_drawall wall)
{
	t_data	*tex;
	double	color_step;

	tex = get_wall_direction(scene, ray);
	if (!tex)
		return ;
	wall.step = 1.0 * tex->height / wall.height;
	wall.texture_x = (int)(wall.x * (double)tex->width);
	if ((ray.side == 0 && ray.dir.x < 0) || (ray.side == 1 && ray.dir.y > 0))
		wall.texture_x = tex->width - wall.texture_x - 1;
	color_step = (wall.start - HEIGHT / 2 + wall.height / 2) * wall.step;
	while (wall.start != wall.end && wall.start < HEIGHT)
	{
		if (wall.start >= 0)
		{
			wall.color = my_mlx_pixel_get(tex, wall.texture_x, color_step);
			draw_pixel(scene->image_obj, x, wall.start, wall.color);
		}
		color_step += wall.step;
		wall.start++;
	}
}

void	draw_img(t_scene *scene, t_ray ray, int x)
{
	t_drawall	wall;
	int			i;

	wall.height = (int)(HEIGHT / ray.perp_dist);
	wall.start = -wall.height / 2 + HEIGHT / 2;
	wall.end = wall.height / 2 + HEIGHT / 2;
	i = 0;
	if (wall.start < 0)
		wall.start = 0;
	if (wall.end >= HEIGHT)
		wall.end = HEIGHT - 1;
	if (ray.side == 0)
		wall.x = scene->camera.pos_y + ray.perp_dist * ray.dir.y;
	else
		wall.x = scene->camera.pos_x + ray.perp_dist * ray.dir.x;
	wall.x -= floor(wall.x);
	while (i < wall.start)
		draw_pixel(scene->image_obj, x, i++, scene->ceil.hex);
	i = wall.end;
	while (i < HEIGHT)
		draw_pixel(scene->image_obj, x, i++, scene->floor.hex);
	print_wall(scene, ray, x, wall);
}
