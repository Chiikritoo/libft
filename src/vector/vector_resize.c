/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_resize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 23:42:17 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/21 23:42:45 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	vector_cleanup_value(t_value *value)
{
	if (!value || !value->owned)
		return ;
	if (value->type == TYPE_STRING && value->as.str)
		free(value->as.str);
	else if (value->type == TYPE_PTR && value->as.p)
		free(value->as.p);
	else if (value->type == TYPE_LST_CTX && value->as.l)
		ft_ctx_destroy(value->as.l);
	else if (value->type == TYPE_GC_CTX && value->as.gc)
		gc_ctx_destroy(value->as.gc);
	else if (value->type == TYPE_VECTOR && value->as.v)
		vector_destroy(value->as.v);
}

t_vector_error	vector_resize(t_vector *vector, size_t new_size, t_value default_value)
{
	t_vector_error	result;
	size_t			i;

	if (!vector)
	{
		vector->last_error = VECTOR_ERROR_NULL_PTR;
		return (VECTOR_ERROR_NULL_PTR);
	}
	if (new_size > vector->capacity)
	{
		result = vector_reserve(vector, new_size);
		if (result != VECTOR_SUCCESS)
			return (result);
	}
	if (new_size < vector->size)
	{
		for (i = new_size; i < vector->size; i++)
			vector_cleanup_value(&vector->data[i]);
	}
	else if (new_size > vector->size)
	{
		for (i = vector->size; i < new_size; i++)
			vector->data[i] = default_value;
	}
	vector->size = new_size;
	vector->last_error = VECTOR_SUCCESS;
	return (VECTOR_SUCCESS);
} 
