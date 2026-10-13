/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_module.spec.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-s <csilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 17:42:56 by csilva-s          #+#    #+#             */
/*   Updated: 2026/10/12 19:25:11 by csilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include <cmocka.h>

static void	key_press_test(void **state)
{
	t_scene	*scene;

	(void)state;
	scene = ft_calloc(1, sizeof(t_scene));
	key_press(K_A, scene);
	assert_int_equal(scene->inputs.a, 1);
	assert_int_equal(scene->inputs.d, 0);
	assert_int_equal(scene->inputs.s, 0);
	assert_int_equal(scene->inputs.w, 0);
	assert_int_equal(scene->inputs.esc, 0);
}

static void	key_release_test(void **state)
{
	t_scene	*scene;

	(void)state;
	scene = ft_calloc(1, sizeof(t_scene));
	key_press(K_A, scene);
	assert_int_equal(scene->inputs.a, 1);
	key_release(K_A, scene);
	assert_int_equal(scene->inputs.a, 0);
	assert_int_equal(scene->inputs.a, 0);
	assert_int_equal(scene->inputs.a, 0);
	assert_int_equal(scene->inputs.a, 0);
}

static void	multi_key_press_test(void **state)
{
	t_scene	*scene;

	(void)state;
	scene = ft_calloc(1, sizeof(t_scene));
	key_press(K_W, scene);
	key_press(K_S, scene);
	assert_int_equal(scene->inputs.w, 1);
	assert_int_equal(scene->inputs.s, 1);
	assert_int_equal(scene->inputs.a, 0);
	assert_int_equal(scene->inputs.d, 0);
	assert_int_equal(scene->inputs.esc, 0);
}

static void	multi_key_release_test(void **state)
{
	t_scene	*scene;

	(void)state;
	scene = ft_calloc(1, sizeof(t_scene));
	key_press(K_W, scene);
	key_press(K_S, scene);
	assert_int_equal(scene->inputs.w, 1);
	assert_int_equal(scene->inputs.s, 1);
	assert_int_equal(scene->inputs.a, 0);
	assert_int_equal(scene->inputs.d, 0);
	assert_int_equal(scene->inputs.esc, 0);
	key_release(K_W, scene);
	key_release(K_S, scene);
	assert_int_equal(scene->inputs.w, 0);
	assert_int_equal(scene->inputs.s, 0);
	assert_int_equal(scene->inputs.a, 0);
	assert_int_equal(scene->inputs.d, 0);
	assert_int_equal(scene->inputs.esc, 0);
}

static void	key_press_two_times_test(void **state)
{
	t_scene	*scene;

	(void)state;
	scene = ft_calloc(1, sizeof(t_scene));
	key_press(K_W, scene);
	assert_int_equal(scene->inputs.w, 1);
	key_press(K_W, scene);
	assert_int_equal(scene->inputs.w, 1);
}

static void	key_release_two_times_test(void	**state)
{
	t_scene	*scene;

	(void)state;
	scene = ft_calloc(1, sizeof(t_scene));
	key_release(K_W, scene);
	assert_int_equal(scene->inputs.w, 0);
	key_release(K_W, scene);
	assert_int_equal(scene->inputs.w, 0);
}

int	main(void)
{
	const struct CMUnitTest	tests[] = {
		cmocka_unit_test(key_press_test),
		cmocka_unit_test(key_release_test),
		cmocka_unit_test(multi_key_press_test),
		cmocka_unit_test(multi_key_release_test),
		cmocka_unit_test(key_press_two_times_test),
		cmocka_unit_test(key_release_two_times_test),
	};
	return (cmocka_run_group_tests(tests, NULL, NULL));
}
