#include "../../includes/cub3d.h"
#include <cmocka.h>

static void	valid_parameter_simple(void **state)
{
	(void)state;

	char		*filename = "./maps/map.valid_reference_map.cub";
	t_map_size	len_map = check_map_size(filename);
	char		**data = ingest_file(filename, len_map);
	char		**map = extract_map(data, len_map);
	t_camera	cam = get_player_coord(map);

	// Reference map player is set to north
	assert_ptr_equal(data[6], map[0]);
	assert_double_equal(cam.pos_x, 26.0, 0.1);
	assert_double_equal(cam.pos_y, 11.0, 0.1);
	assert_double_equal(cam.dir_x, 0, 0.1);
	assert_double_equal(cam.dir_y, -1.0, 0.1);
	ft_split_free(data, len_map.control);
}

static void	valid_parameter_with_space(void **state)
{
	(void)state;

	char		*filename = "./maps/map.valid_with_space.cub";
	t_map_size	len_map = check_map_size(filename);
	char		**data = ingest_file(filename, len_map);
	char		**map = extract_map(data, len_map);
	t_camera	cam = get_player_coord(map);

	// Reference map player is set to north
	assert_ptr_equal(data[6], map[0]);
	assert_double_equal(cam.pos_x, 26.0, 0.1);
	assert_double_equal(cam.pos_y, 11.0, 0.1);
	assert_double_equal(cam.dir_x, 0, 0.1);
	assert_double_equal(cam.dir_y, -1.0, 0.1);
	ft_split_free(data, len_map.control);
}

static void	invalid_random_character(void **state)
{
	(void)state;

	char		*filename = "./maps/map.invalid_random_character.cub";
	t_map_size	len_map = check_map_size(filename);
	char		**data = ingest_file(filename, len_map);
	char		**map = extract_map(data, len_map);
	t_camera	cam = get_player_coord(map);

	assert_ptr_equal(data[6], map[0]);
	assert_double_equal(cam.pos_x, 0.0, 0.1);
	assert_double_equal(cam.pos_y, 0.0, 0.1);
	ft_split_free(data, len_map.control);
}

static void	invalid_random_character_lowercase(void **state)
{
	(void)state;

	char		*filename = "./maps/map.invalid_random_character_lowercase.cub";
	t_map_size	len_map = check_map_size(filename);
	char		**data = ingest_file(filename, len_map);
	char		**map = extract_map(data, len_map);
	t_camera	cam = get_player_coord(map);

	assert_ptr_equal(data[6], map[0]);
	assert_double_equal(cam.pos_x, 0.0, 0.1);
	assert_double_equal(cam.pos_y, 0.0, 0.1);
	ft_split_free(data, len_map.control);
}

static void	valid_parameter_south_player_variant(void **state)
{
	(void)state;

	char		*filename = "./maps/map.valid_player_south.cub";
	t_map_size	len_map = check_map_size(filename);
	char		**data = ingest_file(filename, len_map);
	char		**map = extract_map(data, len_map);
	t_camera	cam = get_player_coord(map);

	assert_ptr_equal(data[6], map[0]);
	assert_double_equal(cam.pos_x, 25.0, 0.1);
	assert_double_equal(cam.pos_y, 2.0, 0.1);
	assert_double_equal(cam.dir_x, 0, 0.1);
	assert_double_equal(cam.dir_y, 1.0, 0.1);
	ft_split_free(data, len_map.control);
}

static void	valid_parameter_east_player_variant(void **state)
{
	(void)state;

	char		*filename = "./maps/map.valid_player_east.cub";
	t_map_size	len_map = check_map_size(filename);
	char		**data = ingest_file(filename, len_map);
	char		**map = extract_map(data, len_map);
	t_camera	cam = get_player_coord(map);

	assert_ptr_equal(data[6], map[0]);
	assert_double_equal(cam.pos_x, 15.0, 0.1);
	assert_double_equal(cam.pos_y, 4.0, 0.1);
	assert_double_equal(cam.dir_x, 1.0, 0.1);
	assert_double_equal(cam.dir_y, 0, 0.1);
	ft_split_free(data, len_map.control);
}

