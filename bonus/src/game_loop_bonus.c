/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-s <csilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 22:45:43 by csilva-s          #+#    #+#             */
/*   Updated: 2026/11/15 17:18:32 by csilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	game_loop_bonus(t_scene *scene)
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
	key_action(scene, dt);
	clear_frame(scene);
	render(scene);
	render_hud(scene);
	mlx_put_image_to_window(scene->mlx_instance,
		scene->win, scene->image_obj->img, 0, 0);
	scene->last_time_render = current;
	return (0);
}
