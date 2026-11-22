/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-s <csilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 20:16:44 by csilva-s          #+#    #+#             */
/*   Updated: 2026/11/22 17:48:02 by buehara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
