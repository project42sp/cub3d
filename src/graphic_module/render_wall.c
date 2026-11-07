/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-s <csilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 14:07:42 by csilva-s          #+#    #+#             */
/*   Updated: 2026/11/07 15:19:12 by csilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_wall(t_scene *scene, int wall_height, int x)
{
	int	start;
	int	end;
	int	i;

	start = -wall_height / 2 + HEIGHT / 2;
	end = wall_height / 2 + HEIGHT / 2;
	i = 0;
	if (start < 0)
		start = 0;
	if (end >= HEIGHT)
		end = HEIGHT - 1;
	while (i < start)
	{
		draw_pixel(scene->image_obj, x, i, GREY);
		i++;
	}
	while (start != end)
	{
		draw_pixel(scene->image_obj, x, start, GREEN);
		start++;
	}
}
