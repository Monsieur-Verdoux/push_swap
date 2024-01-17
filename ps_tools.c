/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalev <akovalev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:34:12 by akovalev          #+#    #+#             */
/*   Updated: 2024/01/17 18:15:19 by akovalev         ###   ########.fr       */
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
	while(i < vec->len)
	{
		if (vec_int(vec, i) > max)
			max = vec_int(vec, i);
		i++;
	}
	return (max);
}

int	find_min(t_vec *vec)
{
	int i;
	int min;

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

void	smart_rotate_a(t_vec *a, int target)
{
	int	i;

	i = 0;
	while (i < a->len)
	{
		if (vec_int(a, i) == target)
		{
			if (a->len - i - 1 > i)
				while (i > 0)
				{
					ra(a, 1);
					i--;
				}
			else
			{
				i = a->len - i;
				while (i > 0)
				{
					rra(a, 1);
					i--;
				}
			}
		}
		i++;
	}
}

void	smart_rotate_b(t_vec *b, int target)
{
	int	i;

	i = 0;
	while (i < b->len)
	{
		if (vec_int(b, i) == target)
		{
			if (b->len - i - 1 > i)
				while (i > 0)
				{
					rb(b, 1);
					i--;
				}
			else
			{
				i = b->len - i;
				while (i > 0)
				{
					rrb(b, 1);
					i--;
				}
			}
		}
		i++;
	}
}

void	choose_move(t_vec *a, t_vec *b)
{
	int	i;
	int j;
	int	next;
	int	cost_total;
	int	cost_a;
	int	cost_b;
	int	cost_min;
	int	ind_a;
	int	ind_b;
	
	i = 0;
	j = 0;
	ind_a = a->len;
	ind_b = b->len;
	cost_a = a->len;
	cost_b = b->len;
	cost_min = cost_a + cost_b;
	//print_vector(b);
	while (i < a->len)
	{
		while(j < b->len)
		{
			if (j == 0)
				next = b->len - 1;
			else 
				next = j - 1;
			if (vec_int(a, i) > find_max(b))
			{
				j = 0;
				while (j < b->len)
				{
					if (vec_int(b, j) == find_max(b))
					{
						ft_printf("\n found max \n");
						execute_move(a, b, i, j);
						return ;
					}
					j++;
				}				
			}
			if (vec_int(a, i) < find_min(b))
			{
				j = 0;
				while (j < b->len)
				{
					if (vec_int(b, j) == find_min(b))
					{
						ft_printf("\n found max \n");
						execute_move(a, b, i, j);
						return ;
					}
					j++;
				}		
			}
			//ft_printf("\n next: %d\n", next);
			if (vec_int(a, i) > vec_int(b, j) && vec_int(a, i) < vec_int(b, next))
			{
				//ft_printf("\n got here \n");
				if (i < a->len - i - 1)
					cost_a = i;
				else 
					cost_a = a->len - i - 1;
				if (j < b->len - j - 1)
					cost_b = j;
				else
					cost_b = b->len - j - 1;
				cost_total = cost_a + cost_b;
				//ft_printf("\n cost total: %d\n", cost_total);
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
	smart_rotate_a(a, vec_int(a, ind_a));
	smart_rotate_b(b, vec_int(b, ind_b));
	pb(a, b);
}