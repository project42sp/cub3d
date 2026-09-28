/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-s <csilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 20:16:44 by csilva-s          #+#    #+#             */
/*   Updated: 2026/09/27 20:50:01 by csilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_game(t_scene *scene)
{
	scene->map = render_map();
	render_map(scene->map);
}


//TODO: Implement exit game function
int	exit_game(void)
{
	exit(0);
}

int	handle_keypress(int keycode, void *scene)
{
	if (keycode == 65307 && scene)
		exit(0);
	if (keycode == 119)
		ft_printf("W\n");
	if (keycode == 97)
		ft_printf("A\n");
	if (keycode == 115)
		ft_printf("S\n");
	if (keycode == 100)
		ft_printf("D\n");
	return (0);
}

int	main(int argc, char **argv)
{
	t_scene	*scene;

	if (argc != 2)
		return (1);
	scene = parser(argv[1]);
	if (scene)
		return (FAILED);
	scene = ft_calloc(1, sizeof(t_scene));
	scene->mlx = mlx_init();
	scene->win = mlx_new_window(scene->mlx, 800, 600, "Windows 98 Screensaver");
	mlx_hook(scene->win, 2, 1L << 0, handle_keypress, scene);
	mlx_hook(scene->win, 17, 0, exit_game, scene);
	init_game(scene);
	mlx_loop(scene->mlx);
	return (0);
}
