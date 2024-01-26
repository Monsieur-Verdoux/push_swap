/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_tools_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalev <akovalev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:31:58 by akovalev          #+#    #+#             */
/*   Updated: 2024/01/26 17:34:19 by akovalev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	check_duplicates(t_vec *a, int num)
{
	size_t	j;

	j = -1;
	while (++j < a->len)
		if (num == vec_int(a, j))
			return (0);
	vec_push(a, &num);
	return (1);
}

int	build_vector(const char **arr, t_vec *a, bool check)
{
	size_t	i;
	size_t	j;
	long	temp_num;
	int		num;

	i = 1;
	if (check == 0)
		i = 0;
	while (arr[i])
	{
		j = -1;
		while (++j < ft_strlen(arr[i]))
			if (((arr[i][j] < 48 || arr[i][j] > 57) && arr[i][0] != 45) || \
			(arr[i][0] == 45 && ft_strlen(arr[i]) == 1) || \
				((arr[i][j] < 48 || arr[i][j] > 57) && j != 0))
				return (0);
		temp_num = ft_atoi_long(arr[i]);
		if (temp_num > 2147483647 || temp_num < -2147483648)
			return (0);
		num = (int)temp_num;
		if (!check_duplicates(a, num))
			return (0);
		i++;
	}
	return (1);
}

int	split_arg_string(const char **argv, t_vec *a)
{
	char	**ptr;

	if (!argv[1][0])
		return (0);
	ptr = ft_split(argv[1], ' ');
	if (!ptr)
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
