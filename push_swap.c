/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalev <akovalev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:09:31 by akovalev          #+#    #+#             */
/*   Updated: 2024/01/09 19:18:56 by akovalev         ###   ########.fr       */
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
int	split_arg_string(const char **argv, t_vec *a)
{
	int		j;
	int		k;
	char 	**ptr;
	int		num;
	
	k = 0;
	j = 0;
	ptr = ft_split(argv[1], ' ');
	while (ptr[k])
	{
		j = 0;
		ft_printf("Split argument %d: %s\n\n", k, ptr[k]);
		while (ptr[k][j])
		{
			ft_printf("Current char: %c\n", ptr[k][j]);
			if (ptr[k][j] < 48 || ptr[k][j] > 57)
			{
				ft_printf("Arguments contain non-number characters\n");
				vec_free(a);
				free_split(ptr);
				return (0);
			}
			j++;
		}
		num = ft_atoi(ptr[k]);
		vec_push(a, &num);
		k++;
	}
	free_split(ptr);
	return (1);
}

int	process_arguments(int argc, const char **argv, t_vec *a)
{
	int		i;
	int		j;
	int		num;
	
	i = 1;
	j = 0;
	if (argc == 2)
	{
		if (!split_arg_string(argv, a))
			return(0);
	}
	else 
	{
		while (i < argc)
		{
			ft_printf("Argument %d: %s\n\n", i, argv[i]);
			j = 0;
			while (j < ft_strlen(argv[i]))
			{
				if (argv[i][j] < 48 || argv[i][j] > 57)
				{
					ft_printf("Arguments contain non-number characters\n");
					vec_free(a);
					return (0);
				}
				j++;
			}
			num = ft_atoi(argv[i]);
			vec_push(a, &num);
			i++;
		}
	}
	return (1);
}

void	print_vector(t_vec *vec)
{
	int	i;
	
	i = 0;
	while (i < vec->len)
	{
		ft_printf("Vector element %d: %d\n", i, *(int *)vec_get(vec, i));
		i++;
	}
}
void	sort_small(t_vec *a)
{
	ft_printf("Vec len is: %d\n", a->len);
	if (a->len == 2)
		if (*(int *)vec_get(a, 0) > *(int *)vec_get(a, 1))
			sa(a);
	else
	{
		if (*(int *)vec_get(a, 0) > *(int *)vec_get(a, 1))
		{
			sa(a);
			//if (*(int *)vec_get(a, 1) > *(int *)vec_get(a, 2))
		}
	}
	
		
}

int	main(int argc, const char **argv)
{
	t_vec	a;
	t_vec	b;
	
	if (argc <= 1)
	{
		ft_printf("\nPlease provide the initial list of numbers\n");
		return (0);
	}

	vec_new(&a, 0, sizeof(int));
	vec_new(&b, 0, sizeof(int));
	
	if (process_arguments(argc, argv, &a))
		ft_printf("\nSuccessfully processed valid arguments\n");
	print_vector(&a);
	if (a.len <= 3)
		sort_small(&a);
	vec_free(&a);
	return (1);
}

