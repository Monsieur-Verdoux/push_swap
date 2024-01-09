/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalev <akovalev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:00:33 by akovalev          #+#    #+#             */
/*   Updated: 2024/01/08 18:59:37 by akovalev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

/*A function vec_append which appends vector src to dst.*/
int	vec_append(t_vec *dst, t_vec *src)
{
	size_t	alloc_size;

	if (!dst || !src || !src->memory || dst->elem_size != src->elem_size)
		return (-1);
	else if (!dst->memory)
		if (vec_new(dst, 1, dst->elem_size) == -1)
			return (-1);
	alloc_size = (dst->len + src->len) * src->elem_size;
	if (dst->alloc_size < alloc_size)
	{
		if (dst->alloc_size * 2 < alloc_size)
		{
			if (vec_resize(dst, dst->len + src->len) == -1)
				return (-1);
		}
		else if (vec_resize(dst, dst->len * 2) == -1)
			return (-1);
	}
	ft_memmove(&dst->memory[dst->elem_size * dst->len], \
		src->memory, src->elem_size * src->len);
	dst->len += src->len;
	return (1);
}

/*A function vec_prepend which prepends vector src to dst.*/
int	vec_prepend(t_vec *dst, t_vec *src)
{
	size_t	alloc_size;

	if (!dst || !src || !src->memory || dst->elem_size != src->elem_size)
		return (-1);
	else if (!dst->memory)
		vec_new(dst, 1, dst->elem_size);
	alloc_size = (dst->len + src->len) * src->elem_size;
	if (dst->alloc_size < alloc_size)
	{
		if (dst->alloc_size * 2 < alloc_size)
		{
			if (vec_resize(dst, alloc_size / dst->elem_size) == -1)
				return (-1);
		}
		else if (vec_resize(dst, dst->len * 2) == -1)
			return (-1);
	}
	ft_memmove(&dst->memory[dst->elem_size * src->len], \
		dst->memory, dst->elem_size * dst->len);
	ft_memmove(dst->memory, src->memory, src->elem_size * src->len);
	dst->len += src->len;
	return (1);
}

/*A function vec_iter which takes as an 
argument a function f applied to each element in the vector.*/
void	vec_iter(t_vec *src, void (*f) (void *))
{
	size_t	i;

	if (!src || !f || src->memory)
		return ;
	i = 0;
	while (i < src->len)
	{
		f(&src->memory[src->elem_size * i]);
		i++;
	}
}

/* A function vec_map which takes as an argument 
a function f applied to a copy of each element in 
the vector. The copied element will be added to vector dst.*/
void	vec_map(t_vec *dst, t_vec *src, void (*f) (void *))
{
	void	*ptr;
	void	*res;
	size_t	i;

	if (!src || !dst || !f || !src->memory)
		return ;
	else if (!dst->memory)
		if (vec_new(dst, 1, dst->elem_size) == -1)
			return ;
	res = malloc(dst->elem_size);
	if (!res)
		return ;
	i = 0;
	while (i < src->len)
	{
		ptr = vec_get(src, i);
		ft_memmove(res, ptr, dst->elem_size);
		f(res);
		vec_push(dst, res);
		i++;
	}
	free(res);
}
//ask Ryan why first copy

/*a function vec_filter which takes as an argument 
a function f applied to a copy of each element in 
the vector. The copied element will be added to vector 
dst if true is returned from f.*/
int	vec_filter(t_vec *dst, t_vec *src, bool (*f) (void *))
{
	void	*ptr;
	void	*res;
	size_t	i;

	if (!src || !dst || !f || !src->memory)
		return (-1);
	else if (!dst->memory)
		if (vec_new(dst, 1, dst->elem_size) == -1)
			return (-1);
	res = malloc(dst->elem_size);
	if (!res)
		return (-1);
	i = 0;
	while (i < src->len)
	{
		ptr = vec_get(src, i);
		ft_memmove(res, ptr, dst->elem_size);
		if (f(res) == true)
			vec_push(dst, res);
		i++;
	}
	free(res);
	return (1);
}
//ask Ryan about his implementation

