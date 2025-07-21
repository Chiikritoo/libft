/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_at.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 23:42:17 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/21 23:42:45 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_value	*vector_at(t_vector *vector, size_t index)
{
	if (!vector)
		return (NULL);
	if (index >= vector->size)
	{
		vector->last_error = VECTOR_ERROR_OUT_OF_BOUNDS;
		return (NULL);
	}
	vector->last_error = VECTOR_SUCCESS;
	return (&vector->data[index]);
} 
