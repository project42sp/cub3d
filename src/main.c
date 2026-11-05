/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-s <csilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 20:16:44 by csilva-s          #+#    #+#             */
/*   Updated: 2026/11/04 23:12:40 by csilva-s         ###   ########.fr       */
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

static long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

int	game_loop(t_scene *scene)
{
	long	current;
	long	elapsed;

	current = get_time();
	if (current < 0)
		return (-1);
	elapsed = current - scene->last_time_render;
	if (elapsed >= 60)
	{
		key_action(scene);
		scene->last_time_render = current;
		clear_frame(scene);
		render(scene);
		mlx_put_image_to_window(scene->mlx_instance,
			scene->win, scene->image_obj->img, 0, 0);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_scene	*scene;

	if (argc != 2)
		return (1);
	scene = parser(argv[1]);
	if (!scene)
	{
		printf("Cub3D: Finishing program.\n\n");
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
