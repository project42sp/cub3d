/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-s <csilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 16:10:08 by csilva-s          #+#    #+#             */
/*   Updated: 2026/10/25 20:57:03 by csilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	draw_player(t_data *image_obj, int y, int x, int color)
{
	int	i;
	int	j;

	i = y;
	j = x;
	while (i <= y + 8)
	{
		j = x;
		while (j <= x + 8)
		{
			draw_pixel(image_obj, j, i, color);
			j++;
		}
		i++;
	}
}

void	render_player(t_scene *scene)
{
	int	x;
	int	y;

	x = scene->player.x * 16;
	y = scene->player.y * 16;
	ft_printf("%d\n", x);
	ft_printf("%d", y);
	draw_player(scene->image_obj, y, x, RED);
}
