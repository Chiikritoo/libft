/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_resize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 11:21:50 by anchikri          #+#    #+#             */
/*   Updated: 2025/06/19 11:37:28 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

// function who adds a node without checking load factor (for rehashing)
static int	gc_add_no_resize(t_gc_ctx *ctx, t_gc *node, void *ptr)
{
	unsigned int	index;
	t_gc			*current;

	if (!ctx || !node || !ptr)
		return (0);
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

// function who rehashes elements from old table to new table
static void	rehash_elements(t_gc_ctx *ctx, t_gc **old_hashmap,
				size_t old_capacity)
{
	int		i;
	t_gc	*current;
	t_gc	*next;

	i = 0;
	while (i < (int)old_capacity)
	{
		current = old_hashmap[i];
		while (current)
		{
			next = current->hash_next;
			current->hash_next = NULL;
			gc_add_no_resize(ctx, current, current->ptr);
			current = next;
		}
		i++;
	}
}

// function who resizes the hash table when load factor is exceeded
void	gc_resize(t_gc_ctx *ctx)
{
	t_gc	**old_hashmap;
	t_gc	**new_hashmap;
	size_t	old_capacity;
	size_t	new_capacity;

	if (!ctx)
		return ;
	old_hashmap = ctx->hashmap;
	old_capacity = ctx->capacity;
	new_capacity = old_capacity * 2;
	if (new_capacity < old_capacity)
		return ;
	new_hashmap = ft_calloc(new_capacity, sizeof(t_gc *));
	if (!new_hashmap)
		return ;
	ctx->hashmap = new_hashmap;
	ctx->capacity = new_capacity;
	ctx->size = 0;
	rehash_elements(ctx, old_hashmap, old_capacity);
	free(old_hashmap);
}
