/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-s <csilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 20:16:44 by csilva-s          #+#    #+#             */
/*   Updated: 2026/11/07 00:31:55 by csilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// Example of a map 4x4 with player looking to north
// static void	mock_initializer(t_scene **scene)
// {
// 	(*scene)->map = ft_split("1111.1001.10N1.1111", '.');
// 	(*scene)->player.x = 2;
// 	(*scene)->player.y = 2;
// 	(*scene)->player.dir_x = 0;
// 	(*scene)->player.dir_y = -1;
// }

int	main(int argc, char **argv)
{
	t_scene	*scene;

	if (argc != 2)
		return (1);
	scene = parser(argv[1]);
	if (!scene)
	{
		free(scene);
		printf("Cub3D: Finishing program.\n");
		return (FAILED);
	}
	scene = ft_calloc(1, sizeof(t_scene));
	graphic_config(&scene);
	key_handler(scene);
	mlx_loop_hook(scene->mlx_instance, game_loop, scene);
	mlx_loop(scene->mlx_instance);
	exit_scene(scene);
	return (0);
}
