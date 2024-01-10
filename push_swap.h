/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalev <akovalev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:09:46 by akovalev          #+#    #+#             */
/*   Updated: 2024/01/10 18:50:33 by akovalev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/libft.h"
# include "Libft/get_next_line_bonus.h"
# include "Libft/ft_printf.h"

void	sa(t_vec *vec);
void	sb(t_vec *b);
void	ss(t_vec *a, t_vec *b);
void	print_vector(t_vec *vec);
int		vec_int(t_vec *vec, int index);
void	pa(t_vec *a, t_vec *b);
void	pb(t_vec *a, t_vec *b);
void	ra(t_vec *a);
void	rb(t_vec *b);
void	rr(t_vec *a, t_vec *b);
void	rra(t_vec *a);
void	rrb(t_vec *b);
void	rrr(t_vec *a, t_vec *b);
#endif