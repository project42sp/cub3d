/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-s <csilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 20:21:56 by csilva-s          #+#    #+#             */
/*   Updated: 2026/11/09 18:46:53 by csilva-s         ###   ########.fr       */
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
# include <sys/time.h>
# include <math.h>

// KEYCODES
# define K_ESC 65307
# define K_W 119
# define K_D 100
# define K_S 115
# define K_A 97
# define K_ARROW_UP 65362
# define K_ARROW_DOWN 65364
# define K_ARROW_LEFT 65361
# define K_ARROW_RIGHT 65363

// CONFIG VARS
# define HEIGHT 720
# define WIDTH 1280

// COLORS
# define RED 0x00FF0000
# define BLACK 0x00000000
# define GREY 0xD3D3D3
# define WHITE 0xFFFFFF
# define GREEN 3800852

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
	int	hex;
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
	int	arrow_up;
	int	arrow_down;
	int	arrow_left;
	int	arrow_right;
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
t_camera	init_camera(void);

// ingest_file.c
char		**ingest_file(char *argv, t_map_size map_size);

// map_validation.c
int			invalid_map(char **data, t_map_size len);
t_camera	get_player_coord(char **map);

// flood_fill.c
int			invalid_wall_check(char **map, t_map_size len, t_camera cam);
char		**extract_map(char **data, t_map_size len);

// parser_utils.c
int			empty_line(char *line);
int			ignore_space(char *line, int index);
int			ismap(char *line);
int			get_file(char *filename);
t_scene		*init_map(void);
t_color		init_color(char *rgb);

// Input Module Functions
void		key_handler(t_scene *scene);
int			key_press(int keycode, t_scene *scene);
int			key_release(int keycode, t_scene *scene);
int			key_action(t_scene *scene, double dt);
void		print_inputs(t_input inputs);

// Game Module Functions
int			exit_scene(t_scene *scene);
int			game_loop(t_scene *scene);
long		get_time(void);
int			check_camera_char(char camera);
// Graphic Module Functions
void		graphic_config(t_scene **scene);
void		draw_pixel(t_data *image_obj, int x, int y, int color);
void		draw_direction_line(t_data *image_obj, t_pos pos, int color);
void		render_map(t_scene *scene);
void		draw_tile(t_data *image_obj, int y, int x, int color);
void		clear_frame(t_scene *scene);
void		render(t_scene *scene);
void		render_player(t_scene *scene);
void		render_direction(t_scene *scene);
void		bresengam(t_pos init_pos, t_pos end_pos,
				t_pos delta, t_scene *scene);
t_ray		dda(t_scene *scene, double dir_x, double dir_y);
t_ray		init_ray(t_scene *scene, double dir_x, double dir_y);
void		draw_wall(t_scene *scene, t_ray ray, int x);
void		render(t_scene *scene);
#endif
