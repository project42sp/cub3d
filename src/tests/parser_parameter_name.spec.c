#include "../../includes/cub3d.h"
#include <cmocka.h>

static void	valid_parameter_simple(void **state)
{
	(void)state;

	char	*filename = "./maps/map.valid_reference_map.cub";

	assert_false(invalid_parameters(filename));
}

static void	valid_parameter_complex(void **state)
{
	(void)state;

	char	*filename = "./maps/map.valid_with_space.cub";

	assert_false(invalid_parameters(filename));
}

static void	inexisting_file(void **state)
{
	(void)state;

	char	*filename = "map.cub";

	assert_true(invalid_parameters(filename));
}

static void	missing_parameter(void **state)
{
	(void)state;

	char	*filename = "./maps/map.invalid_missing_param.cub";

	assert_true(invalid_parameters(filename));
}

static void	duplicated_parameter(void **state)
{
	(void)state;

	char	*filename = "./maps/map.invalid_duplicate_param.cub";

	assert_true(invalid_parameters(filename));
}

static void	invalid_parameter_check(void **state)
{
	(void)state;

	char	*filename = "./maps/map.invalid_parameter.cub";

	assert_true(invalid_parameters(filename));
}

int	main(void)
{
	const struct CMUnitTest tests[] = {
		cmocka_unit_test(valid_parameter_simple),
		cmocka_unit_test(valid_parameter_complex),
		cmocka_unit_test(inexisting_file),
		cmocka_unit_test(missing_parameter),
		cmocka_unit_test(duplicated_parameter),
		cmocka_unit_test(invalid_parameter_check)
	};
	return cmocka_run_group_tests(tests, NULL, NULL);
}
