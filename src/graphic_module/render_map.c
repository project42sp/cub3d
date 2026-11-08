/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-s <csilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 23:22:14 by csilva-s          #+#    #+#             */
/*   Updated: 2026/10/25 20:55:02 by csilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	render_map(t_scene *scene)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (scene->map[i] != NULL)
	{
		j = 0;
		while (scene->map[i][j] != 0)
		{
			if (scene->map[i][j] == '1')
				draw_tile(scene->image_obj, i * 16, j * 16, GREEN);
			else
				draw_tile(scene->image_obj, i * 16, j * 16, BLACK);
			j++;
		}
		i++;
	}
}
