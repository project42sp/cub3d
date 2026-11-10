/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buehara <buehara@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 22:31:59 by buehara           #+#    #+#             */
/*   Updated: 2026/11/09 18:46:27 by csilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	extract_parameter(char *line, t_scene *scene)
{
	int		idx;
	char	**split;

	split = ft_split(line, ' ');
	if (!split)
		return (FAILED);
	if (!ft_strncmp("NO", split[0], 3) && split[1])
		scene->no = ft_strdup(split[1]);
	else if (!ft_strncmp("WE", split[0], 3) && split[1])
		scene->we = ft_strdup(split[1]);
	else if (!ft_strncmp("EA", split[0], 3) && split[1])
		scene->ea = ft_strdup(split[1]);
	else if (!ft_strncmp("SO", split[0], 3) && split[1])
		scene->so = ft_strdup(split[1]);
	else if (!ft_strncmp("F", split[0], 2) && split[1])
		scene->floor = init_color(split[1]);
	else if (!ft_strncmp("C", split[0], 2) && split[1])
		scene->ceil = init_color(split[1]);
	idx = 0;
	while (split[idx])
		idx++;
	ft_split_free(split, idx);
	return (SUCESS);
}

int	extract_parameter_loop(char **data, t_scene *scene)
{
	int		len;
	char	*line;

	len = 0;
	while (len <= 6)
	{
		line = ft_strchr(data[len], '\n');
		*line = '\0';
		if (extract_parameter(data[len], scene))
		{
			printf("Error: Failed to extract parameter. Data %s\n", data[len]);
			if (scene->ea)
				free(scene->ea);
			if (scene->we)
				free(scene->we);
			if (scene->so)
				free(scene->so);
			if (scene->no)
				free(scene->no);
			free(scene);
			return (FALSE);
		}
		len++;
	}
	return (TRUE);
}

t_scene	*init_scene(char **data, t_map_size len)
{
	t_scene		*scene;
	t_camera	cam;
	char		**map;

	map = extract_map(data, len);
	if (!map)
		return (NULL);
	cam = init_camera();
	cam = get_player_coord(map);
	scene = ft_calloc(sizeof(t_scene), 1);
	if (!scene)
	{
		ft_split_free(map, len.map_size);
		return (NULL);
	}
	scene->map = map;
	scene->camera = cam;
	if (extract_parameter_loop(data, scene) == FALSE)
	{
		free(scene);
		return (NULL);
	}
	return (scene);
}

static char	**data_check(char *argv, t_map_size len_map)
{
	char		**data;

	data = ingest_file(argv, len_map);
	if (!data)
		return (NULL);
	if (invalid_parameters(data, len_map))
	{
		ft_split_free(data, len_map.control);
		return (NULL);
	}
	printf("Cub3D: Parameters Accepted.\n");
	if (invalid_content(data, len_map))
	{
		ft_split_free(data, len_map.map_size + 6);
		return (NULL);
	}
	if (invalid_map(data, len_map))
	{
		ft_split_free(data, len_map.map_size + 6);
		return (NULL);
	}
	printf("Cub3D: Parameter Values Accepted.\n");
	return (data);
}

t_scene	*parser(char *argv)
{
	char		**data;
	t_scene		*scene;
	t_map_size	len_map;

	if (invalid_name(argv, "cub"))
		return (NULL);
	len_map = check_map_size(argv);
	if (!len_map.map_size)
		return (NULL);
	data = data_check(argv, len_map);
	if (!data)
		return (NULL);
	scene = init_scene(data, len_map);
	if (!scene)
	{
		printf("Cub3D: scene was not created.\n");
		ft_split_free(data, len_map.map_size + 6);
		return (NULL);
	}
	printf("Cub3D: scene created.");
	ft_split_free(data, len_map.map_size + 6);
	return (scene);
}
