/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_reserve.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 23:42:17 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/21 23:42:45 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vector_error	vector_reserve(t_vector *vector, size_t capacity)
{
	t_value	*new_data;

	if (!vector)
	{
		vector->last_error = VECTOR_ERROR_NULL_PTR;
		return (VECTOR_ERROR_NULL_PTR);
	}
	if (capacity <= vector->capacity)
	{
		vector->last_error = VECTOR_SUCCESS;
		return (VECTOR_SUCCESS);
	}
	new_data = ft_realloc(vector->data, 
		vector->capacity * sizeof(t_value), 
		capacity * sizeof(t_value));
	if (!new_data)
	{
		vector->last_error = VECTOR_ERROR_MEMORY_ALLOCATION;
		return (VECTOR_ERROR_MEMORY_ALLOCATION);
	}
	vector->data = new_data;
	vector->capacity = capacity;
	vector->last_error = VECTOR_SUCCESS;
	return (VECTOR_SUCCESS);
} 
