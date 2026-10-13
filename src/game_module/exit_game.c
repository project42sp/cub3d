/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-s <csilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 01:29:04 by csilva-s          #+#    #+#             */
/*   Updated: 2026/10/12 17:25:27 by csilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	exit_scene(t_scene *scene)
{
	mlx_clear_window(scene->mlx_instance, scene->win);
	mlx_destroy_display(scene->mlx_instance);
	free(scene);
	exit(0);
}
