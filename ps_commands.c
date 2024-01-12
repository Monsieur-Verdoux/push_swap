/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_commands.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalev <akovalev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:38:23 by akovalev          #+#    #+#             */
/*   Updated: 2024/01/12 13:41:24 by akovalev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*sa (swap a): Swap the first 2 elements at the top of stack a.
Do nothing if there is only one or no elements.*/

void	sa(t_vec *a, bool check)
{
	int	num;
	int	*ptr;

	if (a->len <= 1)
		return ;
	num = vec_int(a, 1);
	ptr = &num;
	vec_insert(a, ptr, 0);
	vec_remove(a, 2);
	if (check == 1)
		ft_printf("sa\n");
}

/* sb (swap b): Swap the first 2 elements at the top of stack b.
Do nothing if there is only one or no elements.*/
void	sb(t_vec *b, bool check)
{
	int	*ptr;
	int	num;

	if (b->len <= 1)
		return ;
	num = vec_int(b, 1);
	ptr = &num;
	vec_insert(b, ptr, 0);
	vec_remove(b, 2);
	if (check == 1)
		ft_printf("sb\n");
}

/* ss : sa and sb at the same time.*/
void	ss(t_vec *a, t_vec *b)
{
	sa(a, 0);
	sb(b, 0);
	ft_printf("ss\n");
}

/* pa (push a): Take the first element 
at the top of b and put it at the top of a.
Do nothing if b is empty.*/
void	pa(t_vec *a, t_vec *b)
{
	if (!b->memory)
		return ;
	vec_insert(a, vec_get(b, 0), 0);
	vec_remove(b, 0);
	ft_printf("pa\n");
}

/* pb (push b): Take the first element 
at the top of a and put it at the top of b.
Do nothing if a is empty.*/
void	pb(t_vec *a, t_vec *b)
{
	if (!a->memory)
		return ;
	vec_insert(b, vec_get(a, 0), 0);
	vec_remove(a, 0);
	ft_printf("pb\n");
}

/* ra (rotate a): Shift up all elements of stack a by 1.
The first element becomes the last one.*/
void	ra(t_vec *a, bool check)
{
	int	num;
	int	*ptr;

	num = vec_int(a, 0);
	ptr = &num;
	vec_remove(a, 0);
	vec_push(a, ptr);
	if (check == 1)
		ft_printf("ra\n");
}

/* rb (rotate b): Shift up all elements of stack b by 1.
The first element becomes the last one.*/
void	rb(t_vec *b, bool check)
{
	int	num;
	int	*ptr;

	num = vec_int(b, 0);
	ptr = &num;
	vec_remove(b, 0);
	vec_push(b, ptr);
	if (check == 1)
		ft_printf("rb\n");
}

/*rr : ra and rb at the same time.*/
void	rr(t_vec *a, t_vec *b)
{
	ra(a, 0);
	rb(b, 0);
	ft_printf("rr\n");
}

/*rra (reverse rotate a): Shift down all elements of stack a by 1.
The last element becomes the first one.*/
void	rra(t_vec *a, bool check)
{
	int	num;
	int	*ptr;

	num = vec_int(a, a->len - 1);
	ptr = &num;
	vec_remove(a, a->len - 1);
	vec_insert(a, ptr, 0);
	if (check == 1)
		ft_printf("rra\n");
}

/*rrb (reverse rotate b): Shift down all elements of stack b by 1.
The last element becomes the first one.*/
void	rrb(t_vec *b, bool check)
{
	int	num;
	int	*ptr;

	num = vec_int(b, b->len - 1);
	ptr = &num;
	vec_remove(b, b->len - 1);
	vec_insert(b, ptr, 0);
	if (check == 1)
		ft_printf("rrb\n");
}

/*rrr : rra and rrb at the same time.*/
void	rrr(t_vec *a, t_vec *b)
{
	rra(a, 0);
	rrb(b, 0);
	ft_printf("rrr\n");
}
