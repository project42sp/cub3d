/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-s <csilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 20:16:44 by csilva-s          #+#    #+#             */
/*   Updated: 2026/08/09 20:21:44 by csilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	null_test_success(void **state)
{
	(void) state;
}

int	main(void)
{
	const struct CMUnitTest	tests[];

	tests = {cmocka_unit_test(null_test_success),};
	return (cmocka_run_group_tests(tests, NULL, NULL));
}
