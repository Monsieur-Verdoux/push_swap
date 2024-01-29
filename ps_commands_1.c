/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_commands_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalev <akovalev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:37:34 by akovalev          #+#    #+#             */
/*   Updated: 2024/01/29 15:22:46 by akovalev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
void	rr(t_vec *a, t_vec *b, bool check)
{
	ra(a, 0);
	rb(b, 0);
	if (check == 1)
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
