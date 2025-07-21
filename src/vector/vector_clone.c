/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_clone.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 23:42:17 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/21 23:42:45 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_value	vector_clone_value(t_value value)
{
	t_value	new_value;

	new_value.type = value.type;
	new_value.owned = false;
	switch (value.type)
	{
		case TYPE_STRING:
			if (value.as.str)
				new_value.as.str = ft_strdup(value.as.str);
			else
				new_value.as.str = NULL;
			break;
		case TYPE_PTR:
			new_value.as.p = value.as.p;
			break;
		case TYPE_LST_CTX:
			new_value.as.l = value.as.l;
			break;
		case TYPE_GC_CTX:
			new_value.as.gc = value.as.gc;
			break;
		case TYPE_VECTOR:
			new_value.as.v = value.as.v;
			break;
		default:
			new_value.as = value.as;
			break;
	}
	return (new_value);
}

t_vector	*vector_clone(t_vector *src)
{
	t_vector	*dest;
	size_t		i;

	if (!src)
		return (NULL);
	dest = vector_new(src->capacity);
	if (!dest)
		return (NULL);
	for (i = 0; i < src->size; i++)
	{
		if (vector_push_back(dest, vector_clone_value(src->data[i])) 
			!= VECTOR_SUCCESS)
		{
			vector_destroy(dest);
			return (NULL);
		}
	}
	return (dest);
} 
