/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_tools_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalev <akovalev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:32:05 by akovalev          #+#    #+#             */
/*   Updated: 2024/01/26 17:44:33 by akovalev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max(t_vec *vec)
{
	size_t	i;
	int		max;

	i = 0;
	max = vec_int(vec, 0);
	while (i < vec->len)
	{
		if (vec_int(vec, i) > max)
			max = vec_int(vec, i);
		i++;
	}
	return (max);
}

int	find_min(t_vec *vec)
{
	size_t	i;
	int		min;

	i = 0;
	min = vec_int(vec, 0);
	while (i < vec->len)
	{
		if (vec_int(vec, i) < min)
			min = vec_int(vec, i);
		i++;
	}
	return (min);
}

void	initialize_info_struct(t_vec *a, t_vec *b, t_move *info)
{
	info->i = 0;
	info->j = 0;
	info->k = 0;
	info->ind_a = a->len;
	info->ind_b = b->len;
	info->ind_a = a->len;
	info->cost_b = b->len;
	info->cost_min = info->ind_a + info->cost_b;
	info->a_forw = 0;
	info->b_forw = 0;
}

void	check_order(t_vec *a, t_vec *b)
{
	size_t	i;

	if (a->len == 1)
	{
		vec_free(a);
		vec_free(b);
		exit(EXIT_SUCCESS);
	}
	i = 1;
	while (i < a->len)
	{
		if (vec_int(a, i - 1) < vec_int(a, i))
			i++;
		else
			return ;
	}
	vec_free(a);
	vec_free(b);
	exit(EXIT_SUCCESS);
}
