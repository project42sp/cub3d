/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_config.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-s <csilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 16:12:37 by csilva-s          #+#    #+#             */
/*   Updated: 2026/10/18 18:40:23 by csilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_pixel(t_data *image_obj, int x, int y, int color)
{
	char	*dest_pixel;

	dest_pixel = image_obj->addr
		+ (y * image_obj->line_length + x * (image_obj->bits_per_pixel / 8));
	*(unsigned int *)dest_pixel = color;
}

void	graphic_config(t_scene **scene)
{
	(*scene)->mlx_instance = mlx_init();
	(*scene)->win = mlx_new_window((*scene)->mlx_instance, 1280, 720,
			"Windows 98 Screensaver\n");
	(*scene)->image_obj = ft_calloc(1, sizeof(t_data));
	(*scene)->image_obj->img = mlx_new_image((*scene)->mlx_instance, 1280, 720);
	if (!(*scene)->image_obj->img)
	{
		exit_scene(*scene);
	}
	(*scene)->image_obj->addr = mlx_get_data_addr((*scene)->image_obj->img,
			&(*scene)->image_obj->bits_per_pixel,
			&(*scene)->image_obj->line_length,
			&(*scene)->image_obj->endian);
	if (!(*scene)->image_obj->addr)
		exit_scene(*scene);
}
