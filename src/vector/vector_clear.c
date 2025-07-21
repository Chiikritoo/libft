/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_clear.c                                      :+:      :+:    :+:   */
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

void	vector_clear(t_vector *vector)
{
	size_t	i;

	if (!vector)
		return ;
	for (i = 0; i < vector->size; i++)
		vector_cleanup_value(&vector->data[i]);
	vector->size = 0;
	vector->last_error = VECTOR_SUCCESS;
} 
