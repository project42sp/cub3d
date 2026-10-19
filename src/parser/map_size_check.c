/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map_size_check.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buehara <buehara@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 01:22:19 by buehara           #+#    #+#             */
/*   Updated: 2026/10/12 01:22:21 by buehara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_map_size	init_map_size(void)
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
	while (line)
	{
		len->index = ignore_space(line, len->index);
		if (!ft_isdigit(line[len->index]))
			break ;
		len->map_size++;
		len->index = 0;
		len->control++;
		free(line);
		line = get_next_line(fd);
	}
	return (line);
}

t_map_size	check_map_util(char *line, int fd, t_map_size len)
{
	while (line)
	{
		len.index = ignore_space(line, len.index);
		if (!len.map_size && ft_isdigit(line[len.index]))
			line = count_map_size(&len, fd, line);
		else if (len.map_size && ft_isalnum(line[len.index]))
		{
			printf("Error: Invalid Input File Map Format.\n");
			printf("Error line %d: %s", len.control, line);
			printf("Error character: %c\n", line[len.index]);
			free(line);
			len.map_size = 0;
			return (len);
		}
		else
			len.line_start++;
		free(line);
		len.control++;
		len.index = 0;
		line = get_next_line(fd);
	}
	return (len);
}

t_map_size	check_map_size(char *argv)
{
	char		*line;
	t_map_size	len;
	int			fd;

	len = init_map_size();
	fd = get_file(argv);
	if (fd <= 0)
		return (len);
	line = get_next_line(fd);
	len = check_map_util(line, fd, len);
	if (!len.map_size)
		printf("Error: File Content Format.\n");
	close(fd);
	return (len);
}
