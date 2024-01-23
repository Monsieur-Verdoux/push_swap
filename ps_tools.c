/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalev <akovalev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:34:12 by akovalev          #+#    #+#             */
/*   Updated: 2024/01/23 15:47:47 by akovalev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	vec_int(t_vec *vec, int index)
{
	return (*(int *)vec_get(vec, index));
}

void	print_vector(t_vec *vec)
{
	int	i;

	i = 0;
	while (i < vec->len)
	{
		ft_printf("Vector element %d: %d\n", i, vec_int(vec, i));
		i++;
	}
}

int	find_max(t_vec *vec)
{
	int	i;
	int	max;

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
	int	i;
	int	min;

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

// void	smart_rotate_a(t_vec *a, int target)
// {
// 	int	i;

// 	i = 0;
// 	while (i < a->len)
// 	{
// 		if (vec_int(a, i) == target)
// 		{
// 			if (a->len - i - 1 > i)
// 			{
// 				i++;
// 				while (i-- > 0)
// 					ra(a, 1);
// 			}
// 			else
// 			{
// 				i = a->len - i;
// 				while (i > 0)
// 				{
// 					rra(a, 1);
// 					i--;
// 				}
// 			}
// 		}
// 		i++;
// 	}
// }

// void	smart_rotate_b(t_vec *b, int target)
// {
// 	int	i;

// 	i = 0;
// 	while (i < b->len)
// 	{
// 		if (vec_int(b, i) == target)
// 		{
// 			if (b->len - i - 1 > i)
// 			{
// 				i++;
// 				while (i-- > 0)
// 					rb(b, 1);
// 			}
// 			else
// 			{
// 				i = b->len - i;
// 				while (i > 0)
// 				{
// 					rrb(b, 1);
// 					i--;
// 				}
// 			}
// 		}
// 		i++;
// 	}
// }

void	smart_rotate(t_vec *a, t_vec *b, int target_a, int target_b)
{
	int	i;
	int	j;
	int	check;

	i = 0;
	j = 0;
	check = 0;
	while (i < a->len)
	{
		if (vec_int(a, i) == target_a)
		{
			if (a->len - i - 1 > i)
			{
				check = 1;
				break ;
			}
			else
			{
				i = a->len - i;
				check = 2;
				break ;
			}
		}
		i++;
	}
	while (j < b->len)
	{
		if (vec_int(b, j) == target_b)
		{
			if (b->len - j - 1 > j)
			{
				if (check == 1)
				{
					if (i > j)
					{
						while (j > 0)
						{
							rr(a, b);
							j--;
							i--;
						}
						while (i > 0)
						{
							ra(a, 1);
							i--;
						}
						return ;
					}
					else
					{
						while (i > 0)
						{
							rr(a, b);
							j--;
							i--;
						}
						while (j > 0)
						{
							rb(b, 1);
							j--;
						}
						return ;
					}
				}
				else
				{
					while (j > 0)
					{
						rb(b, 1);
						j--;
					}
					while (i > 0)
					{
						rra(a, 1);
						i--;
					}
					return ;
				}
			}
			else
			{
				j = b->len - j;
				if (check == 2)
				{
					if (i > j)
					{
						while (j > 0)
						{
							rrr(a, b);
							j--;
							i--;
						}
						while (i > 0)
						{
							rra(a, 1);
							i--;
						}
						return ;
					}
					else
					{
						while (i > 0)
						{
							rrr(a, b);
							j--;
							i--;
						}
						while (j > 0)
						{
							rrb(b, 1);
							j--;
						}
						return ;
					}
				}
				else
				{
					while (j > 0)
					{
						rrb(b, 1);
						j--;
					}
					while (i > 0)
					{
						ra(a, 1);
						i--;
					}
					return ;
				}
			}
		}
		j++;
	}
}
// void	initialize_struct(t_vec *a, t_vec *b)
// {
	
// }
void	choose_move(t_vec *a, t_vec *b)
{
	int	i;
	int	j;
	int	k;
	int	next;
	int	cost_total;
	int	cost_a;
	int	cost_b;
	int	cost_min;
	int	ind_a;
	int	ind_b;

	i = 0;
	j = 0;
	k = 0;
	ind_a = a->len;
	ind_b = b->len;
	cost_a = a->len;
	cost_b = b->len;
	cost_min = cost_a + cost_b;
	while (i < a->len)
	{
		if (vec_int(a, i) > find_max(b) || vec_int(a, 0) < find_min(b))
		{
			k = 0;
			while (k < b->len)
			{
				if (vec_int(b, k) == find_max(b))
				{
					if (i < a->len - i - 1)
						cost_a = i;
					else
						cost_a = a->len - i - 1;
					if (k < b->len - k - 1)
						cost_b = k;
					else
						cost_b = b->len - k - 1;
					cost_total = cost_a + cost_b;
					if (cost_total < cost_min)
					{
						cost_min = cost_total;
						ind_a = i;
						ind_b = k;
					}
				}
				k++;
			}
		}
		while (j < b->len)
		{
			if (j == 0)
				next = b->len - 1;
			else
				next = j - 1;
			if (vec_int(a, i) > vec_int(b, j) && vec_int(a, i) < vec_int(b, next))
			{
				if (i < a->len - i - 1)
				{
					if (j < b->len - j - 1)
					{
						if (i > j)
							cost_total = i;
						else
							cost_total = j;
					}
					else
					{
						cost_a = i;
						cost_b = b->len - j - 1;
						cost_total = cost_a + cost_b;
					}
				}
				else
				{
					if (j < b->len - j - 1)
					{
						cost_a = a->len - i - 1;
						cost_b = j;
						cost_total = cost_a + cost_b;
					}
					else
					{
						if (a->len - i - 1 > b->len - j - 1)
							cost_total = a->len - i - 1;
						else
							cost_total = b->len - j - 1;
					}
				}
				if (cost_total < cost_min)
				{
					cost_min = cost_total;
					ind_a = i;
					ind_b = j;
				}
			}
			j++;
		}
		j = 0;
		i++;
	}
	execute_move(a, b, ind_a, ind_b);
}

void	execute_move(t_vec *a, t_vec *b, int ind_a, int ind_b)
{
	 //smart_rotate_a(a, vec_int(a, ind_a));
	 //smart_rotate_b(b, vec_int(b, ind_b));
	smart_rotate(a, b, vec_int(a, ind_a), vec_int(b, ind_b));
	pb(a, b);
}
