/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 00:54:26 by anchikri          #+#    #+#             */
/*   Updated: 2025/02/21 19:59:06 by anchikri         ###   ########.fr       */
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
	index = gc_hash(ptr);
	current = ctx->hashmap[index];
	prev = NULL;
	while (current)
	{
		if (current->ptr == ptr)
		{
			if (prev)
				prev->next = current->next;
			else
				ctx->hashmap[index] = current->next;
			ft_free_ptr((void **)&current->ptr);
			current->next = NULL;
			ctx->size--;
			return ;
		}
		prev = current;
		current = current->next;
	}
}
