/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-s <csilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 20:21:56 by csilva-s          #+#    #+#             */
/*   Updated: 2026/10/04 22:55:01 by csilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

// CMOCKA LIBS
# include <stdarg.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdint.h>
# include <setjmp.h>

// INTERNAL LIBS
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../minilibx/mlx.h"
# include "libft/includes/libft.h"

// KEYCODES
# define K_ESC 65307
# define K_W 119
# define K_D 100
# define K_S 115
# define K_A 97

// Parser MAP structs
enum e_colortype
{
	FLOOR,
	CEIL,
	NO,
	SO,
	WE,
	EA
};

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_coord
{
	int	x;
	int	y;
	int	z;
}	t_coord;

typedef struct s_input
{
	int	w;
	int	s;
	int	d;
	int	a;
	int	esc;
}	t_input;

typedef struct s_scene
{
	char	**map;
	t_color	floor;
	t_color	ceil;
	t_coord	player;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	direction;
	void	*win;
	void	*mlx_instance;
	t_input	*inputs;
}	t_scene;

// Parser functions
t_scene	*parser(char *argv);
int		invalid_name(char *filename);
// Input Module functions
void	key_handler(t_scene **scene);
int		key_press(int keycode, t_scene *scene);
int		key_release(int keycode, t_scene *scene);
#endif
