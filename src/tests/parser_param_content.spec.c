#include "../../includes/cub3d.h"
#include <cmocka.h>

static void	valid_parameter_simple(void **state)
{
	(void)state;

	char	*filename = "./maps/map.valid_reference_map.cub";

	assert_false(invalid_content(filename));
}

static void	invalid_texture_path(void **state)
{
	(void)state;

	char	*filename = "./maps/map.invalid_texture_path.cub";

	assert_true(invalid_content(filename));
}

static void	invalid_texture_format(void **state)
{
	(void)state;

	char	*filename = "./maps/map.invalid_texture_format.cub";

	assert_true(invalid_content(filename));
}

static void	invalid_color_format(void **state)
{
	(void)state;

	char	*filename = "./maps/map.invalid_color_format.cub";

	assert_true(invalid_content(filename));
}

static void	invalid_color_range(void **state)
{
	(void)state;

	char	*filename = "./maps/map.invalid_color_range.cub";

	assert_true(invalid_content(filename));
}

static void	invalid_color_range_negative(void **state)
{
	(void)state;

	char	*filename = "./maps/map.invalid_color_range_negative.cub";

	assert_true(invalid_content(filename));
}

static void	invalid_color_paramn_amount_over(void **state)
{
	(void)state;

	char	*filename = "./maps/map.invalid_color_paramn_amount_over.cub";

	assert_true(invalid_content(filename));
}

static void	invalid_color_paramn_amount_fewer(void **state)
{
	(void)state;

	char	*filename = "./maps/map.invalid_color_paramn_amount_fewer.cub";

	assert_true(invalid_content(filename));
}

int	main(void)
{
	const struct CMUnitTest tests[] = {
		cmocka_unit_test(valid_parameter_simple),
		cmocka_unit_test(invalid_texture_path),
		cmocka_unit_test(invalid_texture_format),
		cmocka_unit_test(invalid_color_format),
		cmocka_unit_test(invalid_color_range),
		cmocka_unit_test(invalid_color_range_negative),
		cmocka_unit_test(invalid_color_paramn_amount_over),
		cmocka_unit_test(invalid_color_paramn_amount_fewer)
	};
	return cmocka_run_group_tests(tests, NULL, NULL);
}
