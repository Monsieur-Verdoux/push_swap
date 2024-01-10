/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_commands.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalev <akovalev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:38:23 by akovalev          #+#    #+#             */
/*   Updated: 2024/01/10 16:27:05 by akovalev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*sa (swap a): Swap the first 2 elements at the top of stack a.
Do nothing if there is only one or no elements.*/
void	sa(t_vec *vec)
{
	int	*ptr;
	int	num;

	ft_printf("\nVector elements before swap: \n");
	print_vector(vec);
	
	vec_insert(vec, vec_get(vec, 1), 0);
	vec_remove(vec, 2);

	ft_printf("\nVector elements before swap: \n");
	print_vector(vec);
	ft_printf("sa\n");
	
	//ft_printf("Vector elements after swap: %d, %d\n", *(int *)vec_get(vec, 0), *(int *)vec_get(vec, 1));	
}
/* sb (swap b): Swap the first 2 elements at the top of stack b.
Do nothing if there is only one or no elements.*/
void	sb(t_vec *vec)
{
	int	*ptr;
	int	num;

	ft_printf("\nVector elements before swap: \n");
	print_vector(vec);
	
	vec_insert(vec, vec_get(vec, 1), 0);
	vec_remove(vec, 2);

	ft_printf("\nVector elements before swap: \n");
	print_vector(vec);
	ft_printf("sa\n");
	
	//ft_printf("Vector elements after swap: %d, %d\n", *(int *)vec_get(vec, 0), *(int *)vec_get(vec, 1));	
}

/* ss : sa and sb at the same time.*/
int ss(t_vec *a, t_vec *b)
{
	sa(a);
	sb(b);
	return (1);
}
