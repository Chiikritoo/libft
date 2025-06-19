/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 00:54:26 by anchikri          #+#    #+#             */
/*   Updated: 2025/06/19 11:29:51 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

// function who frees a node from the garbage collector
void	gc_free(t_gc_ctx *ctx, void *ptr)
{
	int		index;
	t_gc	*current;
	t_gc	*prev;

	if (!ctx || !ptr)
		return ;
	index = gc_hash(ptr, ctx->capacity);
	current = ctx->hashmap[index];
	prev = NULL;
	while (current)
	{
		if (current->ptr == ptr)
		{
			if (prev)
				prev->hash_next = current->hash_next;
			else
				ctx->hashmap[index] = current->hash_next;
			ft_free_ptr((void **)&current->ptr);
			free(current);
			ctx->size--;
			return ;
		}
		prev = current;
		current = current->hash_next;
	}
}
