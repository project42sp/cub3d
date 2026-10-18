/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-s <csilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 01:29:04 by csilva-s          #+#    #+#             */
/*   Updated: 2026/10/18 18:53:00 by csilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
		free(map[i++]);
	free(map);
}

int	exit_scene(t_scene *scene)
{
	if (scene->map)
		free_map(scene->map);
	mlx_destroy_image(scene->mlx_instance, scene->image_obj->img);
	mlx_clear_window(scene->mlx_instance, scene->win);
	mlx_destroy_display(scene->mlx_instance);
	free(scene->image_obj);
	free(scene);
	exit(0);
}
