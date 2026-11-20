/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_ingestion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buehara <buehara@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 23:50:05 by buehara           #+#    #+#             */
/*   Updated: 2026/11/15 11:36:51 by buehara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/cub3d.h"

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

t_data	*init_texture_data(t_scene *scene, char *path)
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
			&tex->line_length, &tex->endian);
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
