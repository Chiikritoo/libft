/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_insert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 23:42:17 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/21 23:42:45 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_vector_error	vector_ensure_capacity(t_vector *vector)
{
	t_value	*new_data;
	size_t	new_capacity;

	if (vector->size < vector->capacity)
		return (VECTOR_SUCCESS);
	new_capacity = vector->capacity * 2;
	if (new_capacity == 0)
		new_capacity = 1;
	new_data = ft_realloc(vector->data, 
		vector->capacity * sizeof(t_value), 
		new_capacity * sizeof(t_value));
	if (!new_data)
	{
		vector->last_error = VECTOR_ERROR_MEMORY_ALLOCATION;
		return (VECTOR_ERROR_MEMORY_ALLOCATION);
	}
	vector->data = new_data;
	vector->capacity = new_capacity;
	return (VECTOR_SUCCESS);
}

t_vector_error	vector_insert(t_vector *vector, size_t index, t_value value)
{
	t_vector_error	result;
	size_t			i;

	if (!vector)
	{
		vector->last_error = VECTOR_ERROR_NULL_PTR;
		return (VECTOR_ERROR_NULL_PTR);
	}
	if (index > vector->size)
	{
		vector->last_error = VECTOR_ERROR_OUT_OF_BOUNDS;
		return (VECTOR_ERROR_OUT_OF_BOUNDS);
	}
	result = vector_ensure_capacity(vector);
	if (result != VECTOR_SUCCESS)
		return (result);
	for (i = vector->size; i > index; i--)
		vector->data[i] = vector->data[i - 1];
	vector->data[index] = value;
	vector->size++;
	vector->last_error = VECTOR_SUCCESS;
	return (VECTOR_SUCCESS);
} 
