/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-s <csilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 20:21:56 by csilva-s          #+#    #+#             */
/*   Updated: 2026/11/08 02:06:37 by buehara          ###   ########.fr       */
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

typedef struct s_map_size
{
	int	line_start;
	int	map_size;
	int	control;
	int	index;
}	t_map_size;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_camera
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}	t_camera;

typedef struct s_pos
{
	double	x;
	double	y;
}	t_pos;

typedef struct s_input
{
	int	w;
	int	s;
	int	d;
	int	a;
	int	esc;
}	t_input;

typedef struct s_parameter_check
{
	int	no;
	int	so;
	int	we;
	int	ea;
	int	floor;
	int	ceil;
	int	index;
	int	ctrl;
}	t_param;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_ray
{
	t_pos	dir;
	t_pos	delta_dist;
	t_pos	side_dist;
	double	perp_dist;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		side;
	int		hit;
}	t_ray;

typedef struct s_scene
{
	t_color		floor;
	t_color		ceil;
	t_camera	camera;
	char		**map;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	void		*win;
	void		*mlx_instance;
	t_data		*image_obj;
	t_input		inputs;
	long		last_time_render;
}	t_scene;

// Parser functions
// parser.c
t_scene		*parser(char *argv);

// parser_invalid_name.c
int			invalid_name(char *filename, char *file_format);

// parser_map_size_check.c
t_map_size	check_map_size(char *argv);

// parameter_check.c
int			invalid_parameters(char **data, t_map_size len);

// content_validation.c
int			invalid_content(char **data, t_map_size len);

// map_validation.c
int			invalid_map(char **data, t_map_size len);

// ingest_file.c
char		**ingest_file(char *argv, t_map_size map_size);

// map_validation.c 
int			invalid_map(char **data, t_map_size len);
t_camera	get_player_coord(char **map);
char		**extract_map(char **map, t_map_size len);

// parser_utils.c
int			empty_line(char *line);
int			ignore_space(char *line, int index);
int			ismap(char *line);
int			get_file(char *filename);
t_scene		*init_map(void);

// Input Module Functions
void		key_handler(t_scene *scene);
int			key_press(int keycode, t_scene *scene);
int			key_release(int keycode, t_scene *scene);
int			key_action(t_scene *scene);
void		print_inputs(t_input inputs);

// Game Module Functions
int			exit_scene(t_scene *scene);

// Graphic Module Functions
void		graphic_config(t_scene **scene);
void		draw_pixel(t_data *image_obj, int x, int y, int color);
#endif
