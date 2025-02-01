/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_pool.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 16:46:52 by anchikri          #+#    #+#             */
/*   Updated: 2025/02/01 03:36:37 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

// function who initializes the pool of the garbage collector
void	gc_pool_init(t_pool_ctx *ctx)
{
	size_t	i;
	t_pool	*node;

	ctx->size = POOL_SIZE;
	ctx->free_nodes = ft_calloc(POOL_SIZE, sizeof(t_gc));
	if (!ctx->free_nodes)
		return ;
	node = ctx->free_nodes;
	i = 0;
	while (i < ctx->size - 1)
	{
		node->next = node + 1;
		node = node->next;
		i++;
	}
	node->next = NULL;
}

// function to resize the pool
void	gc_pool_resize(t_pool_ctx *ctx)
{
	size_t	i;
	t_pool	*node;

	ctx->size += POOL_SIZE;
	node = ft_calloc(POOL_SIZE, sizeof(t_gc));
	if (!node)
		return ;
	i = 0;
	while (i < POOL_SIZE - 1)
	{
		node->next = node + 1;
		node = node->next;
		i++;
	}
}

// function to add a node to the pool
void	gc_pool_add(t_pool_ctx *ctx,  t_gc *node)
{
	node->next = ctx->free_nodes;
	ctx->free_nodes = node;
}

// function to get a node from the pool
t_pool	*gc_pool_get(t_pool_ctx *ctx)
{
	t_pool	*node;

	if (ctx->size == 0)
	{
		gc_pool_resize(ctx);
		if (!ctx->free_nodes)
			return (NULL);
	}
	node = ctx
	return (node);
}
