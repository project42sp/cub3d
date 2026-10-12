/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-s <csilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 19:29:51 by csilva-s          #+#    #+#             */
/*   Updated: 2026/10/12 17:25:18 by csilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	key_handler(t_scene *scene)
{
	mlx_hook(scene->win, 2, 1L << 0, key_press, scene);
	mlx_hook(scene->win, 3, 1L << 1, key_release, scene);
	mlx_loop_hook(scene->mlx_instance, key_action, scene);
	mlx_hook(scene->win, 17, 0, exit_scene, scene);
}
