/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-s <csilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 01:29:04 by csilva-s          #+#    #+#             */
/*   Updated: 2026/11/09 16:29:59 by buehara          ###   ########.fr       */
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
	free(scene->ea);
	free(scene->so);
	free(scene->we);
	free(scene->no);
	mlx_destroy_image(scene->mlx_instance, scene->image_obj->img);
	mlx_clear_window(scene->mlx_instance, scene->win);
	mlx_destroy_display(scene->mlx_instance);
	free(scene->image_obj);
	free(scene);
	exit(0);
}
