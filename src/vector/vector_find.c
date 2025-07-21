/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_find.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 23:42:17 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/21 23:42:45 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static bool	vector_value_equal(t_value a, t_value b)
{
	if (a.type != b.type)
		return (false);
	switch (a.type)
	{
		case TYPE_CHAR:
			return (a.as.c == b.as.c);
		case TYPE_STRING:
			return (ft_strcmp(a.as.str, b.as.str) == 0);
		case TYPE_INT:
			return (a.as.i == b.as.i);
		case TYPE_FLOAT:
			return (a.as.f == b.as.f);
		case TYPE_DOUBLE:
			return (a.as.d == b.as.d);
		case TYPE_BOOL:
			return (a.as.b == b.as.b);
		case TYPE_PTR:
			return (a.as.p == b.as.p);
		case TYPE_FUNC:
			return (a.as.func == b.as.func);
		case TYPE_LST_CTX:
			return (a.as.l == b.as.l);
		case TYPE_GC_CTX:
			return (a.as.gc == b.as.gc);
		case TYPE_VECTOR:
			return (a.as.v == b.as.v);
		default:
			return (false);
	}
}

ssize_t	vector_find(t_vector *vector, t_value value)
{
	size_t	i;

	if (!vector)
		return (-1);
	for (i = 0; i < vector->size; i++)
	{
		if (vector_value_equal(vector->data[i], value))
			return (i);
	}
	return (-1);
} 
