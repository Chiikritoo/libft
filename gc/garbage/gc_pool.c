/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_pool.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 16:46:52 by anchikri          #+#    #+#             */
/*   Updated: 2025/01/29 17:03:29 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/garbage.h"

// function to resize the pool
void	gc_pool_resize(t_gc_ctx *ctx)
{
	int		i;
	t_gc	*node;

	ctx->pool_size = POOL_SIZE * 2;
	ctx->pool = gc_calloc(ctx, ctx->pool_size, sizeof(t_gc));
	if (!ctx->pool)
		return ;
	node = ctx->pool;
	i = 0;
	while (i < ctx->pool_size - 1)
	{
		node->next = node + 1;
		node = node->next;
		i++;
	}
}

// function to add a node to the pool
void	gc_pool_add(t_gc_ctx *ctx, t_gc *node)
{
	node->next = ctx->pool;
	ctx->pool = node;
	ctx->pool_size++;
}

// function to get a node from the pool
t_gc	*gc_pool_get(t_gc_ctx *ctx)
{
	t_gc	*node;

	if (ctx->pool_size == 0)
	{
		gc_pool_resize(ctx);
		if (!ctx->pool)
			return (NULL);
	}
	node = ctx->pool;
	ctx->pool = ctx->pool->next;
	ctx->pool_size--;
	return (node);
}
