/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_for_each.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 23:42:17 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/21 23:42:45 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vector_error	vector_for_each(t_vector *vector, void (*func)(t_value *))
{
	size_t	i;

	if (!vector)
	{
		vector->last_error = VECTOR_ERROR_NULL_PTR;
		return (VECTOR_ERROR_NULL_PTR);
	}
	if (!func)
	{
		vector->last_error = VECTOR_ERROR_INVALID_OPERATION;
		return (VECTOR_ERROR_INVALID_OPERATION);
	}
	for (i = 0; i < vector->size; i++)
		func(&vector->data[i]);
	vector->last_error = VECTOR_SUCCESS;
	return (VECTOR_SUCCESS);
} 