// bool filter_tester(void *src)
// {
//     if (*(int *)src % 2 == 0)
//         return (true);
//     return (false);
// }

// int main(void)
// {
//     t_vec   t1;
//     t_vec   t2;
//     int     base[] = {1, 2, 3, 4, 5};
//     int     expect[] = {2, 4};

//     assert(vec_from(&t1, base, 5, sizeof(int)) > 0);
//     assert(vec_new(&t2, 5, sizeof(int)) > 0);
//     vec_filter(&t2, &t1, filter_tester);
//     assert(memcmp(t2.memory, expect, sizeof(expect)) == 0);
//     vec_free(&t1);
//     vec_free(&t2);
//     printf("test_vec_filter successful!\n");
// }
//note: Ryan first adds then applies, while subject says otherwise, check

// void map_tester(void *src)
// {
//     *(int *)src += 1;
// }

// int main(void)
// {
//     t_vec   t1;
//     t_vec   t2;
//     int     base[] = {1, 2, 3, 4, 5};
//     int     expect[] = {2, 3, 4, 5, 6};

//     assert(vec_from(&t1, base, 5, sizeof(int)) > 0);
//     assert(vec_new(&t2, 5, sizeof(int)) > 0);
//     vec_map(&t2, &t1, map_tester);
//     assert(memcmp(t2.memory, expect, sizeof(expect)) == 0);
//     vec_free(&t1);
//     vec_free(&t2);
//     printf("test_vec_map successful!\n");
// }

// void iter_tester(void *src)
// {
//     *(int *)src += 1;
// }

// int main(void)
// {
//     t_vec   t1;
//     int     base[] = {1, 2, 3, 4, 5};
//     int     expect[] = {2, 3, 4, 5, 6};

//     assert(vec_from(&t1, base, 5, sizeof(int)) > 0);
//     vec_iter(&t1, iter_tester);
//     assert(memcmp(t1.memory, expect, sizeof(expect)) == 0);
//     vec_free(&t1);
//     printf("test_vec_iter successful!\n");
// }

// int main(void)
// {
//     t_vec   t1;
//     t_vec   t2;
//     int     base1[] = {1, 2, 3};
//     int     base2[] = {4, 5, 6};
//     int     expect[] = {4, 5, 6, 1, 2, 3};

//     assert(vec_from(&t1, base1, 3, sizeof(int)) > 0);
//     assert(vec_from(&t2, base2, 3, sizeof(int)) > 0);
//     assert(vec_prepend(&t1, &t2) > 0);
//     assert(memcmp(t1.memory, expect, sizeof(expect)) == 0);
//     vec_free(&t1);
//     vec_free(&t2);
//     printf("test_vec_prepend successful!\n");
// }
// int main(void)
// {
//     t_vec   t1;
//     t_vec   t2;
//     int     base1[] = {1, 2, 3};
//     int     base2[] = {4, 5, 6, 7};
//     int     expect[] = {1, 2, 3, 4, 5, 6, 7};

//     assert(vec_from(&t1, base1, 3, sizeof(int)) > 0);
//     assert(vec_from(&t2, base2, 4, sizeof(int)) > 0);
// 	ft_printf("len: %d\n", t1.len);
// 	ft_printf("size: %d\n", t1.alloc_size);
//     assert(vec_append(&t1, &t2) > 0);
// 	ft_printf("len: %d\n", t1.len);
// 	ft_printf("size: %d\n", t1.alloc_size);
// 	ft_printf("last: %d\n", t1.memory[t1.len * t1.elem_size - 4]);
//     assert(memcmp(t1.memory, expect, sizeof(expect)) == 0);
//     vec_free(&t1);
//     vec_free(&t2);
//     printf("test_vec_append successful!\n");
// }