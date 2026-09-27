/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-s <csilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 20:16:44 by csilva-s          #+#    #+#             */
/*   Updated: 2026/09/27 17:00:13 by csilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int argc, char **argv)
{
	void	*mlx;
	t_scene	*scene;

	write (1, "Windows 98 Screensaver\n", 23);
	mlx = mlx_init();
	mlx_new_window(mlx, 1024, 516, "Cub3d");
	mlx_loop(mlx);
	if (argc != 2)
		return (1);
	scene = parser(argv[1]);
	if (!scene)
		return (FAILED);
	return (0);
}
