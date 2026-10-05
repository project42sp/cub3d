/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-s <csilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 19:29:51 by csilva-s          #+#    #+#             */
/*   Updated: 2026/10/04 23:04:19 by csilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

//Accept Criterias:
// - The information should be retained if any key is pressed or released.
void	key_handler(t_scene **scene)
{
	(*scene)->inputs = ft_calloc(1, sizeof(t_input));
	mlx_hook((*scene)->win, 2, 1L << 0, key_press, *scene);
	mlx_hook((*scene)->win, 3, 1L << 1, key_release, *scene);
}
