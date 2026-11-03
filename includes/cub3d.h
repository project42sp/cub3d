/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-s <csilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 20:21:56 by csilva-s          #+#    #+#             */
/*   Updated: 2026/11/03 01:04:44 by csilva-s         ###   ########.fr       */
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

// KEYCODES
# define K_ESC 65307
# define K_W 119
# define K_D 100
# define K_S 115
# define K_A 97

// CONFIG VARS
# define HEIGHT 720
# define WIDTH 1280

// COLORS
# define RED 0x00FF0000
# define BLACK 0x00000000
# define GREY 0xD3D3D3
# define WHITE 0xFFFFFF
# define GREEN 0x39FF14

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

typedef struct s_coord
{
	double	x;
	double	y;
	int		dir_x;
	int		dir_y;
}	t_coord;

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_input
{
	int	w;
	int	s;
	int	d;
	int	a;
	int	esc;
}	t_input;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_scene
{
	t_color	floor;
	t_color	ceil;
	t_coord	player;
	char	**map;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	direction;
	void	*win;
	void	*mlx_instance;
	t_data	*image_obj;
	t_input	inputs;
	long	last_time_render;
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

t_scene		*parser(char *argv);
int			invalid_name(char *filename);

// Input Module Functions
void		key_handler(t_scene *scene);
int			key_press(int keycode, t_scene *scene);
int			key_release(int keycode, t_scene *scene);
int			key_action(t_scene *scene);
void		print_inputs(t_input inputs);

// Game Module Functions
int			exit_scene(t_scene *scene);
int			game_loop(t_scene *scene);
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
#endif
