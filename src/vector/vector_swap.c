/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 23:42:17 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/21 23:42:45 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vector_error	vector_swap(t_vector *vector, size_t index1, size_t index2)
{
	t_value	temp;

	if (!vector)
	{
		vector->last_error = VECTOR_ERROR_NULL_PTR;
		return (VECTOR_ERROR_NULL_PTR);
	}
	if (index1 >= vector->size || index2 >= vector->size)
	{
		vector->last_error = VECTOR_ERROR_OUT_OF_BOUNDS;
		return (VECTOR_ERROR_OUT_OF_BOUNDS);
	}
	temp = vector->data[index1];
	vector->data[index1] = vector->data[index2];
	vector->data[index2] = temp;
	vector->last_error = VECTOR_SUCCESS;
	return (VECTOR_SUCCESS);
} 
