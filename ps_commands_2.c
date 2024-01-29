/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_commands_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalev <akovalev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:37:41 by akovalev          #+#    #+#             */
/*   Updated: 2024/01/29 15:23:42 by akovalev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*rrr : rra and rrb at the same time.*/
void	rrr(t_vec *a, t_vec *b, bool check)
{
	rra(a, 0);
	rrb(b, 0);
	if (check == 1)
		ft_printf("rrr\n");
}
