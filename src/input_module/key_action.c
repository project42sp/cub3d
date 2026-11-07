/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_action.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-s <csilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 01:23:30 by csilva-s          #+#    #+#             */
/*   Updated: 2026/11/07 19:00:29 by csilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	key_action(t_scene *scene)
{
	if (scene->inputs.esc)
		exit_scene(scene);
	if (scene->inputs.arrow_up)
	{
		scene->camera.dir_x = 0.0;
		scene->camera.dir_y = -1.0;
	}
	else if (scene->inputs.arrow_right)
	{
		scene->camera.dir_x = 1.0;
		scene->camera.dir_y = 0.0;
	}
	else if (scene->inputs.arrow_left)
	{
		scene->camera.dir_x = -1.0;
		scene->camera.dir_y = 0.0;
	}
	else if (scene->inputs.arrow_down)
	{
		scene->camera.dir_x = 0.0;
		scene->camera.dir_y = 1.0;
	}
	return (0);
}
