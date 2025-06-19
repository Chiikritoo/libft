/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_node.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:31:29 by anchikri          #+#    #+#             */
/*   Updated: 2025/06/19 11:29:51 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

// function who adds the pointer to the hash table
int	gc_add(t_gc_ctx *ctx, t_gc *node, void *ptr)
{
	unsigned int	index;
	t_gc			*current;
	float			current_load;

	if (!ctx || !node || !ptr)
		return (0);
	current_load = (float)ctx->size / ctx->capacity;
	if (current_load > ctx->load_factor)
		gc_resize(ctx);
	index = gc_hash(ptr, ctx->capacity);
	current = ctx->hashmap[index];
	while (current)
	{
		if (current->ptr == ptr)
			return (0);
		current = current->hash_next;
	}
	node->ptr = ptr;
	node->hash_next = ctx->hashmap[index];
	ctx->hashmap[index] = node;
	ctx->size++;
	return (1);
}
