/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_register.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-s <csilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 20:06:39 by csilva-s          #+#    #+#             */
/*   Updated: 2026/10/04 22:59:41 by csilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

//ISSUE: Debug function
static	void	print_inputs(t_input *inputs)
{
	ft_printf("\nInputs:\n");
	ft_printf("\nW: %d", inputs->w);
	ft_printf("\nS: %d", inputs->s);
	ft_printf("\nA: %d", inputs->a);
	ft_printf("\nD: %d", inputs->d);
	ft_printf("\nESC: %d", inputs->esc);
}

int	key_release(int keycode, t_scene *scene)
{
	if (keycode == K_W && scene->inputs->w)
		scene->inputs->w = 0;
	else if (keycode == K_S && scene->inputs->s)
		scene->inputs->s = 0;
	else if (keycode == K_D && scene->inputs->d)
		scene->inputs->d = 0;
	else if (keycode == K_A && scene->inputs->a)
		scene->inputs->a = 0;
	else if (keycode == K_ESC && scene->inputs->esc)
		scene->inputs->esc = 0;
	return (keycode);
}

int	key_press(int keycode, t_scene *scene)
{
	if (keycode == K_W && !scene->inputs->w)
		scene->inputs->w = 1;
	else if (keycode == K_S && !scene->inputs->s)
		scene->inputs->s = 1;
	else if (keycode == K_D && !scene->inputs->d)
		scene->inputs->d = 1;
	else if (keycode == K_A && !scene->inputs->a)
		scene->inputs->a = 1;
	else if (keycode == K_ESC && !scene->inputs->esc)
		scene->inputs->esc = 1;
	return (keycode);
}
