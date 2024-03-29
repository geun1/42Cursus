/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   darray_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 19:43:35 by yback             #+#    #+#             */
/*   Updated: 2023/03/02 19:43:38 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "darray.h"

extern void		*ft_calloc(size_t nmemb, size_t bytes);

t_darray	*new_darray_malloc(size_t init_capacity)
{
	t_darray	*arr;

	arr = malloc(sizeof(*arr));
	if (arr != NULL)
	{
		arr->size = 0;
		arr->capacity = init_capacity;
		arr->data = new_data_malloc(init_capacity);
		if (arr->data == NULL)
		{
			free(arr);
			arr = NULL;
		}
	}
	return (arr);
}

void	delete_darray(t_darray **arr)
{
	darray_reset(*arr);
	free((*arr)->data);
	(*arr)->data = NULL;
	free(*arr);
	*arr = NULL;
}

void	darray_reset(t_darray *arr)
{
	size_t	idx;

	idx = 0;
	while (idx < arr->size)
	{
		darray_set_data(arr, idx, NULL);
		++idx;
	}
	arr->size = 0;
}

void	darray_set_data(t_darray *arr, size_t index, void *data)
{
	if (arr->data[index] != NULL)
		free(arr->data[index]);
	arr->data[index] = data;
}

void	*new_data_malloc(size_t init_capacity)
{
	void	*data;

	data = ft_calloc(init_capacity, sizeof(size_t));
	return (data);
}
