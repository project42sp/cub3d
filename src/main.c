/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-s <csilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 20:16:44 by csilva-s          #+#    #+#             */
/*   Updated: 2026/10/12 17:32:45 by csilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_scene	*scene;

	scene = ft_calloc(1, sizeof(t_scene));
	scene->mlx_instance = mlx_init();
	scene->win = mlx_new_window(scene->mlx_instance, 1280, 720,
			"Windows 98 Screensaver\n");
	key_handler(scene);
	mlx_loop(scene->mlx_instance);
	if (argc != 2)
		return (1);
	scene = parser(argv[1]);
	if (!scene)
		return (FAILED);
	return (0);
}
