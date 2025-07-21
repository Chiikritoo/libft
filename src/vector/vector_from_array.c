/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_from_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 23:42:17 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/21 23:42:45 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vector	*vector_from_array(t_value *values, size_t count)
{
	t_vector	*vector;
	size_t		i;

	if (!values)
		return (NULL);
	vector = vector_new(count);
	if (!vector)
		return (NULL);
	for (i = 0; i < count; i++)
	{
		if (vector_push_back(vector, values[i]) != VECTOR_SUCCESS)
		{
			vector_destroy(vector);
			return (NULL);
		}
	}
	return (vector);
} 
