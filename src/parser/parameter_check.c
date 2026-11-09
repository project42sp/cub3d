/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parameter_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buehara <buehara@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 23:03:50 by buehara           #+#    #+#             */
/*   Updated: 2026/11/06 23:09:30 by buehara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static t_param	check_param(char *line, t_param check)
{
	if (!ft_strncmp("NO ", line, 3))
		check.no++;
	else if (!ft_strncmp("WE ", line, 3))
		check.we++;
	else if (!ft_strncmp("SO ", line, 3))
		check.so++;
	else if (!ft_strncmp("EA ", line, 3))
		check.ea++;
	else if (!ft_strncmp("F ", line, 2))
		check.floor++;
	else if (!ft_strncmp("C ", line, 2))
		check.ceil++;
	else
	{
		printf("Cud3D: Unexpected parameter: %s", line);
		check.ctrl++;
	}
	return (check);
}

static t_param	init_check_param(void)
{
	t_param	check;

	check.ctrl = 0;
	check.index = 0;
	check.no = 0;
	check.so = 0;
	check.ea = 0;
	check.we = 0;
	check.floor = 0;
	check.ceil = 0;
	return (check);
}

static t_param	fill_param_check(char **data, t_map_size len)
{
	int		idx;
	t_param	check;

	(void)len;
	check = init_check_param();
	idx = 0;
	while (data && data[check.index])
	{
		while (ft_isspace(data[check.index][idx]))
			idx++;
		if (ft_isalpha(data[check.index][idx]))
			check = check_param(&data[check.index][idx], check);
		check.index++;
		idx = 0;
	}
	return (check);
}

int	invalid_parameters(char **data, t_map_size len)
{
	t_param	check;

	check = fill_param_check(data, len);
	if (check.ctrl)
	{
		printf("Cub3D: Error: Unexpected Parameter Found.\n");
		return (FAILED);
	}
	if (check.no > 1 || check.ea > 1 || check.so > 1 || check.we > 1
		|| check.floor > 1 || check.ceil > 1)
	{
		printf("Cub3D: Error: Duplicate Parameter Found.\n");
		return (FAILED);
	}
	if (!check.no || !check.ea || !check.so || !check.we
		|| !check.floor || !check.ceil)
	{
		printf("Cub3D: Error: Missing obligatory parameter on file.\n");
		return (FAILED);
	}
	return (SUCESS);
}
