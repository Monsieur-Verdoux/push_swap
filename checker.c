/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalev <akovalev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 18:30:52 by akovalev          #+#    #+#             */
/*   Updated: 2024/01/26 19:24:36 by akovalev         ###   ########.fr       */
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

int	main(int argc, const char **argv)
{
	t_vec	a;
	t_vec	b;
	char	*str;

	if (argc < 2)
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	vec_new(&a, 0, sizeof(int));
	vec_new(&b, 0, sizeof(int));
	if (!process_arguments(argc, argv, &a))
	{
		write(2, "Error\n", 6);
		vec_free(&a);
		vec_free(&b);
		exit(EXIT_FAILURE);
	}
	check_order(&a, &b);
	while ((str = get_next_line(0)) != NULL)
	{
		if (ft_strncmp(str, "ra\n", ft_strlen(str)) == 0)
			ra(&a, 1);
		else if (ft_strncmp(str, "rb\n", ft_strlen(str)) == 0)
			rb(&b, 1);
		else if (ft_strncmp(str, "sa\n", ft_strlen(str)) == 0)
			sa(&a, 1);
		else if (ft_strncmp(str, "sb\n", ft_strlen(str)) == 0)
			sb(&b, 1);
		else if (ft_strncmp(str, "rra\n", ft_strlen(str)) == 0)
			rra(&a, 1);
		else if (ft_strncmp(str, "rrb\n", ft_strlen(str)) == 0)
			rrb(&b, 1);
		else if (ft_strncmp(str, "pa\n", ft_strlen(str)) == 0)
			pa(&a, &b);
		else if (ft_strncmp(str, "pb\n", ft_strlen(str)) == 0)
			pb(&a, &b);
		else if (ft_strncmp(str, "rr\n", ft_strlen(str)) == 0)
			rr(&a, &b);
		else if (ft_strncmp(str, "ss\n", ft_strlen(str)) == 0)
			ss(&a, &b);
		else if (ft_strncmp(str, "rrr\n", ft_strlen(str)) == 0)
			rrr(&a, &b);
		else
		{
			free(str);
			vec_free(&a);
			vec_free(&b);
			write(1, "KO", 2);
			exit(EXIT_FAILURE);
		}
		free(str);
	}
	if (!checker_order(&a, &b))
	{
		write(1, "KO", 2);
		vec_free(&a);
		vec_free(&b);
		exit(EXIT_FAILURE);
	}
	else
		write(1, "OK", 2);
	vec_free(&a);
	vec_free(&b);
	exit(EXIT_SUCCESS);
}
