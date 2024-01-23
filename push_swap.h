/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalev <akovalev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:09:46 by akovalev          #+#    #+#             */
/*   Updated: 2024/01/23 16:26:35 by akovalev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/libft.h"
# include "Libft/get_next_line_bonus.h"
# include "Libft/ft_printf.h"

typedef struct s_move
{
	int	i;
	int	j;
	int	next;
	int	cost_total;
	int	cost_a;
	int	cost_b;
	int	cost_min;
	int	ind_a;
	int	ind_b;
}	t_move;

void	sa(t_vec *vec, bool check);
void	sb(t_vec *b, bool check);
void	ss(t_vec *a, t_vec *b);
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
void	choose_move(t_vec *a, t_vec *b, t_move *info);
void	execute_move(t_vec *a, t_vec *b, int ind_a, int ind_b);
void	smart_rotate(t_vec *a, t_vec *b, int target_a, int target_b);
int		process_arguments(int argc, const char **argv, t_vec *a);
void	initialize_info_struct(t_vec *a, t_vec *b, t_move *info);

#endif

//void	smart_rotate_a(t_vec *a, int target);
//void	smart_rotate_b(t_vec *b, int target);