/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_commands.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalev <akovalev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:38:23 by akovalev          #+#    #+#             */
/*   Updated: 2024/01/09 19:25:17 by akovalev         ###   ########.fr       */
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


/* pa (push a): Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty.*/
int	pa(t_vec *a, t_vec *b)
{
	vec_insert(a, vec_get(b, 0), 0);
	vec_remove(b, 0);
	return (1);
}

/* pb (push b): Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty.*/
int	pb(t_vec *a, t_vec *b)
{
	vec_insert(b, vec_get(a, 0), 0);
	vec_remove(a, 0);
	return (1);
}

/* ra (rotate a): Shift up all elements of stack a by 1.
The first element becomes the last one.*/
int	ra(t_vec *a)
{
	vec_push(a, vec_get(a, 0));
	vec_remove(a, 0);
	return (1);
}

/* rb (rotate b): Shift up all elements of stack b by 1.
The first element becomes the last one.*/
int	rb(t_vec *b)
{
	vec_push(b, vec_get(b, 0));
	vec_remove(b, 0);
	return (1);
}

/*rr : ra and rb at the same time.*/
int	rr(t_vec *a, t_vec *b)
{
	ra(a);
	rb(b);
	return (1);
}

/*rra (reverse rotate a): Shift down all elements of stack a by 1.
The last element becomes the first one.*/
int	rra(t_vec *a)
{
	int x;

	x = *(int *)(vec_get(a, a->len - 1));
	vec_insert(a, &x, 0);
	vec_remove(a, a->len - 1);
	return (1);
}

/*rrb (reverse rotate b): Shift down all elements of stack b by 1.
The last element becomes the first one.*/
int	rrb(t_vec *b)
{
	int x;
	
	x = *(int *)(vec_get(b, b->len - 1));
	vec_insert(b, &x, 0);
	vec_remove(b, b->len - 1);
	return (1);
}

/*rrr : rra and rrb at the same time.*/
int	rrr(t_vec *a, t_vec *b)
{
	rra(a);
	rrb(b);
	return(1);
}