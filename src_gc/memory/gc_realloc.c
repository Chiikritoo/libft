/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 05:34:51 by anchikri          #+#    #+#             */
/*   Updated: 2024/08/16 02:17:17 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/garbage.h"

// function who reallocates the memory of 'ptr' with the size 'new_size'
void	*gc_realloc(t_gc_ctx *ctx, void *ptr, size_t old_size, size_t new_size)
{
	void	*new;

	if (!ptr)
		return (gc_malloc(ctx, new_size, 1));
	if (!new_size)
	{
		ft_free_ptr(ptr);
		return (NULL);
	}
	new = gc_malloc(ctx, new_size, 1);
	if (!new)
		return (NULL);
	if (old_size < new_size)
		ft_memcpy(new, ptr, old_size);
	else
		ft_memcpy(new, ptr, new_size);
	ft_free_ptr(ptr);
	return (new);
}
