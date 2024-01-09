/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalev <akovalev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:22:38 by akovalev          #+#    #+#             */
/*   Updated: 2024/01/08 17:21:18 by akovalev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

/*A function vec_new which will take a pointer to 
a t_vec and allocate len * elem_size bytes in 
the buffer as well as initialize its length and element size.*/
int	vec_new(t_vec *dst, size_t init_len, size_t elem_size)
{
	if (!dst || elem_size == 0)
		return (-1);
	dst->len = 0;
	dst->elem_size = elem_size;
	dst->alloc_size = init_len * elem_size;
	if (init_len == 0)
		dst->memory = NULL;
	else
	{
		dst->memory = malloc(dst->alloc_size);
		if (!dst->memory)
			return (-1);
	}
	return (1);
}

/*A function vec_free that frees the allocated 
resources in src and zeroes its fields.*/
void	vec_free(t_vec *src)
{
	if (!src)
		return ;
	free(src->memory);
	src->memory = NULL;
	src->alloc_size = 0;
	src->elem_size = 0;
	src->len = 0;
}
//why does the original also has if (!src || src->alloc_size == 0) 
//check? Also, should there be if (!src->memory) check?

/*A function vec_from which takes in a pointer to some
 memory, which then will be copied over to the new vector.*/
int	vec_from(t_vec *dst, void *src, size_t len, size_t elem_size)
{
	if (!dst || elem_size == 0 || !src)
		return (-1);
	if (vec_new(dst, len, elem_size) == -1)
		return (-1);
	ft_memmove(dst->memory, src, dst->alloc_size);
	dst->len = len;
	return (1);
}

/*The vec_copy function is very simple and will only copy 
at most as many bytes as are available in the dst vector*/
int	vec_copy(t_vec *dst, t_vec *src)
{
	size_t	copy_size;

	if (!src || !dst || !src->memory)
		return (-1);
	else if (!dst->memory)
		if (vec_new(dst, src->len, dst->elem_size) == -1)
			return (-1);
	if (src->len * src->elem_size < dst->alloc_size)
		copy_size = src->len * src->elem_size;
	else
		copy_size = dst->alloc_size;
	ft_printf("dst: %d, src: %d\n", dst->alloc_size, src->alloc_size);
	if (!ft_memmove(dst->memory, src->memory, copy_size))
		return (-1);
	dst->len = copy_size / dst->elem_size;
	return (1);
}

/*A function vec_resize which will take in a 
target_size parameter and either shrink (destructively)
 or grow the vector to the target size, 
 copying the old contents over to the new allocation.*/
int	vec_resize(t_vec *src, size_t target_len)
{
	unsigned char	*temp;

	if (!src)
		return (-1);
	else if (!src->memory)
		return (vec_new(src, target_len, src->elem_size));
	src->alloc_size = target_len * src->elem_size;
	temp = src->memory;
	src->memory = malloc(src->alloc_size);
	if (!src->memory)
		return (-1);
	if (ft_memmove(src->memory, temp, src->len * src->elem_size) == NULL)
		return (-1);
	free(temp);
	temp = NULL;
	return (1);
}

//note: ask Ryan why -1 in case of !src->memory, also 
//using size over len is a conscious choice
//also memmove 3rd parameter, also temp=null

// int main(void)
// {
//     t_vec   t1;
//     int     base[] = {1, 2, 3, 4, 5};

//     assert(vec_from(&t1, base, 5, sizeof(int)) > 0);
// 	ft_printf("dst: %d\n", t1.alloc_size);
// 	ft_printf("dst alloc siez: %d\n", t1.alloc_size);
// 	ft_printf("dst elem size: %d\n", t1.elem_size);
// 	ft_printf("dst len: %d\n", t1.len);
//     assert(vec_resize(&t1, 100) > 0);
//     assert(memcmp(t1.memory, base, sizeof(base)) == 0);
// 	ft_printf("dst: %d\n", *t1.memory);
//  	ft_printf("dst: %d\n", *(t1.memory + t1.elem_size));
//  	ft_printf("dst: %d\n", *(t1.memory + t1.elem_size * 2));
//  	ft_printf("dst: %d\n", *(t1.memory + t1.elem_size * 3));
//  	ft_printf("dst: %d\n", *(t1.memory + t1.elem_size * 4));
// 	ft_printf("dst alloc siez: %d\n", t1.alloc_size);
// 	ft_printf("dst elem size: %d\n", t1.elem_size);
// 	ft_printf("dst len: %d\n", t1.len);
//     vec_free(&t1);
//     printf("test_vec_resize successful!\n");
// }

// int main(void)
// {
//     t_vec   t1;
//     t_vec   t2;
// 	size_t n = 4;
//     int     base[] = {1, 2, 3, 4, 5};

//     assert(vec_from(&t1, base, 5, sizeof(int)) > 0);
//     assert(vec_new(&t2, n, sizeof(int)) > 0);
//     assert(vec_copy(&t2, &t1) > 0);
//     assert(memcmp(t2.memory, base, n) == 0);
// 	ft_printf("dst: %d\n", *t2.memory);
// 	ft_printf("dst: %d\n", *(t2.memory + t1.elem_size));
// 	ft_printf("dst: %d\n", *(t2.memory + t1.elem_size * 2));
// 	ft_printf("dst: %d\n", *(t2.memory + t1.elem_size * 3));
// 	ft_printf("dst: %d\n", *(t2.memory + t1.elem_size * 4));
//     vec_free(&t1);
//     vec_free(&t2);
//     printf("test_vec_copy successful!\n");
// }

// int main(void)
// {
//     t_vec   t1;
//     int     base[] = {1, 2, 3, 4, 5};

//     assert(vec_from(&t1, base, 5, sizeof(int)) > 0);
//     assert(memcmp(t1.memory, base, sizeof(base)) == 0);
//     vec_free(&t1);
//     printf("test_vec_from successful!\n");
// }

// int main(void)
// {
//     t_vec t1;

//     assert(vec_new(&t1, 0, 0) == -1);
//     assert(vec_new(&t1, 0, 1) > 0);
//     assert(t1.memory == NULL);
//     assert(vec_new(&t1, 1, 0) == -1);
//     assert(vec_new(&t1, 10, 1) > 0);
//     assert(t1.memory != NULL);
//     vec_free(&t1);
//     printf("test_vec_new successful!\n");
// }

// int main(void)
// {
//     t_vec t1;

//     assert(vec_new(&t1, 10, 1) > 0);
//     vec_free(&t1);
//     assert(t1.len == 0);
//     assert(t1.alloc_size == 0);
//     assert(t1.elem_size == 0);
//     assert(t1.memory == NULL);
//     printf("test_vec_free successful!\n");
// }

//old resize:

// int	vec_resize(t_vec *src, size_t target_size)
// {
// 	unsigned char	*temp;

// 	if (!src || target_size < 0)
// 		return (-1);
// 	else if (!src->memory)
// 		return (vec_new(src, target_size / src->elem_size, src->elem_size));
// 	src->alloc_size = target_size;
// 	temp = src->memory;
// 	src->memory = malloc(src->alloc_size);
// 	if (!temp)
// 		return (-1);
// 	if (!ft_memmove(src->memory, temp, src->len * src->elem_size))
// 		return (-1);
// 	free(temp);
// 	temp = NULL;
// 	return (1);
// }