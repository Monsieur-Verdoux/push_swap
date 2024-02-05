/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalev <akovalev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:34:12 by akovalev          #+#    #+#             */
/*   Updated: 2024/01/30 14:12:09 by akovalev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	min_max_cost(t_vec *a, t_vec *b, t_move *info)
{
	if (info->i < a->len - info->i - 1)
		info->cost_a = info->i;
	else
		info->cost_a = a->len - info->i - 1;
	if (info->k < b->len - info->k - 1)
		info->cost_b = info->k;
	else
		info->cost_b = b->len - info->k - 1;
	if (info->i < a->len - info->i - 1 && info->k < b->len - info->k - 1)
	{
		if (info->i > info->k)
			info->cost_total = info->i;
		else
			info->cost_total = info->k;
	}
	if (info->i > a->len - info->i - 1 && info->k > b->len - info->k - 1)
	{
		if (a->len - info->i - 1 > b->len - info->k - 1)
			info->cost_total = a->len - info->i - 1;
		else
			info->cost_total = b->len - info->k - 1;
	}
	else
		info->cost_total = info->cost_a + info->cost_b;
}

void	handle_min_max(t_vec *a, t_vec *b, t_move *info)
{
	info->k = 0;
	while (info->k < b->len)
	{
		if (vec_int(b, info->k) == find_max(b))
		{
			min_max_cost(a, b, info);
			if (info->cost_total < info->cost_min)
			{
				info->cost_min = info->cost_total;
				info->ind_a = info->i;
				info->ind_b = info->k;
			}
		}
		info->k++;
	}
}

void	reverse_a_cost(t_vec *a, t_vec *b, t_move *info)
{
	if (info->j < b->len - info->j - 1)
	{
		info->cost_a = a->len - info->i - 1;
		info->cost_b = info->j;
		info->cost_total = info->cost_a + info->cost_b;
	}
	else
	{
		if (a->len - info->i - 1 > b->len - info->j - 1)
			info->cost_total = a->len - info->i - 1;
		else
			info->cost_total = b->len - info->j - 1;
	}
}

void	determine_direction_cost(t_vec *a, t_vec *b, t_move *info)
{
	if (info->i < a->len - info->i - 1)
	{
		if (info->j < b->len - info->j - 1)
		{
			if (info->i > info->j)
				info->cost_total = info->i;
			else
				info->cost_total = info->j;
		}
		else
		{
			info->cost_a = info->i;
			info->cost_b = b->len - info->j - 1;
			info->cost_total = info->cost_a + info->cost_b;
		}
	}
	else
		reverse_a_cost(a, b, info);
	if (info->cost_total < info->cost_min)
	{
		info->cost_min = info->cost_total;
		info->ind_a = info->i;
		info->ind_b = info->j;
	}
}

void	choose_move(t_vec *a, t_vec *b, t_move *info)
{
	initialize_info_struct(a, b, info);
	while (info->i < a->len)
	{
		if (vec_int(a, info->i) > find_max(b) || \
			vec_int(a, info->i) < find_min(b))
			handle_min_max(a, b, info);
		else
		{
			while (info->j < b->len)
			{
				if (info->j == 0)
					info->next = b->len - 1;
				else
					info->next = info->j - 1;
				if (vec_int(a, info->i) > vec_int(b, info->j) \
					&& vec_int(a, info->i) < vec_int(b, info->next))
					determine_direction_cost(a, b, info);
				info->j++;
			}
		}
		info->j = 0;
		info->i++;
	}
	smart_rotate(a, b, info);
	pb(a, b, 1);
}
