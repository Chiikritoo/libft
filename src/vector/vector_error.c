/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 23:42:17 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/21 23:42:45 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

const char	*vector_error_string(t_vector_error error)
{
	switch (error)
	{
		case VECTOR_SUCCESS:
			return ("Success");
		case VECTOR_ERROR_NULL_PTR:
			return ("Null pointer error");
		case VECTOR_ERROR_OUT_OF_BOUNDS:
			return ("Index out of bounds");
		case VECTOR_ERROR_TYPE_MISMATCH:
			return ("Type mismatch");
		case VECTOR_ERROR_MEMORY_ALLOCATION:
			return ("Memory allocation failed");
		case VECTOR_ERROR_INVALID_OPERATION:
			return ("Invalid operation");
		default:
			return ("Unknown error");
	}
}

void	vector_clear_error(t_vector *vector)
{
	if (vector)
		vector->last_error = VECTOR_SUCCESS;
}

t_vector_error	vector_get_last_error(t_vector *vector)
{
	if (!vector)
		return (VECTOR_ERROR_NULL_PTR);
	return (vector->last_error);
} 
