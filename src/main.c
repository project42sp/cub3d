/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-s <csilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 20:16:44 by csilva-s          #+#    #+#             */
/*   Updated: 2026/10/19 00:30:24 by csilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_scene	*scene;

	if (argc != 2)
		return (1);
	scene = parser(argv[1]);
	if (scene)
	{
		printf("Cub3D: Finishing program.\n\n");
		return (FAILED);
	}
	scene = ft_calloc(1, sizeof(t_scene));
	graphic_config(&scene);
	key_handler(scene);
	scene->map = ft_split("1111111111111111.1000000000000001.10000000000N0001.1111111111111111", '.');
	render_map(scene);
	mlx_put_image_to_window(scene->mlx_instance,
		scene->win, scene->image_obj->img, 0, 0);
	mlx_loop(scene->mlx_instance);
	exit_scene(scene);
	return (0);
}
