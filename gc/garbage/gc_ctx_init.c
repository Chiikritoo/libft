/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_ctx_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 17:58:27 by anchikri          #+#    #+#             */
/*   Updated: 2025/01/29 17:14:28 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/garbage.h"

// function who initializes the pool of the garbage collector
void	gc_pool_init(t_gc_ctx *ctx)
{
	size_t		i;
	t_gc		*node;
	ctx->pool_size = POOL_SIZE;
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
	node->next = NULL;
}

// function who initializes the garbage collector
t_gc_ctx	*gc_ctx_init(void)
{
	t_gc_ctx	*ctx;

	ctx = ft_calloc(1, sizeof(t_gc_ctx));
	if (!ctx)
		return (NULL);
	ft_bzero(ctx->hashmap, sizeof(ctx->hashmap));
	gc_pool_init(ctx);
	if (!ctx->pool)
	{
		ft_free_ptr((void **)&ctx);
		return (NULL);
	}
	return (ctx);
}
