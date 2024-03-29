/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalev <akovalev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:09:31 by akovalev          #+#    #+#             */
/*   Updated: 2024/01/29 16:08:01 by akovalev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_small(t_vec *a)
{
	if (a->len == 2)
	{
		if (vec_int(a, 0) > vec_int(a, 1))
			sa(a, 1);
	}
	else
	{
		if (vec_int(a, 0) > vec_int(a, 1) && vec_int(a, 0) < vec_int(a, 2))
			sa(a, 1);
		else if (vec_int(a, 0) < vec_int(a, 1) && vec_int(a, 0) > vec_int(a, 2))
			rra(a, 1);
		else if (vec_int(a, 0) > vec_int(a, 2) && vec_int(a, 2) > vec_int(a, 1))
			ra(a, 1);
		else if (vec_int(a, 0) < vec_int(a, 1) && vec_int(a, 1) > vec_int(a, 2))
		{
			sa(a, 1);
			ra(a, 1);
		}
		else if (vec_int(a, 0) > vec_int(a, 1) && vec_int(a, 1) > vec_int(a, 2))
		{
			sa(a, 1);
			rra(a, 1);
		}
	}
}

void	sort_four_five(t_vec *a, t_vec *b)
{
	pb(a, b, 1);
	pb(a, b, 1);
	sort_small(a);
	if (vec_int(b, b->len - 1) > vec_int(b, 0))
		sb(b, 1);
	if (vec_int(b, 0) < vec_int(a, 0))
	{
		pa(a, b, 1);
		pa(a, b, 1);
		return ;
	}
	while (vec_int(b, 0) < vec_int(a, a->len - 1))
		rra(a, 1);
	pa(a, b, 1);
	while (vec_int(b, 0) < vec_int(a, a->len - 1) && \
		vec_int(a, 0) > vec_int(a, a->len - 1))
		rra(a, 1);
	pa(a, b, 1);
	while (vec_int(a, 0) > vec_int(a, a->len - 1))
		rra(a, 1);
}

void	rebuild_a(t_vec *a, t_vec *b)
{
	while (vec_int(b, 0) < vec_int(a, a->len - 1) && find_min(a) < find_max(b))
		rra(a, 1);
	while (b->len > 0)
	{
		while (vec_int(a, a->len - 1) < vec_int(a, 0) && \
			vec_int(a, a->len - 1) > vec_int(b, 0))
			rra(a, 1);
		pa(a, b, 1);
	}
	while (vec_int(a, a->len - 1) < vec_int(a, 0))
		rra(a, 1);
}

void	sort_all(t_vec *a, t_vec *b)
{
	t_move	info;
	size_t	i;

	pb(a, b, 1);
	pb(a, b, 1);
	if (vec_int(b, 0) < vec_int(b, 1))
		sb(b, 1);
	while (a->len > 3)
		choose_move(a, b, &info);
	sort_small(a);
	info.ind_a = 0;
	i = 0;
	while (i < b->len)
	{
		if (vec_int(b, i) == find_max(b))
		{
			info.ind_b = i;
			break ;
		}
		i++;
	}
	smart_rotate(a, b, &info);
	rebuild_a(a, b);
}

void	push_swap(t_vec *a, t_vec *b)
{
	if (a->len <= 3)
		sort_small(a);
	else if (a->len == 5 || a->len == 4)
		sort_four_five(a, b);
	else if (a->len > 5)
		sort_all(a, b);
}
