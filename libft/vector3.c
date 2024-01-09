/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalev <akovalev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 18:17:59 by akovalev          #+#    #+#             */
/*   Updated: 2024/01/09 18:50:00 by akovalev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

/*a function vec_reduce which takes as an argument 
a function f applied to each element in the vector. 
Function f takes acc as it's first argument thus we can 
reduce the elements in the vector into one element.*/
int	vec_reduce(void *acc, t_vec *src, void (*f) (void *, void *))
{
	size_t	i;

	if (!acc || !src || !f || !src->memory)
		return (-1);
	i = 0;
	while (i < src->len)
	{
		f(acc, &src->memory[i * src->elem_size]);
		i++;
	}
	return (1);
}

/*a function vec_sort which takes in a function f 
determining order and equality of the two elements 
passed as parameters and thus sorting the array accordingly 
from the smallest to the largest element.*/
void	vec_sort(t_vec *src, int (*f)(void *, void *))
{
	size_t	i;
	int		j;
	int		temp;
	int		*tempptr;

	if (!src || !f || !src->memory)
		return ;
	i = 0;
	j = 0;
	while (i < src->len)
	{
		if (f(vec_get(src, i), &src->memory[(i + 1) * src->elem_size]) > 0)
		{
			temp = *(int *)vec_get(src, i);
			tempptr = &temp;
			vec_remove(src, i);
			vec_insert(src, tempptr, i + 1);
			i = 0;
		}
		else
			i++;
	}
}

// int cmp1(void *a, void *b)
// {
//     return ((long)*(int *)a - *(int *)b);
// }

// int main(void)
// {
//     t_vec   t1;
//     int     base[] = {3, 2, 2, 7, 4};
//     int     expect[] = {2, 2, 3, 4, 7};

//     assert(vec_from(&t1, base, 5, sizeof(int)) > 0);
//     vec_sort(&t1, cmp1);
//     assert(memcmp(t1.memory, expect, sizeof(expect)) == 0);
//     vec_free(&t1);
//     printf("test_vec_sort successful!\n");
// }

// void reduce_tester(void *acc, void *src)
// {
//     *(int *)acc += *(int *)src;
// }

// int main(void)
// {
//     t_vec   t1;
//     int     base[] = {1, 2, 3, 4, 5};
//     int     result = 0;

//     assert(vec_from(&t1, base, 5, sizeof(int)) > 0);
//     vec_reduce(&result, &t1, reduce_tester);
//     assert(result == 15);
//     vec_free(&t1);
//     printf("test_vec_reduce successful!\n");
// }