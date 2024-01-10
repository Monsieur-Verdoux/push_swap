/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalev <akovalev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:09:46 by akovalev          #+#    #+#             */
/*   Updated: 2024/01/09 19:24:54 by akovalev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "libft/get_next_line_bonus.h"
# include "libft/ft_printf.h"

void	sa(t_vec *vec);
void	sb(t_vec *b);
int ss(t_vec *a, t_vec *b);
void	print_vector(t_vec *vec);
int	pa(t_vec *a, t_vec *b);
int	pb(t_vec *a, t_vec *b);
int	ra(t_vec *a);
int	rb(t_vec *b);
int	rr(t_vec *a, t_vec *b);
int	rra(t_vec *a);
int	rrb(t_vec *b);
int	rrr(t_vec *a, t_vec *b);

#endif