/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalev <akovalev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 17:32:05 by akovalev          #+#    #+#             */
/*   Updated: 2024/01/29 17:02:26 by akovalev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, const char **argv)
{
	t_vec	a;
	t_vec	b;

	if (argc < 2)
		exit(EXIT_FAILURE);
	vec_new(&a, 0, sizeof(int));
	vec_new(&b, 0, sizeof(int));
	process_arguments(argc, argv, &a, &b);
	check_order(&a, &b);
	push_swap(&a, &b);
	vec_free(&a);
	vec_free(&b);
	exit(EXIT_SUCCESS);
}
