/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalev <akovalev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 18:16:14 by akovalev          #+#    #+#             */
/*   Updated: 2024/01/08 17:21:22 by akovalev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

/*A function vec_push which takes in a vector and a 
pointer to an element to be pushed to the end of the vector.*/
int	vec_push(t_vec *dst, void *src)
{
	if (!dst || !src)
		return (-1);
	else if (!dst->memory)
		if (vec_new(dst, 1, dst->elem_size) == -1)
			return (-1);
	if (dst->elem_size * dst->len >= dst->alloc_size)
		if (vec_resize(dst, dst->len * 2) < 0)
			return (-1);
	ft_memmove(&dst->memory[dst->len * dst->elem_size], src, dst->elem_size);
	dst->len++;
	return (1);
}

/*A function vec_pop which will remove the last 
element from the vector and copy it to dst.*/
int	vec_pop(void *dst, t_vec *src)
{
	if (!dst || !src || !src->memory)
		return (-1);
	ft_memmove(dst, &src->memory[src->elem_size * (src->len - 1)], \
		src->elem_size);
	src->len--;
	return (1);
}
//ask Ryan why else if	(!src->memory || src->len == 0)		return (0);

/* A function vec_get which returns an opaque handle to the element at index*/
void	*vec_get(t_vec *src, size_t index)
{
	if (!src || index >= src->len || !src->memory)
		return (NULL);
	return (&(src->memory[src->elem_size * index]));
}

/*A function vec_insert which will insert 
a new element at any position in the vector
without overwriting existing elements.*/
int	vec_insert(t_vec *dst, void *src, size_t index)
{
	if (!dst || !src || index > dst->len)
		return (-1);
	else if (index == dst->len)
		return (vec_push(dst, src));
	if (dst->elem_size * dst->len >= dst->alloc_size)
		if (vec_resize(dst, dst->len * 2) < 0)
			return (-1);
	ft_memmove(vec_get(dst, index) + dst->elem_size, \
		vec_get(dst, index), (dst->len - index) * dst->elem_size);
	ft_memcpy(vec_get(dst, index), src, dst->elem_size);
	dst->len++;
	return (1);
}

/*A function vec_remove which will remove 
an element from any position in the vector 
without overwriting existing elements.*/
int	vec_remove(t_vec *src, size_t index)
{
	if (!src || index > src->len)
		return (-1);
	if (index != src->len)
		ft_memmove(vec_get(src, index), vec_get(src, index) + src->elem_size, \
			(src->len - index) * src->elem_size);
	src->len--;
	return (1);
}

// int main(void)
// {
//     t_vec   t1;
//     int     base[] = {1, 2, 3, 4, 5};
//     int     insert[] = {42, 666, 7};

//     assert(vec_from(&t1, base, 5, sizeof(int)) > 0);
//     vec_insert(&t1, &insert[0], 1);
//     vec_insert(&t1, &insert[1], 4);
//     vec_insert(&t1, &insert[2], 7);
//     vec_remove(&t1, 1);
//     vec_remove(&t1, 3);
//     vec_remove(&t1, 5);
//     assert(memcmp(t1.memory, base, sizeof(base)) == 0);
//     vec_free(&t1);
//     printf("test_vec_remove successful!\n");
// }

// int main(void)
// {
//     t_vec   t1;
//     int     base[] = {1, 2, 3, 4, 5};
//     int     insert[] = {42, 666, 7};
//     int     expect[] = {1, 42, 2, 3, 666, 4, 5, 7};

//     assert(vec_from(&t1, base, 5, sizeof(int)) > 0);
//     vec_insert(&t1, &insert[0], 1);
//     vec_insert(&t1, &insert[1], 4);
//     vec_insert(&t1, &insert[2], 7);
//     assert(memcmp(t1.memory, expect, sizeof(expect)) == 0);
//     vec_free(&t1);
//     printf("test_vec_insert successful!\n");
// }

// int main(void)
// {
//     t_vec   t1;
//     int     base[] = {1, 2, 3, 4, 5};
//     int     *expect;

//     assert(vec_new(&t1, 1, sizeof(int)) > 0);
//     vec_push(&t1, &base[1]);
//     vec_push(&t1, &base[3]);
//     expect = vec_get(&t1, 0);
//     assert(*expect == 2);
//     expect = vec_get(&t1, 1);
//     assert(*expect == 4);
//     assert(t1.len == 2);
//     vec_free(&t1);
//     printf("test_vec_get successful!\n");
// }

// int main(void)
// {
//     t_vec   t1;
//     int     base[] = {1, 2, 3, 4, 5};
//     int     expect = 0;

//     assert(vec_new(&t1, 1, sizeof(int)) > 0);
//     vec_push(&t1, &base[1]);
//     vec_push(&t1, &base[3]);
//     vec_pop(&expect, &t1);
//     assert(expect == 4);
//     vec_pop(&expect, &t1);
//     assert(expect == 2);
//     assert(t1.len == 0);
//     vec_free(&t1);
//     printf("test_vec_pop successful!\n");
// }

// int main(void)
// {
//     t_vec   t1;
//     int     base[] = {1, 2, 3, 4, 5};
//     int     expect[] = {2, 4};

//     assert(vec_new(&t1, 1, sizeof(int)) > 0);
//     vec_push(&t1, &base[1]);
// 	ft_printf("dst el: %d\n", t1.memory[t1.len * t1.elem_size - 4]);
//     vec_push(&t1, &base[3]);
// 	ft_printf("dst el: %d\n", t1.memory[t1.len * t1.elem_size - 4]);
//     assert(memcmp(t1.memory, expect, sizeof(expect)) == 0);
//     vec_free(&t1);
//     printf("test_vec_push successful!\n");
// }