/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 23:42:17 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/21 23:42:45 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	vector_quick_sort(t_value *data, size_t low, size_t high, 
				int (*cmp)(t_value, t_value))
{
	size_t	pivot;
	size_t	i;
	size_t	j;
	t_value	temp;

	if (low < high)
	{
		pivot = low;
		i = low;
		j = high;
		while (i < j)
		{
			while (cmp(data[i], data[pivot]) <= 0 && i < high)
				i++;
			while (cmp(data[j], data[pivot]) > 0)
				j--;
			if (i < j)
			{
				temp = data[i];
				data[i] = data[j];
				data[j] = temp;
			}
		}
		temp = data[pivot];
		data[pivot] = data[j];
		data[j] = temp;
		if (j > 0)
			vector_quick_sort(data, low, j - 1, cmp);
		vector_quick_sort(data, j + 1, high, cmp);
	}
}

t_vector_error	vector_sort(t_vector *vector, int (*cmp)(t_value, t_value))
{
	if (!vector)
	{
		vector->last_error = VECTOR_ERROR_NULL_PTR;
		return (VECTOR_ERROR_NULL_PTR);
	}
	if (!cmp)
	{
		vector->last_error = VECTOR_ERROR_INVALID_OPERATION;
		return (VECTOR_ERROR_INVALID_OPERATION);
	}
	if (vector->size > 1)
		vector_quick_sort(vector->data, 0, vector->size - 1, cmp);
	vector->last_error = VECTOR_SUCCESS;
	return (VECTOR_SUCCESS);
} 
