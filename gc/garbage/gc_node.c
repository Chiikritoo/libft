/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_node.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:31:29 by anchikri          #+#    #+#             */
/*   Updated: 2025/01/29 17:25:42 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

// function who adds the pointer to the hash table
void	gc_add(t_gc_ctx *ctx, t_gc *node, void *ptr)
{
	unsigned int	index;
	t_gc			*current;

	index = gc_hash(ptr);
	current = ctx->hashmap[index];
	while (current)
	{
		if (current->ptr == ptr)
		{
			ft_free_ptr((void *)node);
			return ;
		}
		current = current->next;
	}
	node->ptr = ptr;
	node->next = ctx->hashmap[index];
	ctx->hashmap[index] = node;
}