static void	invalid_parameter_west_lowercase_player_variant(void **state)
{
	(void)state;

	char		*filename = "./maps/map.invalid_player_west_lowercase.cub";
	t_map_size	len_map = check_map_size(filename);
	char		**data = ingest_file(filename, len_map);
	char		**map = extract_map(data, len_map);
	t_camera	cam = get_player_coord(map);

	assert_ptr_equal(data[6], map[0]);
	assert_double_equal(cam.pos_x, 0.0, 0.1);
	assert_double_equal(cam.pos_y, 0.0, 0.1);
	ft_split_free(data, len_map.control);
}
static void	valid_parameter_west_player_variant(void **state)
{
	(void)state;

	char		*filename = "./maps/map.valid_player_west.cub";
	t_map_size	len_map = check_map_size(filename);
	char		**data = ingest_file(filename, len_map);
	char		**map = extract_map(data, len_map);
	t_camera	cam = get_player_coord(map);

	assert_ptr_equal(data[6], map[0]);
	assert_double_equal(cam.pos_x, 3.0, 0.1);
	assert_double_equal(cam.pos_y, 10.0, 0.1);
	assert_double_equal(cam.dir_x, -1.0, 0.1);
	assert_double_equal(cam.dir_y, 0, 0.1);
	ft_split_free(data, len_map.control);
}

static void	invalid_player_character(void **state)
{
	(void)state;

	char		*filename = "./maps/map.invalid_player.cub";
	t_map_size	len_map = check_map_size(filename);
	char		**data = ingest_file(filename, len_map);
	char		**map = extract_map(data, len_map);
	t_camera	cam = get_player_coord(map);

	assert_ptr_equal(data[6], map[0]);
	assert_double_equal(cam.pos_x, 0.0, 0.1);
	assert_double_equal(cam.pos_y, 0.0, 0.1);
	ft_split_free(data, len_map.control);
}

static void	invalid_double_player(void **state)
{
	(void)state;

	char		*filename = "./maps/map.invalid_double_player.cub";
	t_map_size	len_map = check_map_size(filename);
	char		**data = ingest_file(filename, len_map);
	char		**map = extract_map(data, len_map);
	t_camera	cam = get_player_coord(map);

	assert_ptr_equal(data[6], map[0]);
	assert_double_equal(cam.pos_x, 0.0, 0.1);
	assert_double_equal(cam.pos_y, 0.0, 0.1);
	ft_split_free(data, len_map.control);
}

static void	invalid_no_player(void **state)
{
	(void)state;

	char		*filename = "./maps/map.invalid_no_player.cub";
	t_map_size	len_map = check_map_size(filename);
	char		**data = ingest_file(filename, len_map);
	char		**map = extract_map(data, len_map);
	t_camera	cam = get_player_coord(map);

	assert_ptr_equal(data[6], map[0]);
	assert_double_equal(cam.pos_x, 0.0, 0.1);
	assert_double_equal(cam.pos_y, 0.0, 0.1);
	ft_split_free(data, len_map.control);
}

int	main(void)
{
	const struct CMUnitTest tests[] = {
		cmocka_unit_test(valid_parameter_simple),
		cmocka_unit_test(valid_parameter_east_player_variant),
		cmocka_unit_test(valid_parameter_south_player_variant),
		cmocka_unit_test(valid_parameter_west_player_variant),
		cmocka_unit_test(invalid_parameter_west_lowercase_player_variant),
		cmocka_unit_test(invalid_random_character),
		cmocka_unit_test(invalid_random_character_lowercase),
		cmocka_unit_test(valid_parameter_with_space),
		cmocka_unit_test(invalid_player_character),
		cmocka_unit_test(invalid_double_player),
		cmocka_unit_test(invalid_no_player)
	};
	return cmocka_run_group_tests(tests, NULL, NULL);
}
