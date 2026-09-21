#include "../../includes/cub3d.h"
#include <cmocka.h>

int	invalid_name(char *filename);

static void	valid_name_simple(void **state)
{
	(void)state;

	char	*filename = "map.cub";

	assert_false(invalid_name(filename));
}

static void	valid_name_complex(void **state)
{
	(void)state;

	char	*filename = "map.txt.cub";

	assert_false(invalid_name(filename));
}

static void	invalid_name_simple(void **state)
{
	(void)state;

	char	*filename = "map.txt";

	assert_true(invalid_name(filename));
}

static void	invalid_name_complex(void **state)
{
	(void)state;

	char	*filename = "map.txt.json";

	assert_true(invalid_name(filename));
}

static void	invalid_name_similar(void **state)
{
	(void)state;

	char	*filename = "map.cub3d";

	assert_true(invalid_name(filename));
}

static void	invalid_name_no_dot(void **state)
{
	(void)state;

	char	*filename = "map";

	assert_true(invalid_name(filename));
}

int	main(void)
{
	const struct CMUnitTest tests[] = {
		cmocka_unit_test(valid_name_simple),
		cmocka_unit_test(valid_name_complex),
		cmocka_unit_test(invalid_name_simple),
		cmocka_unit_test(invalid_name_complex),
		cmocka_unit_test(invalid_name_similar),
		cmocka_unit_test(invalid_name_no_dot)
	};
	return cmocka_run_group_tests(tests, NULL, NULL);
}
