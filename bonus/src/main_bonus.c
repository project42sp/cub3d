/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-s <csilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 20:15:03 by csilva-s          #+#    #+#             */
/*   Updated: 2026/11/14 22:47:17 by csilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_scene	*scene;

	if (argc != 2)
		return (1);
	scene = parser(argv[1]);
	if (!scene)
	{
		scene = NULL;
		printf("Cub3D: Finishing program.\n");
		return (FAILED);
	}
	graphic_config(&scene);
	key_handler(scene);
	scene->last_time_render = get_time();
	mlx_loop_hook(scene->mlx_instance, game_loop_bonus, scene);
	mlx_loop(scene->mlx_instance);
	exit_scene(scene);
	return (0);
}
