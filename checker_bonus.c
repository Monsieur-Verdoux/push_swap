/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalev <akovalev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 18:30:52 by akovalev          #+#    #+#             */
/*   Updated: 2024/01/29 17:04:37 by akovalev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	checker_order(t_vec *a, t_vec *b)
{
	size_t	i;

	if (b->len != 0)
		return (0);
	if (a->len == 1)
	{
		vec_free(a);
		vec_free(b);
		exit(EXIT_SUCCESS);
	}
	i = 1;
	while (i < a->len)
	{
		if (vec_int(a, i - 1) < vec_int(a, i))
			i++;
		else
			return (0);
	}
	return (1);
}

int	process_single_command(t_vec *a, t_vec *b, char *str)
{
	if (ft_strncmp(str, "ra\n", ft_strlen(str)) == 0)
		ra(a, 0);
	else if (ft_strncmp(str, "rb\n", ft_strlen(str)) == 0)
		rb(b, 0);
	else if (ft_strncmp(str, "sa\n", ft_strlen(str)) == 0)
		sa(a, 0);
	else if (ft_strncmp(str, "sb\n", ft_strlen(str)) == 0)
		sb(b, 0);
	else if (ft_strncmp(str, "rra\n", ft_strlen(str)) == 0)
		rra(a, 0);
	else if (ft_strncmp(str, "rrb\n", ft_strlen(str)) == 0)
		rrb(b, 0);
	else if (ft_strncmp(str, "pa\n", ft_strlen(str)) == 0)
		pa(a, b, 0);
	else if (ft_strncmp(str, "pb\n", ft_strlen(str)) == 0)
		pb(a, b, 0);
	else if (ft_strncmp(str, "rr\n", ft_strlen(str)) == 0)
		rr(a, b, 0);
	else if (ft_strncmp(str, "ss\n", ft_strlen(str)) == 0)
		ss(a, b, 0);
	else if (ft_strncmp(str, "rrr\n", ft_strlen(str)) == 0)
		rrr(a, b, 0);
	else
		return (0);
	return (1);
}

void	check_commands(t_vec *a, t_vec *b, char *str)
{
	while (str)
	{
		if (!process_single_command(a, b, str))
		{
			free(str);
			vec_free(a);
			vec_free(b);
			write(2, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
		free(str);
		str = get_next_line(0);
	}
}

int	main(int argc, const char **argv)
{
	t_vec	a;
	t_vec	b;
	char	*str;

	if (argc < 2)
		exit(EXIT_FAILURE);
	vec_new(&a, 0, sizeof(int));
	vec_new(&b, 0, sizeof(int));
	process_arguments(argc, argv, &a, &b);
	str = get_next_line(0);
	check_commands (&a, &b, str);
	if (!checker_order(&a, &b))
	{
		write(1, "KO\n", 3);
		vec_free(&a);
		vec_free(&b);
		exit(EXIT_FAILURE);
	}
	else
		write(1, "OK\n", 3);
	vec_free(&a);
	vec_free(&b);
	exit(EXIT_SUCCESS);
}
