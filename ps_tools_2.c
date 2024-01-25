/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_tools_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalev <akovalev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:32:05 by akovalev          #+#    #+#             */
/*   Updated: 2024/01/25 18:24:37 by akovalev         ###   ########.fr       */
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

// void	smart_rotate(t_vec *a, t_vec *b, t_move *info)
// {
// 	if (info->ind_a < a->len - info->ind_a - 1)
// 	{
// 		info->a_forw = 1;
// 		info->cost_a = info->ind_a ;
// 	}
// 	else
// 	{
// 		info->a_forw = 0;
// 		info->cost_a = a->len - info->ind_a;
// 	}
// 	if (info->ind_b < b->len - info->ind_b - 1)
// 	{
// 		info->b_forw = 1;
// 		info->cost_b = info->ind_b;
// 	}
// 	else
// 	{
// 		info->b_forw = 0;
// 		info->cost_b = b->len - info->ind_b;
// 	}
// 	if (info->a_forw == 1 && info->b_forw == 1)
// 	{
// 		if (info->cost_a > info->cost_b)
// 		{
// 			while (info->cost_b > 0)
// 			{
// 				rr(a, b);
// 				info->cost_a--;
// 				info->cost_b--;
// 			}
// 			while (info->cost_a > 0)
// 			{
// 				ra(a, 1);
// 				info->cost_a--;
// 			}
// 		}
// 		else
// 		{
// 			while (info->cost_a > 0)
// 			{
// 				rr(a, b);
// 				info->cost_b--;
// 				info->cost_a--;
// 			}
// 			while (info->cost_b > 0)
// 			{
// 				rb(b, 1);
// 				info->cost_b--;
// 			}
// 		}
// 	}
// 	if (info->a_forw == 0 && info->b_forw == 0)
// 	{
// 		if (info->cost_a > info->cost_b)
// 		{
// 			while (info->cost_b > 0)
// 			{
// 				rrr(a, b);
// 				info->cost_a--;
// 				info->cost_b--;
// 			}
// 			while (info->cost_a > 0)
// 			{
// 				rra(a, 1);
// 				info->cost_a--;
// 			}
// 		}
// 		else
// 		{
// 			while (info->cost_a > 0)
// 			{
// 				rrr(a, b);
// 				info->cost_b--;
// 				info->cost_a--;
// 			}
// 			while (info->cost_b > 0)
// 			{
// 				rrb(b, 1);
// 				info->cost_b--;
// 			}
// 		}
// 	}
// 	if (info->a_forw == 1 && info->b_forw == 0)
// 	{
// 		while (info->cost_a > 0)
// 		{
// 			ra(a, 1);
// 			info->cost_a--;
// 		}
// 		while (info->cost_b > 0)
// 		{
// 			rrb(b, 1);
// 			info->cost_b--;
// 		}
// 	}
// 	if (info->a_forw == 0 && info->b_forw == 1)
// 	{
// 		while (info->cost_a > 0)
// 		{
// 			rra(a, 1);
// 			info->cost_a--;
// 		}
// 		while (info->cost_b > 0)
// 		{
// 			rb(b, 1);
// 			info->cost_b--;
// 		}
// 	}
// }

// void	smart_rotate(t_vec *a, t_vec *b, t_move *info)
// {
// 	int	i;
// 	int	j;
// 	int	check;

// 	i = 0;
// 	j = 0;
// 	check = 0;
// 	while (i < a->len)
// 	{
// 		if (vec_int(a, i) == vec_int(a, info->ind_a))
// 		{
// 			if (a->len - i - 1 > i)
// 			{
// 				check = 1;
// 				break ;
// 			}
// 			else
// 			{
// 				i = a->len - i;
// 				check = 2;
// 				break ;
// 			}
// 		}
// 		i++;
// 	}
// 	while (j < b->len)
// 	{
// 		if (vec_int(b, j) == vec_int(b, info->ind_b))
// 		{
// 			if (b->len - j - 1 > j)
// 			{
// 				if (check == 1)
// 				{
// 					if (i > j)
// 					{
// 						while (j > 0)
// 						{
// 							rr(a, b);
// 							j--;
// 							i--;
// 						}
// 						while (i > 0)
// 						{
// 							ra(a, 1);
// 							i--;
// 						}
// 						return ;
// 					}
// 					else
// 					{
// 						while (i > 0)
// 						{
// 							rr(a, b);
// 							j--;
// 							i--;
// 						}
// 						while (j > 0)
// 						{
// 							rb(b, 1);
// 							j--;
// 						}
// 						return ;
// 					}
// 				}
// 				else
// 				{
// 					while (j > 0)
// 					{
// 						rb(b, 1);
// 						j--;
// 					}
// 					while (i > 0)
// 					{
// 						rra(a, 1);
// 						i--;
// 					}
// 					return ;
// 				}
// 			}
// 			else
// 			{
// 				j = b->len - j;
// 				if (check == 2)
// 				{
// 					if (i > j)
// 					{
// 						while (j > 0)
// 						{
// 							rrr(a, b);
// 							j--;
// 							i--;
// 						}
// 						while (i > 0)
// 						{
// 							rra(a, 1);
// 							i--;
// 						}
// 						return ;
// 					}
// 					else
// 					{
// 						while (i > 0)
// 						{
// 							rrr(a, b);
// 							j--;
// 							i--;
// 						}
// 						while (j > 0)
// 						{
// 							rrb(b, 1);
// 							j--;
// 						}
// 						return ;
// 					}
// 				}
// 				else
// 				{
// 					while (j > 0)
// 					{
// 						rrb(b, 1);
// 						j--;
// 					}
// 					while (i > 0)
// 					{
// 						ra(a, 1);
// 						i--;
// 					}
// 					return ;
// 				}
// 			}
// 		}
// 		j++;
// 	}
// }
