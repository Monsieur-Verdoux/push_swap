/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalev <akovalev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:09:31 by akovalev          #+#    #+#             */
/*   Updated: 2024/01/12 16:07:10 by akovalev         ###   ########.fr       */
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
	char	**ptr;
	int		num;
	int		f;
	
	k = 0;
	j = 0;
	ptr = ft_split(argv[1], ' ');
	if (!ptr)
	{
		write(2, "Error\n", 6);
		free_split(ptr);
		return (0);
	}
		
	while (ptr[k])
	{
		j = 0;
		//ft_printf("Split argument %d: %s\n\n", k, ptr[k]);
		while (ptr[k][j])
		{
			//ft_printf("Current char: %c\n", ptr[k][j]);
			if (ptr[k][j] < 48 || ptr[k][j] > 57)
			{
				//ft_printf("Arguments contain non-number characters\n");
				write(2, "Error\n", 6);
				free_split(ptr);
				return (0);
			}
			j++;
		}
		num = ft_atoi(ptr[k]);
		f = 0;
		while (f < a->len)
		{
			if (num == vec_int(a, f))
			{
				free_split(ptr);
				write(2, "Error\n", 6);
				return (0);
			}
			f++;
		}
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
	int		f;

	i = 1;
	j = 0;
	if (argc == 2)
	{
		if (!split_arg_string(argv, a))
		{
			//write(2, "Error\n", 6);
			return (0);
		}
	}
	else
	{
		while (i < argc)
		{
		//	ft_printf("Argument %d: %s\n\n", i, argv[i]);
			j = 0;
			while (j < ft_strlen(argv[i]))
			{
				if (argv[i][j] < 48 || argv[i][j] > 57)
				{
					//ft_printf("Arguments contain non-number characters\n");
					write(2, "Error\n", 6);
					return (0);
				}
				j++;
			}
			num = ft_atoi(argv[i]);
			f = 0;
			while (f < a->len)
			{
				if (num == vec_int(a, f))
				{
					write(2, "Error\n", 6);
					return (0);
				}
				f++;
			}
			vec_push(a, &num);
			i++;
		}
	}
	return (1);
}

void	sort_small(t_vec *a)
{
	if (a->len == 2)
	{
		//ft_printf("Vec len should be 2 and is: %d\n", a->len);
		if (vec_int(a, 0) > vec_int(a, 1))
			sa(a, 1);
	}
	else
	{
		//ft_printf("Vec len should be 3 and is: %d\n", a->len);
		if ((vec_int(a, 0)) > vec_int(a, 1) && vec_int(a, 0) < vec_int(a, 2))
			sa(a, 1);
		else if ((vec_int(a, 0)) < vec_int(a, 1) && vec_int(a, 0) > vec_int(a, 2))
			rra(a, 1);
		else if ((vec_int(a, 0)) > vec_int(a, 2) && vec_int(a, 2) > vec_int(a, 1))
			ra(a, 1);
		else if ((vec_int(a, 0)) < vec_int(a, 1) && vec_int(a, 1) > vec_int(a, 2))
		{
			sa(a, 1);
			ra(a, 1);
		}
		else if ((vec_int(a, 0)) > vec_int(a, 1) && vec_int(a, 1) > vec_int(a, 2))
		{
			sa(a, 1);
			rra(a, 1);
		}			
	}
}

// void	sort_four(t_vec *a, t_vec *b)
// {
// 	pb(a, b);
// 	if (vec_int(b, 1) > vec_int(b, 0))
// 	 	sb(b, 1);
// 	sort_small(a);

// 	if (vec_int(a, 2) > vec_int(b, 0) && vec_int(a, 2) > vec_int(b, 1) && vec_int(b, 1) > vec_int(a, 1))
// 	{
// 		rra(a, 1);
// 		pa(a, b);
// 		pa(a, b);
// 		ra(a, 1);
// 		ra(a, 1);
// 		ra(a, 1);
// 		return ;
// 	}
	
// 	pa(a, b);
// 	if (vec_int(a, 0) > vec_int(a, 1) && vec_int(a, 0) > vec_int(a, 2))
// 	{
// 		if (vec_int(a, 0) > vec_int(a, 3))
// 			ra(a, 1);
// 		else
// 		{
// 			rra(a, 1);
// 			sa(a, 1);
// 			ra(a, 1);
// 			ra(a, 1);				
// 		}
// 	}
// 	else if (vec_int(a, 0) > vec_int(a, 1))
// 		sa(a, 1);
// }

