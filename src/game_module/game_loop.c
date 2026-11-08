/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-s <csilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 00:31:34 by csilva-s          #+#    #+#             */
/*   Updated: 2026/11/08 02:49:23 by csilva-s         ###   ########.fr       */
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
	double	dt;

	current = get_time();
	elapsed = current - scene->last_time_render;
	if (elapsed <= 0)
		return (0);
	dt = elapsed / 1000.0;
	if (dt > 0.05)
		dt = 0.05;
	printf("\n%.6f", dt);
	key_action(scene, dt);
	clear_frame(scene);
	render(scene);
	mlx_put_image_to_window(scene->mlx_instance,
		scene->win, scene->image_obj->img, 0, 0);
	scene->last_time_render = current;
	return (0);
}
