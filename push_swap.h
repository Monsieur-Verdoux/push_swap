/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalev <akovalev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:09:46 by akovalev          #+#    #+#             */
/*   Updated: 2024/01/29 17:02:12 by akovalev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/libft.h"
# include "Libft/get_next_line_bonus.h"
# include "Libft/ft_printf.h"

typedef struct s_move
{
	size_t		i;
	size_t		j;
	size_t		k;
	int			next;
	int			cost_total;
	int			cost_a;
	int			cost_b;
	int			cost_min;
	size_t		ind_a;
	size_t		ind_b;
	bool		a_forw;
	bool		b_forw;
}	t_move;

void	sa(t_vec *vec, bool check);
void	sb(t_vec *b, bool check);
void	ss(t_vec *a, t_vec *b, bool check);
void	pa(t_vec *a, t_vec *b, bool check);
void	pb(t_vec *a, t_vec *b, bool check);
void	ra(t_vec *a, bool check);
void	rb(t_vec *b, bool check);
void	rr(t_vec *a, t_vec *b, bool check);
void	rra(t_vec *a, bool check);
void	rrb(t_vec *b, bool check);
void	rrr(t_vec *a, t_vec *b, bool check);
int		find_max(t_vec *vec);
int		find_min(t_vec *vec);
void	choose_move(t_vec *a, t_vec *b, t_move *info);
void	execute_move(t_vec *a, t_vec *b, int ind_a, int ind_b);
void	smart_rotate(t_vec *a, t_vec *b, t_move *info);
void	process_arguments(int argc, const char **argv, t_vec *a, t_vec *b);
void	initialize_info_struct(t_vec *a, t_vec *b, t_move *info);
void	check_order(t_vec *a, t_vec *b);
void	push_swap(t_vec *a, t_vec *b);

#endif