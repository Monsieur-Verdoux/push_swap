/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalev <akovalev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:34:12 by akovalev          #+#    #+#             */
/*   Updated: 2024/01/11 16:22:13 by akovalev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	vec_int(t_vec *vec, int index)
{
	return (*(int *)vec_get(vec, index));
}

void	print_vector(t_vec *vec)
{
	int	i;

	i = 0;
	while (i < vec->len)
	{
		ft_printf("Vector element %d: %d\n", i, vec_int(vec, i));
		i++;
	}
}
