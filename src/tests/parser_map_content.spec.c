#include "../../includes/cub3d.h"
#include <cmocka.h>

static void	valid_reference_map(void **state)
{
	(void)state;

	char	*filename = "./maps/map.valid_reference_map.cub";
	t_map_size	len = check_map_size(filename);
	char	**data = ingest_file(filename, len);

	assert_false(invalid_map(data, len));
}

static void	valid_space_map(void **state)
{
	(void)state;

	char	*filename = "./maps/map.valid_with_space.cub";
	t_map_size	len = check_map_size(filename);
	char	**data = ingest_file(filename, len);

	assert_false(invalid_map(data, len));
}

static void	valid_map_open_diogonal(void **state)
{
	(void)state;

	char	*filename = "./maps/map.valid_map_open_diogonal.cub";
	t_map_size	len = check_map_size(filename);
	char	**data = ingest_file(filename, len);

	assert_false(invalid_map(data, len));
}

static void	invalid_map_open(void **state)
{
	(void)state;

	char	*filename = "./maps/map.invalid_map_open.cub";
	t_map_size	len = check_map_size(filename);
	char	**data = ingest_file(filename, len);

	assert_true(invalid_map(data, len));
}

static void	invalid_player_out_of_map(void **state)
{
	(void)state;

	char		*filename = "./maps/map.player_out_of_map.cub";
	t_map_size	len_map = check_map_size(filename);

	char	**data = ingest_file(filename, len_map);

	assert_true(invalid_map(data, len_map));
}


int	main(void)
{
	const struct CMUnitTest tests[] = {
		cmocka_unit_test(valid_reference_map),
		cmocka_unit_test(valid_space_map),
		cmocka_unit_test(valid_map_open_diogonal),
		cmocka_unit_test(invalid_map_open),
		cmocka_unit_test(invalid_player_out_of_map)
	};
	return cmocka_run_group_tests(tests, NULL, NULL);
}
