/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_concat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 23:42:17 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/21 23:42:45 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vector_error	vector_concat(t_vector *dest, t_vector *src)
{
	size_t	i;

	if (!dest || !src)
	{
		if (dest)
			dest->last_error = VECTOR_ERROR_NULL_PTR;
		return (VECTOR_ERROR_NULL_PTR);
	}
	for (i = 0; i < src->size; i++)
	{
		if (vector_push_back(dest, src->data[i]) != VECTOR_SUCCESS)
			return (dest->last_error);
	}
	dest->last_error = VECTOR_SUCCESS;
	return (VECTOR_SUCCESS);
} 
