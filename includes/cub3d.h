/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-s <csilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 20:21:56 by csilva-s          #+#    #+#             */
/*   Updated: 2026/09/27 16:05:28 by csilva-s         ###   ########.fr       */
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
# include <errno.h>
# include <fcntl.h>
# include "../minilibx/mlx.h"
# include "libft/includes/libft.h"

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

typedef struct s_map_size
{
	int	line_start;
	int	map_size;
	int	control;
	int	index;
} t_map_size;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_coord
{
	double	x;
	double	y;
	double	z;
}	t_coord;

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
}	t_scene;

// Parser functions
// parser.c
t_scene		*parser(char *argv);

// parser_invalid_name.c
int			invalid_name(char *filename);

// parser_map_size_check.c
t_map_size	check_map_size(int fd);
void		map_error(t_map_size len, char *line, int fd);
char		*count_map_size(t_map_size *len, int fd, char *line);
t_map_size	init_map_size(void);

// parser_utils.c
int			empty_line(char *line);
int			ignore_space(char *line, int index);
int			ismap(char *line);
int			get_file(char *filename);
t_scene		*init_map(void);

#endif
