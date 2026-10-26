/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-s <csilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 16:06:40 by csilva-s          #+#    #+#             */
/*   Updated: 2026/10/25 22:00:15 by csilva-s         ###   ########.fr       */
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

void	render(t_scene *scene)
{
	if (scene->map)
		render_map(scene);
	if (scene->player.x > 0 && scene->player.y >= 0)
	{
		render_player(scene);
		render_direction(scene);
	}
}
