/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   content_validation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buehara <buehara@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 00:22:50 by buehara           #+#    #+#             */
/*   Updated: 2026/10/25 21:58:41 by buehara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	invalid_rgb(char *rgb)
{
	char	**colors;
	int		len;

	colors = ft_split(rgb, ',');
	if (!colors)
		return (FAILED);
	len = 0;
	while (colors[len])
	{
		if (ft_atoi(colors[len]) < 0 || ft_atoi(colors[len]) > 255)
		{
			printf("Error: Color outside of allowed range (0,255)\n");
			ft_split_free(colors, len);
			return (FAILED);
		}
		len++;
	}
	if (len > 3)
	{
		printf("Error: Found more than 3 values for RGB.\n");
		ft_split_free(colors, len);
		return (FAILED);
	}
	ft_split_free(colors, len);
	return (SUCESS);
}

int	invalid_param_content(char **split)
{
	int		temp_fd;
	char	*new_line;

	temp_fd = 0;
	if (!ft_strncmp(split[0], "NO", 3) || !ft_strncmp(split[0], "SO", 3)
		|| !ft_strncmp(split[0], "EA", 3) || !ft_strncmp(split[0], "WE", 3))
	{
		new_line = ft_strrchr(split[1], '\n');
		if (new_line)
			new_line[0] = '\0';
		if (invalid_name(split[1], "xpm"))
			return (FAILED);
		temp_fd = get_file(split[1]);
		if (temp_fd <= 0)
		{
			printf("Cub3D: Failed to open '%s' texture file.\n", split[0]);
			return (FAILED);
		}
		close(temp_fd);
	}
	else if (!ft_strncmp(split[0], "F", 2) || !ft_strncmp(split[0], "C", 2))
	{
		if (invalid_rgb(split[1]))
			return (FAILED);
	}
	return (SUCESS);
}

int	line_check_invalid(char **split)
{
	int		len;
	int		err;

	len = 0;
	err = SUCESS;
	while (split[len])
		len++;
	if (len == 1)
	{
		printf("Error: Empty parameter value for '%s'.\n", split[0]);
		err = FAILED;
	}
	else if (len > 2)
	{
		printf("Error: Unexpected parameter quantity.\n");
		err = FAILED;
	}
	else if (invalid_param_content(split))
		err = FAILED;
	ft_split_free(split, len);
	return (err);
}

int	invalid_content(char *argv)
{
	int		fd;
	char	*line;
	char	**split;

	fd = get_file(argv);
	if (fd <= 0)
		return (FAILED);
	line = get_next_line(fd);
	while (line)
	{
		if (ismap(line))
		{
			free(line);
			break ;
		}
		if (!empty_line(line))
		{
			split = ft_split(line, ' ');
			if (!split)
			{
				free(line);
				perror("Error: ");
				return (FAILED);
			}
			if (line_check_invalid(split))
				return (FAILED);
		}
		free(line);
		line = get_next_line(fd);
	}
	printf("Cub3d: Finish parameter check.\n");
	return (SUCESS);
}
