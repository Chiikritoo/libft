/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_find_if.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 23:42:17 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/21 23:42:45 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	vector_find_if(t_vector *vector, t_value value, bool (*cmp)(t_value, t_value))
{
	size_t	i;

	if (!vector || !cmp)
		return (-1);
	for (i = 0; i < vector->size; i++)
	{
		if (cmp(vector->data[i], value))
			return (i);
	}
	return (-1);
} 
