/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalev <akovalev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:09:46 by akovalev          #+#    #+#             */
/*   Updated: 2024/01/23 15:40:34 by akovalev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/libft.h"
# include "Libft/get_next_line_bonus.h"
# include "Libft/ft_printf.h"

void	sa(t_vec *vec, bool check);
void	sb(t_vec *b, bool check);
void	ss(t_vec *a, t_vec *b);
void	print_vector(t_vec *vec);
int		vec_int(t_vec *vec, int index);
void	pa(t_vec *a, t_vec *b);
void	pb(t_vec *a, t_vec *b);
void	ra(t_vec *a, bool check);
void	rb(t_vec *b, bool check);
void	rr(t_vec *a, t_vec *b);
void	rra(t_vec *a, bool check);
void	rrb(t_vec *b, bool check);
void	rrr(t_vec *a, t_vec *b);
int		find_max(t_vec *vec);
int		find_min(t_vec *vec);
void	choose_move(t_vec *a, t_vec *b);
void	execute_move(t_vec *a, t_vec *b, int ind_a, int ind_b);
void	smart_rotate(t_vec *a, t_vec *b, int target_a, int target_b);
int		process_arguments(int argc, const char **argv, t_vec *a);

#endif

//void	smart_rotate_a(t_vec *a, int target);
//void	smart_rotate_b(t_vec *b, int target);