/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_subvector.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 23:42:17 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/21 23:42:45 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vector	*vector_subvector(t_vector *vector, size_t start, size_t end)
{
	t_vector	*subvector;
	size_t		i;
	size_t		sub_size;

	if (!vector)
		return (NULL);
	if (start >= vector->size || end > vector->size || start >= end)
		return (NULL);
	sub_size = end - start;
	subvector = vector_new(sub_size);
	if (!subvector)
		return (NULL);
	for (i = 0; i < sub_size; i++)
	{
		if (vector_push_back(subvector, vector->data[start + i]) 
			!= VECTOR_SUCCESS)
		{
			vector_destroy(subvector);
			return (NULL);
		}
	}
	return (subvector);
} 
