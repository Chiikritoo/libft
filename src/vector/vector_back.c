/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_back.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 23:42:17 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/21 23:42:45 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_value	*vector_back(t_vector *vector)
{
	if (!vector)
		return (NULL);
	if (vector->size == 0)
	{
		vector->last_error = VECTOR_ERROR_INVALID_OPERATION;
		return (NULL);
	}
	vector->last_error = VECTOR_SUCCESS;
	return (&vector->data[vector->size - 1]);
} 
