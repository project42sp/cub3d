/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_config.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-s <csilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 16:12:37 by csilva-s          #+#    #+#             */
/*   Updated: 2026/11/09 23:30:45 by buehara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

typedef struct	s_texture
{
	t_data	*no;
	t_data	*so;
	t_data	*ea;
	t_data	*we;
}	t_texture;

void	free_texture(t_texture **tex)
{
	if ((*tex)->no)
		free((*tex)->no);
	if ((*tex)->so)
		free((*tex)->so);
	if ((*tex)->we)
		free((*tex)->we);
	if ((*tex)->ea)
		free((*tex)->ea);
	free(*tex);
	*tex = NULL;
}

t_data	*init_texture_data(t_scene scene, char *path)
{
	t_data	*tex;

	tex = ft_calloc(sizeof(t_data), 1);
	if (!tex)
		return (NULL);
	tex->img = mlx_xpm_file_to_image(scene->mlx_instance, path, 
		&tex->width, &tex->height);
	if (!tex->img)
	{
		free(tex);
		return (NULL);
	}
	tex->addr = mlx_get_data_addr(tex->img, &tex->bits_per_pixel,
			&tex->line_length,  &tex->endian);
	if (!tex->addr)
	{
		free(tex->img);
		free(tex);
		return (NULL);
	}
	return (tex);
}

void	init_texture(t_scene *scene, t_texture **tex)
{
	(*tex)->we = init_texture_data(scene, scene->we);
	if (!(*tex)->we)
		free_texture(tex);
	(*tex)->no = init_texture_data(scene, scene->no);
	if (!(*tex)->no)
		free_texture(tex);
	(*tex)->ea = init_texture_data(scene, scene->ea);
	if (!(*tex)->ea)
		free_texture(tex);
	(*tex)->so = init_texture_data(scene, scene->so);
	if (!(*tex)->so)
		free_texture(tex);
}

int	graphic_config(t_scene **scene)
{
	(*scene)->mlx_instance = mlx_init();
	(*scene)->texture = ft_calloc(sizeof(t_texture), 1);
	if (!(*scene)->texture)
	{
		free((*scene)->mlx_instance);
		return (FALSE);
	}
	init_texture(scene, &(*scene)->texture);
	(*scene)->win = mlx_new_window((*scene)->mlx_instance, WIDTH, HEIGHT,
			"Windows 98 Screensaver\n");
	(*scene)->image_obj = ft_calloc(1, sizeof(t_data));
	(*scene)->image_obj->img = mlx_new_image((*scene)->mlx_instance,
			WIDTH, HEIGHT);
	if (!(*scene)->image_obj->img)
		exit_scene(*scene);
	(*scene)->image_obj->addr = mlx_get_data_addr((*scene)->image_obj->img,
			&(*scene)->image_obj->bits_per_pixel,
			&(*scene)->image_obj->line_length,
			&(*scene)->image_obj->endian);
	if (!(*scene)->image_obj->addr)
		exit_scene(*scene);
	return (TRUE);
}
