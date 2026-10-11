/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buehara <buehara@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 22:31:59 by buehara           #+#    #+#             */
/*   Updated: 2026/09/12 22:32:01 by buehara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	invalid_name(char *filename)
{
	int		index;
	char	**name_parts;
	int		err;

	err = SUCESS;
	name_parts = ft_split(filename, '.');
	if (!name_parts)
		err = FAILED;
	index = 0;
	while (name_parts[index + 1] != NULL)
		index++;
	if (ft_strncmp(name_parts[index], "cub", 4))
		err = FAILED;
	ft_split_free(name_parts, index);
	if (err)
		printf("%s\n", "Error: Unexpected file format.");
	else // TODO: Test else to see if validation worked. Clean Later.
		printf("%s\n", "Cub3D: File Accepted.");
	return (err);
}

int	get_file(char *filename)
{
	int	fd;

	if (!filename)
		return (FALSE);
	fd = 0;
	fd = open(filename, O_RDONLY);
	if (fd <= 0)
	{
		perror("Error");
		return (FALSE);
	}
	printf("Cub3D: File %s opened.\n", filename);
	return (fd);
}

int	empty_line(char *line)
{
	int	index;

	if (!line)
		return (TRUE);
	index = 0;
	while(ft_isspace(line[index]))
		index++;
	if (line[index] == '\n' || line[index] == '\0')
	{
		printf("%s\n", "Cub3D: Empty line.");
		return (TRUE);
	}
	return (FALSE);
}

t_scene	*init_map(void)
{
	t_scene	*map;

	map = ft_calloc(1, sizeof(t_scene));
	if (!map)
	{
		perror("Error");
		free(map);
		return (NULL);
	}
	return (map);
}

int	ismap(char *line)
{
	int	index;

	index = 0;
	while (ft_isspace(line[index]))
		index++;
	if (ft_isalnum(line[index]))
		return (TRUE);
	return (FALSE);
}

char	**parsing_map(char *line, int fd)
{
	int		map_size;
	int		index;
	char	**map;

	map_size = 1;
	index = 0;
	map = NULL;
	while (ismap(line))
	{
		map_size++;
		map = ft_calloc(map_size, sizeof(char *));
		if (!map_size)
		{
			ft_split_free(map, map_size);
			return (NULL);
		}
		map[index] = line;
		line = get_next_line(fd);
	}
	return (NULL);
}

t_scene	*parse_data(int	fd)
{
	int		parsed_map;
	char	*line;
	t_scene	*data;

	data = init_map();
	if (!data)
		return (NULL);
	printf("Cub3D: Start Parsing file...\n");
	parsed_map = FALSE;
	line =  get_next_line(fd);
	while(line)
	{
		if (!empty_line(line))
		{
			if (!parsed_map && ismap(line))
			{
				parsed_map = TRUE;
				//data->map = parsing_map(line, fd);
			}
		}
		free(line);
		line = get_next_line(fd);
	}
	return (NULL);
}

t_scene	*get_data(char *argv)
{
	int		fd;
	t_scene	*map;

	if (!argv)
		return (NULL);
	fd = get_file(argv);
	if (fd <= 0)
		return (NULL);
	map = parse_data(fd);
	if (!map)
		return (NULL);
	printf("Cub3D: Closing file.");
	close(fd);
	return (map);
}

int	ignore_space(char *line, int index)
{
	if (!line)
		return index;
	while (ft_isspace(line[index]))
		index++;
	return (index);
}

t_map_size init_map_size(void)
{
	t_map_size	len;

	len.index = 0;
	len.map_size = 0;
	len.control = 1;
	len.line_start = 1;
	return (len);
}

char	*count_map_size(t_map_size *len, int fd, char *line)
{
	len->index = ignore_space(line, len->index);
	if (!ft_isdigit(line[len->index]))
		return (NULL);
	len->map_size++;
	len->index = 0;
	len->control++;
	free(line);
	line = get_next_line(fd);
	return (line);
}

void	map_error(t_map_size len, char *line, int fd)
{
	printf("Error: Invalid Input File Map Format.\n");
	printf("Error line %d: %s", len.control, line);
	printf("Error character: %c\n", line[len.index]);
	free(line);
	close(fd);
}

t_map_size	check_map_size(int fd)
{
	char	*line;
	t_map_size	len;

	len = init_map_size();
	line = get_next_line(fd);
	while (line)
	{
		len.index = ignore_space(line, len.index);
		if (!len.map_size && ft_isdigit(line[len.index]))
		{
			while (line)
				line = count_map_size(&len, fd, line);
		}
		else if (len.map_size && ft_isdigit(line[len.index]))
		{
			map_error(len, line, fd);
			len.map_size = 0;
			return (len);
		}
		else
			len.line_start++;
		len.control++;
		free(line);
		len.index = 0;
		line = get_next_line(fd);
	}
	close(fd);
	return (len);
}

t_scene	*parser(char *argv)
{
	//t_scene	*map;
	t_map_size	len_map;
	int			fd;

	if (invalid_name(argv))
		return (NULL);
	fd = get_file(argv);
	if (fd <= 0)
		return (NULL);
	len_map = check_map_size(fd);
	if (!len_map.map_size)
	{
		printf("Cub3D: Error: Return to Main.");
		return (NULL);
	}
	//map = get_data(argv);
	//if (!map)
		//return (NULL);
	return (NULL);
}
