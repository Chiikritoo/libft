/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_pop_back.c                                   :+:      :+:    :+:   */
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

t_vector_error	vector_pop_back(t_vector *vector)
{
	if (!vector)
	{
		vector->last_error = VECTOR_ERROR_NULL_PTR;
		return (VECTOR_ERROR_NULL_PTR);
	}
	if (vector->size == 0)
	{
		vector->last_error = VECTOR_ERROR_INVALID_OPERATION;
		return (VECTOR_ERROR_INVALID_OPERATION);
	}
	vector_cleanup_value(&vector->data[vector->size - 1]);
	vector->size--;
	vector->last_error = VECTOR_SUCCESS;
	return (VECTOR_SUCCESS);
} 
