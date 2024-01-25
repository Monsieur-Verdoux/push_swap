/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalev <akovalev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:18:43 by akovalev          #+#    #+#             */
/*   Updated: 2024/01/25 18:49:04 by akovalev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initialize_dir_cost(t_vec *a, t_vec *b, t_move *info)
{
	if (info->ind_a < a->len - info->ind_a - 1)
	{
		info->a_forw = 1;
		info->cost_a = info->ind_a;
	}
	else
	{
		info->a_forw = 0;
		info->cost_a = a->len - info->ind_a;
	}
	if (info->ind_b < b->len - info->ind_b - 1)
	{
		info->b_forw = 1;
		info->cost_b = info->ind_b;
	}
	else
	{
		info->b_forw = 0;
		info->cost_b = b->len - info->ind_b;
	}
}

void	both_forward(t_vec *a, t_vec *b, t_move *info)
{
	if (info->cost_a > info->cost_b)
	{
		while (info->cost_b > 0)
		{
			rr(a, b);
			info->cost_a--;
			info->cost_b--;
		}
		while (info->cost_a-- > 0)
			ra(a, 1);
	}
	else
	{
		while (info->cost_a > 0)
		{
			rr(a, b);
			info->cost_b--;
			info->cost_a--;
		}
		while (info->cost_b-- > 0)
			rb(b, 1);
	}
}

void	both_reverse(t_vec *a, t_vec *b, t_move *info)
{
	if (info->cost_a > info->cost_b)
	{
		while (info->cost_b > 0)
		{
			rrr(a, b);
			info->cost_a--;
			info->cost_b--;
		}
		while (info->cost_a-- > 0)
			rra(a, 1);
	}
	else
	{
		while (info->cost_a > 0)
		{
			rrr(a, b);
			info->cost_b--;
			info->cost_a--;
		}
		while (info->cost_b-- > 0)
			rrb(b, 1);
	}
}

void	smart_rotate(t_vec *a, t_vec *b, t_move *info)
{
	initialize_dir_cost(a, b, info);
	if (info->a_forw == 1 && info->b_forw == 1)
		both_forward(a, b, info);
	if (info->a_forw == 0 && info->b_forw == 0)
		both_reverse(a, b, info);
	if (info->a_forw == 1 && info->b_forw == 0)
	{
		while (info->cost_a-- > 0)
			ra(a, 1);
		while (info->cost_b-- > 0)
			rrb(b, 1);
	}
	if (info->a_forw == 0 && info->b_forw == 1)
	{
		while (info->cost_a-- > 0)
			rra(a, 1);
		while (info->cost_b-- > 0)
			rb(b, 1);
	}
}
