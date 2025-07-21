/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_shrink_to_fit.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 23:42:17 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/21 23:42:45 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vector_error	vector_shrink_to_fit(t_vector *vector)
{
	t_value	*new_data;
	size_t	new_capacity;

	if (!vector)
	{
		vector->last_error = VECTOR_ERROR_NULL_PTR;
		return (VECTOR_ERROR_NULL_PTR);
	}
	if (vector->size == vector->capacity)
	{
		vector->last_error = VECTOR_SUCCESS;
		return (VECTOR_SUCCESS);
	}
	new_capacity = (vector->size > 0) ? vector->size : 1;
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
	vector->last_error = VECTOR_SUCCESS;
	return (VECTOR_SUCCESS);
} 
