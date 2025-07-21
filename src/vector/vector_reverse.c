/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_reverse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 23:42:17 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/21 23:42:45 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vector_error	vector_reverse(t_vector *vector)
{
	size_t	i;
	size_t	j;
	t_value	temp;

	if (!vector)
	{
		vector->last_error = VECTOR_ERROR_NULL_PTR;
		return (VECTOR_ERROR_NULL_PTR);
	}
	for (i = 0, j = vector->size - 1; i < j; i++, j--)
	{
		temp = vector->data[i];
		vector->data[i] = vector->data[j];
		vector->data[j] = temp;
	}
	vector->last_error = VECTOR_SUCCESS;
	return (VECTOR_SUCCESS);
} 
