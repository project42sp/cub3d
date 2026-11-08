/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_action.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-s <csilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 01:23:30 by csilva-s          #+#    #+#             */
/*   Updated: 2026/11/08 02:44:12 by csilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	rotate_camera(t_scene *scene, int side, double dt)
{
	double	old_dir_x;
	double	old_plane_x;
	double	rotspeed;

	rotspeed = 2 * dt;
	old_dir_x = scene->camera.dir_x;
	scene->camera.dir_x = scene->camera.dir_x * cos(rotspeed * side)
		- scene->camera.dir_y * sin(rotspeed * side);
	scene->camera.dir_y = old_dir_x * sin(rotspeed * side)
		+ scene->camera.dir_y * cos(rotspeed * side);
	old_plane_x = scene->camera.plane_x;
	scene->camera.plane_x = scene->camera.plane_x * cos(rotspeed * side)
		- scene->camera.plane_y * sin(rotspeed * side);
	scene->camera.plane_y = old_plane_x * sin(rotspeed * side)
		+ scene->camera.plane_y * cos(rotspeed * side);
}

static void	move_forward(t_scene *scene, double dt)
{
	int		x_map;
	int		y_map;
	double	movespeed;

	movespeed = 1 * dt;
	x_map = (int)(scene->camera.pos_x + scene->camera.dir_x * movespeed);
	y_map = (int)(scene->camera.pos_y + scene->camera.dir_y * movespeed);
	scene->map[(int)scene->camera.pos_x][(int)scene->camera.pos_y] = '0';
	if (scene->map[x_map][(int)scene->camera.pos_y] == '0')
		scene->camera.pos_x += scene->camera.dir_x * movespeed;
	if (scene->map[(int)scene->camera.pos_x][y_map] == '0')
		scene->camera.pos_y += scene->camera.dir_y * movespeed;
}

int	key_action(t_scene *scene, double dt)
{
	if (scene->inputs.esc)
		exit_scene(scene);
	if (scene->inputs.arrow_right)
		rotate_camera(scene, -1, dt);
	if (scene->inputs.arrow_left)
		rotate_camera(scene, 1, dt);
	if (scene->inputs.w)
		move_forward(scene, dt);
	return (0);
}
