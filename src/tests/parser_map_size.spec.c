#include "../../includes/cub3d.h"
#include <cmocka.h>

t_map_size	check_map_size(int fd);
int			get_file(char *filename);

static void	valid_file_normal_format(void **state)
{
	(void)state;

	char	*filename = "./maps/map.valid_reference_map.cub";
	int		fd	= get_file(filename);
	if (fd <= 0)
		return ;

	t_map_size	map_test = check_map_size(fd);
	t_map_size	map_check = {
		.line_start = 12,
		.map_size = 14,
		.control = 0,	// Value not needed after check
		.index = 0		// Value not needed after check
	};

	assert_int_equal(map_check.line_start, map_test.line_start);
	assert_int_equal(map_check.map_size, map_test.map_size);
}

static void	valid_file_with_initial_space(void **state)
{
	(void)state;

	char	*filename = "./maps/map.valid_with_space.cub";
	int		fd	= get_file(filename);
	if (fd <= 0)
		return ;

	t_map_size	map_test = check_map_size(fd);
	t_map_size	map_check = {
		.line_start = 12,
		.map_size = 14,
		.control = 0,	// Value not needed after check
		.index = 0		// Value not needed after check
	};

	assert_int_equal(map_check.line_start, map_test.line_start);
	assert_int_equal(map_check.map_size, map_test.map_size);
}

static void	invalid_file_no_map(void **state)
{
	(void)state;

	char	*filename = "./maps/map.invalid_no_map.cub";
	int		fd	= get_file(filename);
	if (fd <= 0)
		return ;

	t_map_size	map_test = check_map_size(fd);

	// If function fails to parse, return map_size = 0
	assert_false(map_test.map_size);
}

static void	invalid_file_double_map(void **state)
{
	(void)state;

	char	*filename = "./maps/map.invalid_double_map.cub";
	int		fd	= get_file(filename);
	if (fd <= 0)
		return ;

	t_map_size	map_test = check_map_size(fd);

	// If function fails to parse, return map_size = 0
	assert_false(map_test.map_size);
}

static void	invalid_file_line_in_map(void **state)
{
	(void)state;

	char	*filename = "./maps/map.invalid_line_in_map.cub";
	int		fd	= get_file(filename);
	if (fd <= 0)
		return ;

	t_map_size	map_test = check_map_size(fd);

	// If function fails to parse, return map_size = 0
	assert_false(map_test.map_size);
}

static void	invalid_file_content_after_map(void **state)
{
	(void)state;

	char	*filename = "./maps/map.invalid_content_after_map.cub";
	int		fd	= get_file(filename);
	if (fd <= 0)
		return ;

	t_map_size	map_test = check_map_size(fd);

	// If function fails to parse, return map_size = 0
	assert_false(map_test.map_size);
}

int	main(void)
{
	const struct CMUnitTest tests[] =
	{
		cmocka_unit_test(valid_file_normal_format),
		cmocka_unit_test(valid_file_with_initial_space),
		cmocka_unit_test(invalid_file_no_map),
		cmocka_unit_test(invalid_file_double_map),
		cmocka_unit_test(invalid_file_line_in_map),
		cmocka_unit_test(invalid_file_content_after_map),
	};
	return cmocka_run_group_tests(tests, NULL, NULL);
}
