/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalev <akovalev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:09:31 by akovalev          #+#    #+#             */
/*   Updated: 2024/01/16 17:22:45 by akovalev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//to-do: errors for num > int

void	free_split(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	build_vector(const char **arr, t_vec *a, bool check)
{
	int		i;
	int		j;
	int		num;

	i = 1;
	if (check == 0)
		i = 0;
	while (arr[i])
	{
		j = -1;
		while (++j < ft_strlen(arr[i]))
			if (((arr[i][j] < 48 || arr[i][j] > 57) && arr[i][0] != 45) \
			|| (arr[i][0] == 45 && ft_strlen(arr[i]) == 1))
				return (0);
		num = ft_atoi(arr[i]);
		j = -1;
		while (++j < a->len)
			if (num == vec_int(a, j))
				return (0);
		vec_push(a, &num);
		i++;
	}
	return (1);
}

int	split_arg_string(const char **argv, t_vec *a)
{
	char	**ptr;

	ptr = ft_split(argv[1], ' ');
	if (!ptr)
	{
		free_split(ptr);
		return (0);
	}
	if (ptr[1] == NULL)
	{
		free_split(ptr);
		return (0);
	}
	if (!build_vector((const char **)ptr, a, 0))
	{
		free_split(ptr);
		return (0);
	}
	free_split(ptr);
	return (1);
}

int	process_arguments(int argc, const char **argv, t_vec *a)
{
	if (argc == 2)
	{
		if (!split_arg_string(argv, a))
			return (0);
	}
	else if (!build_vector(argv, a, 1))
		return (0);
	return (1);
}

void	sort_small(t_vec *a)
{
	if (a->len == 2)
	{
		if (vec_int(a, 0) > vec_int(a, 1))
			sa(a, 1);
	}
	else
	{
		if (vec_int(a, 0) > vec_int(a, 1) && vec_int(a, 0) < vec_int(a, 2))
			sa(a, 1);
		else if (vec_int(a, 0) < vec_int(a, 1) && vec_int(a, 0) > vec_int(a, 2))
			rra(a, 1);
		else if (vec_int(a, 0) > vec_int(a, 2) && vec_int(a, 2) > vec_int(a, 1))
			ra(a, 1);
		else if (vec_int(a, 0) < vec_int(a, 1) && vec_int(a, 1) > vec_int(a, 2))
		{
			sa(a, 1);
			ra(a, 1);
		}
		else if (vec_int(a, 0) > vec_int(a, 1) && vec_int(a, 1) > vec_int(a, 2))
		{
			sa(a, 1);
			rra(a, 1);
		}
	}
}

void	sort_four_five(t_vec *a, t_vec *b)
{
	pb(a, b);
	pb(a, b);
	sort_small(a);
	if (vec_int(b, b->len - 1) > vec_int(b, 0))
		sb(b, 1);
	if (vec_int(b, 0) < vec_int(a, 0))
	{
		pa(a, b);
		pa(a, b);
		return ;
	}
	while (vec_int(b, 0) < vec_int(a, a->len - 1))
		rra(a, 1);
	pa(a, b);
	while (vec_int(b, 0) < vec_int(a, a->len - 1) && \
		vec_int(a, 0) > vec_int(a, a->len - 1))
		rra(a, 1);
	pa(a, b);
	while (vec_int(a, 0) > vec_int(a, a->len - 1))
		rra(a, 1);
}

int	main(int argc, const char **argv)
{
	t_vec	a;
	t_vec	b;

	if (argc < 2)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	vec_new(&a, 0, sizeof(int));
	vec_new(&b, 0, sizeof(int));
	if (!process_arguments(argc, argv, &a))
	{
		write(2, "Error\n", 6);
		vec_free(&a);
		vec_free(&b);
		return (0);
	}
	if (a.len <= 3)
		sort_small(&a);
	if (a.len == 5 || a.len == 4)
		sort_four_five(&a, &b);
	vec_free(&a);
	vec_free(&b);
	return (1);
}

/*need to implement error handling for bigger than int numbers:
num = ft_atoi(ptr[k]);
		if (num > 2147483647 || num < -2147483648)
			return (-1);
		int_num = (int)num;*/