/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-s <csilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 20:21:56 by csilva-s          #+#    #+#             */
/*   Updated: 2026/08/18 00:31:52 by csilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdarg.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdint.h>
# include <setjmp.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
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

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_scene
{
	char	**map;
	t_color	floor;
	t_color	ceil;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		coord[2];
	char	direction;
}	t_scene;

t_scene	*parser(char *argv);
#endif