void	sort_five(t_vec *a, t_vec *b)
{
	pb(a, b);
	//sort_four(a, b);
	pb(a, b);
	sort_small(a);
	if (vec_int(b, 1) > vec_int(b, 0))
 	 	sb(b, 1);
	if (vec_int(b, 0) < vec_int(a, 0) && vec_int(b, 1) < vec_int(a, 0))
	{
		pa(a, b);
		pa(a, b);
		return ;
	}
	// if (vec_int(b, 0) > vec_int(a, 2) && vec_int(b, 1) > vec_int(a, 2))
	// {
	// 	pa(a, b);
	// 	pa(a, b);
	// 	ra(a, 1);
	// 	ra(a, 1);
	// 	return ;
	// }
	if (vec_int(b, 0) > vec_int(a, 2))
	{
		pa(a, b);
		while (vec_int(b, 0) < vec_int(a, 3) && vec_int(a, 0) > vec_int(a, 3))
			rra(a, 1);
		pa(a, b);
		while (vec_int(a, 0) > vec_int(a, 3))
			rra(a, 1);
		return ;
	}
	
	while (vec_int(b, 0) > vec_int(a, 0) || vec_int(b, 0) < vec_int(a, 2))
		rra(a, 1);
	pa(a, b);
	while (vec_int(a, 0) > vec_int(a, 3) && (vec_int(b, 0) < vec_int(a, 3)))
		rra(a, 1);
	pa(a, b);
	while (vec_int(a, 0) > vec_int(a, 4))
		rra(a, 1);


		
	// if (vec_int(a, 0) > vec_int(a, 1) && vec_int(a, 0) < vec_int(a, 2))
	// 	sa(a, 1);
	// else if (vec_int(a, 0) > vec_int(a, 2) && vec_int(a, 0) < vec_int(a, 3))
	// {
	// 	sa(a, 1);
	// 	ra(a, 1);
	// 	sa(a, 1);
	// 	rra(a, 1);		
	// }
	// else if (vec_int(a, 0) > vec_int(a, 3) && vec_int(a, 0) < vec_int(a, 4))
	// {
	// 	rra(a, 1);
	// 	sa(a, 1);
	// 	ra(a, 1);
	// 	ra(a, 1);
	// }
	// else if (vec_int(a, 0) > vec_int(a, 4))
	// 	ra(a, 1);
}

int	main(int argc, const char **argv)
{
	t_vec	a;
	t_vec	b;

	if (argc < 2)
	{
		write(2, "Error\n", 6);
		//ft_printf("\nPlease provide the initial list of numbers\n");
		vec_free(&a);
		return (0);
	}
	vec_new(&a, 0, sizeof(int));
	vec_new(&b, 0, sizeof(int));
	if (!process_arguments(argc, argv, &a))
	{
		vec_free(&a);
		return (0);
	}
		//write(2, "Error\n", 6);
		//ft_printf("\nunSuccessfully processed valid arguments\n");
	//print_vector(&a);
	if (a.len <= 3)
		sort_small(&a);
	//if (a.len == 4)
	//	sort_four(&a, &b);
	if (a.len == 5)
		sort_five(&a, &b);
	
	// ft_printf("\nVector a:\n");
	// print_vector(&a);
	// ft_printf("\nVector b:\n");
	// print_vector(&b);
	// ft_printf("\nPushing elements:\n");
	// pb(&a, &b);
	// pb(&a, &b);
	// pb(&a, &b);
	// pb(&a, &b);
	// pa(&a, &b);
	// ft_printf("\nVector a:\n");
	// print_vector(&a);
	// ft_printf("\nVector b:\n");
	// print_vector(&b);
	// ft_printf("\nRotating elements:\n");
	// rr(&a, &b);
	// ft_printf("\nVector a:\n");
	// print_vector(&a);
	// ft_printf("\nVector b:\n");
	// print_vector(&b);
	// ft_printf("\nReverse rotating elements:\n");
	// rrr(&a, &b);
	
	//ft_printf("\nVector a:\n");
	//print_vector(&a);
	//ft_printf("\nVector b:\n");
	//print_vector(&b);
	vec_free(&a);
	vec_free(&b);
	return (1);
}
