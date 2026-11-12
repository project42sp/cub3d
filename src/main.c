/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-s <csilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 20:16:44 by csilva-s          #+#    #+#             */
/*   Updated: 2026/11/09 17:44:51 by buehara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// Example of a map 4x4 with player looking to north
// static void	mock_initializer(t_scene **scene)
// {
// 	  const char *map =
//         "1111111111111111\n"
//         "1000001000000001\n"
//         "1000000100000001\n"
//         "1000000010000001\n"
//         "1000L00001000001\n"
//         "1000000000100001\n"
//         "1000000000010001\n"
//         "1000000000001001\n"
//         "1000000000000101\n"
//         "1000000000000001\n"
//         "1000000000000001\n"
//         "1111111111111111";
// 	(*scene)->map = ft_split(map, '\n');
//     (*scene)->camera.pos_x = 4.5;
//     (*scene)->camera.pos_y = 4.5;
//     (*scene)->camera.dir_x = -1.0;
//     (*scene)->camera.dir_y = 0.0;
//     (*scene)->camera.plane_x = 0.0;
//     (*scene)->camera.plane_y = 0.82;
// }
//
void	ft_free_scene(t_scene *scene)
{
	int	idx;

	free(scene->ea);
	free(scene->we);
	free(scene->no);
	free(scene->so);
	idx = 0;
	while (scene->map[idx])
		idx++;
	ft_split_free(scene->map, idx);
	free(scene);
	printf("Free function done");
}

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
	mlx_loop_hook(scene->mlx_instance, game_loop, scene);
	mlx_loop(scene->mlx_instance);
	exit_scene(scene);
	return (0);
}
