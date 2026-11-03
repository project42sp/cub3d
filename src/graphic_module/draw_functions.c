/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-s <csilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 21:35:52 by csilva-s          #+#    #+#             */
/*   Updated: 2026/11/03 01:06:50 by csilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_pixel(t_data *image_obj, int x, int y, int color)
{
	char	*dest_pixel;

	dest_pixel = image_obj->addr
		+ (y * image_obj->line_length + x * (image_obj->bits_per_pixel / 8));
	*(unsigned int *)dest_pixel = color;
}

void	draw_direction_line(t_data *image_obj, t_pos pos, int color)
{
	int	i;
	int	j;

	i = pos.y;
	j = pos.x;
	while (i <= pos.y + 4)
	{
		j = pos.x;
		while (j <= pos.x + 4)
		{
			draw_pixel(image_obj, j, i, color);
			j++;
		}
		i++;
	}
}

void	clear_frame(t_scene *scene)
{
	int	x;
	int	y;

	x = 0;
	y = x;
	while (y <= HEIGHT)
	{
		x = 0;
		while (x <= WIDTH)
		{
			draw_pixel(scene->image_obj, x, y, BLACK);
			x++;
		}
		y++;
	}
}
