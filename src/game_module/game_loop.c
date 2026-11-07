/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-s <csilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 00:31:34 by csilva-s          #+#    #+#             */
/*   Updated: 2026/11/07 15:15:32 by csilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

int	game_loop(t_scene *scene)
{
	long	current;
	long	elapsed;

	current = get_time();
	if (current < 0)
		return (-1);
	elapsed = current - scene->last_time_render;
	if (elapsed >= 60)
	{
		key_action(scene);
		scene->last_time_render = current;
		clear_frame(scene);
		render(scene);
		mlx_put_image_to_window(scene->mlx_instance,
			scene->win, scene->image_obj->img, 0, 0);
	}
	return (0);
}
