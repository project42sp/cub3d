
#include "../../includes/cub3d.h"

t_param_check	check_param(char *line, t_param_check check)
{
	if (!ft_strncmp("NO ", &line[check.index], 3))
		check.no++;
	else if (!ft_strncmp("WE ", &line[check.index], 3))
		check.we++;
	else if (!ft_strncmp("SO ", &line[check.index], 3))
		check.so++;
	else if (!ft_strncmp("EA ", &line[check.index], 3))
		check.ea++;
	else if (!ft_strncmp("F ", &line[check.index], 2))
		check.floor++;
	else if (!ft_strncmp("C ", &line[check.index], 2))
		check.ceil++;
	else
		check.ctrl++;
	return (check);
}

t_param_check	init_check_param(void)
{
	t_param_check	check;

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

t_param_check	fill_param_check(int fd)
{
	char	*line;
	t_param_check	check;

	check = init_check_param();
	line = get_next_line(fd);
	while (line)
	{
		check.index = ignore_space(line, check.index);
		if (ft_isalpha(line[check.index]))
			check = check_param(line, check);
		free(line);
		check.index = 0;
		line = get_next_line(fd);
	}
	close(fd);
	return check;
}

int	invalid_parameters(char *argv)
{
	int				fd;
	t_param_check	check;

	fd = get_file(argv);
	if (fd <= 0)
		return (FAILED);
	check = fill_param_check(fd);
	if (check.ctrl)
	{
		printf("Cub3D: Error: Unexpected Parameter Found.\n");
		return (FAILED);
	}
	if (check.no > 1 || check.ea > 1 || check.so > 1 || check.we > 1
		|| check.floor > 1 || check.ceil > 1)
	{
		printf("Cub3D: Error: Duplicate Parameter Found.\n");
		return (FAILED);}
	if (!check.no || !check.ea || !check.so || !check.we
		|| !check.floor || !check.ceil)
	{
		printf("Cub3D: Error: Missing obligatory parameter on file.\n");
		return (FAILED);
	}
	return (SUCESS);
}
