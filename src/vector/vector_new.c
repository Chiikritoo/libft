/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 23:42:17 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/21 23:42:45 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vector	*vector_new(size_t initial_capacity)
{
	t_vector	*vector;

	if (initial_capacity == 0)
		initial_capacity = 1;
	vector = ft_calloc(1, sizeof(t_vector));
	if (!vector)
		return (NULL);
	vector->data = ft_calloc(initial_capacity, sizeof(t_value));
	if (!vector->data)
	{
		free(vector);
		return (NULL);
	}
	vector->size = 0;
	vector->capacity = initial_capacity;
	vector->last_error = VECTOR_SUCCESS;
	return (vector);
} 
