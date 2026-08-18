/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmocka.spec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-s <csilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 22:02:22 by csilva-s          #+#    #+#             */
/*   Updated: 2026/08/17 22:02:23 by csilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cmocka.h>

static void  check_null_cases(void **states)
{
        (void)states;
        int n = 2;
        assert_false(n);
}
int main(void)
{
    const struct CMUnitTest tests[] = {cmocka_unit_test(check_null_cases),};
    return (cmocka_run_group_tests(tests, NULL, NULL));
}
