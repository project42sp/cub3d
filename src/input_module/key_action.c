/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_action.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-s <csilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 01:23:30 by csilva-s          #+#    #+#             */
/*   Updated: 2026/11/03 01:28:16 by csilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// ISSUE: Think how to reduce these conditionals
int	key_action(t_scene *scene)
{
	if (scene->inputs.esc == 1)
	{
		exit_scene(scene);
	}
	else if (scene->inputs.w == 1)
	{
		scene->player.dir_x = 0;
		scene->player.dir_y = -1;
		scene->player.y--;
	}
	else if (scene->inputs.s == 1)
	{
		scene->player.dir_x = 0;
		scene->player.dir_y = 1;
		scene->player.y++;
	}
	else if (scene->inputs.a == 1)
	{
		scene->player.dir_x = -1;
		scene->player.dir_y = 0;
		scene->player.x--;
	}
	else if (scene->inputs.d == 1)
	{
		scene->player.dir_x = 1;
		scene->player.dir_y = 0;
		scene->player.x++;
	}
	if (scene->inputs.a && scene->inputs.w)
	{
		scene->player.dir_x = -1;
		scene->player.dir_y = -1;
		scene->player.x -= 0.5;
		scene->player.y -= 0.5;
	}
	if (scene->inputs.w && scene->inputs.d)
	{
		scene->player.dir_x = 1;
		scene->player.dir_y = -1;
		scene->player.x += 0.5;
		scene->player.y -= 0.5;
	}
	if (scene->inputs.d && scene->inputs.s)
	{
		scene->player.dir_x = 1;
		scene->player.dir_y = 1;
		scene->player.x += 0.5;
		scene->player.y += 0.5;
	}
	if (scene->inputs.s && scene->inputs.a)
	{
		scene->player.dir_x = -1;
		scene->player.dir_y = 1;
		scene->player.x -= 0.5;
		scene->player.y += 0.5;
	}
	return (0);
}
