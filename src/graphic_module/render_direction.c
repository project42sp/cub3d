/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_direction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-s <csilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 17:36:27 by csilva-s          #+#    #+#             */
/*   Updated: 2026/11/07 16:22:26 by csilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static	t_pos	end_position_coords(t_pos init_pos, t_scene *scene)
{
	t_pos	pos;

	pos.x = init_pos.x + scene->camera.dir_x * 32;
	pos.y = init_pos.y + scene->camera.dir_y * 32;
	return (pos);
}

static	t_pos	init_position_coords(t_scene *scene)
{
	t_pos	pos;

	pos.x = floor(scene->camera.pos_x * 16);
	pos.y = floor(scene->camera.pos_y * 16);
	return (pos);
}

static t_pos	initalize_step(t_pos init, t_pos end)
{
	t_pos	step;

	if (init.x > end.x)
		step.x = -1;
	else
		step.x = 1;
	if (init.y > end.y)
		step.y = -1;
	else
		step.y = 1;
	return (step);
}

void	render_direction(t_scene *scene)
{
	t_pos	init_pos;
	t_pos	end_pos;
	t_pos	delta;

	init_pos = init_position_coords(scene);
	end_pos = end_position_coords(init_pos, scene);
	delta.x = abs((int)(end_pos.x - init_pos.x));
	delta.y = abs((int)(end_pos.y - init_pos.y));
	bresengam(init_pos, end_pos, delta, scene);
}

void	bresengam(t_pos init_pos, t_pos end_pos, t_pos delta, t_scene *scene)
{
	t_pos	step;
	int		err;

	step = initalize_step(init_pos, end_pos);
	err = delta.x - delta.y;
	while (1)
	{
		if ((init_pos.y < 0 || init_pos.x < 0)
			|| (init_pos.x == end_pos.x && init_pos.y == end_pos.y))
			break ;
		draw_direction_line(scene->image_obj, init_pos, RED);
		if ((2 * err) > -delta.y)
		{
			err -= delta.y;
			init_pos.x += step.x;
		}
		if ((2 * err) < delta.x)
		{
			err += delta.x;
			init_pos.y += step.y;
		}
	}
}
