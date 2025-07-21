/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterators.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 23:42:17 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/21 23:42:45 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vector_iter	vector_begin(t_vector *vector)
{
	t_vector_iter	iter;

	iter.vector = vector;
	iter.index = 0;
	iter.valid = (vector != NULL && vector->size > 0);
	return (iter);
}

t_vector_iter	vector_end(t_vector *vector)
{
	t_vector_iter	iter;

	iter.vector = vector;
	iter.index = (vector ? vector->size : 0);
	iter.valid = false;
	return (iter);
}

bool	vector_iter_next(t_vector_iter *iter)
{
	if (!iter || !iter->vector)
		return (false);
	iter->index++;
	iter->valid = (iter->index < iter->vector->size);
	return (iter->valid);
}

t_value	*vector_iter_get(t_vector_iter *iter)
{
	if (!iter || !iter->vector || !iter->valid)
		return (NULL);
	if (iter->index >= iter->vector->size)
		return (NULL);
	return (&iter->vector->data[iter->index]);
}

bool	vector_iter_valid(t_vector_iter *iter)
{
	return (iter && iter->valid);
} 
