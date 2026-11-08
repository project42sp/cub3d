/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.spec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-s <csilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 16:47:03 by csilva-s          #+#    #+#             */
/*   Updated: 2026/11/08 19:11:44 by csilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include <cmocka.h>

static void	mock_initializer(t_scene **scene)
{
	  const char *map =
        "1111111111111111\n"
        "1000001000000001\n"
        "1000000100000001\n"
        "1000000010000001\n"
        "1000L00001000001\n"
        "1000000000100001\n"
        "1000000000010001\n"
        "1000000000001001\n"
        "1000000000000101\n"
        "1000000000000001\n"
        "1000000000000001\n"
        "1111111111111111";
	(*scene)->map = ft_split(map, '\n');
    (*scene)->camera.pos_x = 4.5;
    (*scene)->camera.pos_y = 4.5;
    (*scene)->camera.dir_x = 1.0;
    (*scene)->camera.dir_y = 0.0;
    (*scene)->camera.plane_x = 0.0;
    (*scene)->camera.plane_y = 0.66;
}

// Calculate de perpendicular distance of ray (4 pos to right L(player) -> 1(wall))
static void check_ray_distance(void **state)
{
	t_scene *scene;

	(void)state;
	scene = ft_calloc(1, sizeof(t_scene));
	int center_screen = WIDTH / 2;
	mock_initializer(&scene);
	double camera_x = 2.0 * center_screen / (double)WIDTH - 1.0;
	double ray_dir_x = scene->camera.dir_x + scene->camera.plane_x * camera_x;
	double ray_dir_y = scene->camera.dir_y + scene->camera.plane_y * camera_x;
	t_ray ray = dda(scene, ray_dir_x, ray_dir_y);
	assert_int_equal((int)ray.perp_dist, 4);
}

int	main(void)
{
	const struct CMUnitTest	tests[] = {
		cmocka_unit_test(check_ray_distance),
	};
	return (cmocka_run_group_tests(tests, NULL, NULL));
}
