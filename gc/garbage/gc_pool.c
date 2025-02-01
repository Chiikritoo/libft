/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_pool.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 16:46:52 by anchikri          #+#    #+#             */
/*   Updated: 2025/02/01 04:08:34 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

// function to add a node to the pool
void	gc_pool_add(t_gc_ctx *ctx, t_gc *node)
{
	node->next = ctx->pool;
	ctx->pool = node;
}

// function to get a node from the pool
t_gc	*gc_pool_get(t_gc_ctx *ctx)
{
	t_gc	*node;

	if (!ctx->pool)
		return (NULL);
	node = ctx->pool;
	ctx->pool = ctx->pool->next;
	return (node);
}
