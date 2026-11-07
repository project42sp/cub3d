#include "../../includes/cub3d.h"
#include <cmocka.h>

static void	valid_parameter_simple(void **state)
{
	(void)state;

	char	*filename = "./maps/map.valid_reference_map.cub";
	t_map_size	len_map = check_map_size(filename);
	char	**data = ingest_file(filename, len_map);

	assert_false(invalid_parameters(data, len_map));
	ft_split_free(data, len_map.control);
}

static void	valid_parameter_complex(void **state)
{
	(void)state;

	char	*filename = "./maps/map.valid_with_space.cub";
	t_map_size	len_map = check_map_size(filename);
	char	**data = ingest_file(filename, len_map);

	assert_false(invalid_parameters(data, len_map));
	ft_split_free(data, len_map.control);
}

static void	missing_parameter(void **state)
{
	(void)state;

	char	*filename = "./maps/map.invalid_missing_param.cub";
	t_map_size	len_map = check_map_size(filename);
	char	**data = ingest_file(filename, len_map);

	assert_true(invalid_parameters(data, len_map));
	ft_split_free(data, len_map.control);
}

static void	duplicated_parameter(void **state)
{
	(void)state;

	char	*filename = "./maps/map.invalid_duplicate_param.cub";
	t_map_size	len_map = check_map_size(filename);
	char	**data = ingest_file(filename, len_map);

	assert_true(invalid_parameters(data, len_map));
	ft_split_free(data, len_map.control);
}

static void	invalid_parameter_check(void **state)
{
	(void)state;

	char	*filename = "./maps/map.invalid_parameter.cub";
	t_map_size	len_map = check_map_size(filename);
	char	**data = ingest_file(filename, len_map);

	assert_true(invalid_parameters(data, len_map));
	ft_split_free(data, len_map.control);
}

int	main(void)
{
	const struct CMUnitTest tests[] = {
		cmocka_unit_test(valid_parameter_simple),
		cmocka_unit_test(valid_parameter_complex),
		cmocka_unit_test(missing_parameter),
		cmocka_unit_test(duplicated_parameter),
		cmocka_unit_test(invalid_parameter_check)
	};
	return cmocka_run_group_tests(tests, NULL, NULL);
}
