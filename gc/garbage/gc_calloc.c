/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 01:31:56 by anchikri          #+#    #+#             */
/*   Updated: 2025/02/01 04:35:38 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

// function who allocates memory and adds it to the garbage collector as temporary
void	*gc_calloc_temporary(t_gc_ctx *ctx, size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = gc_calloc(ctx, nmemb, size);
	if (!ptr)
		return (NULL);
	((t_gc *)ptr)->temporary = true;
	return (ptr);
}

// function who allocates memory and adds it to the garbage collector
void	*gc_calloc(t_gc_ctx *ctx, size_t nmemb, size_t size)
{
	t_gc	*node;

	if (!ctx)
		return (NULL);
	if (!ctx->pool)
	{
		node = ft_calloc(1, sizeof(t_gc));
		if (!node)
			return (NULL);
	}
	else
	{
		node = gc_pool_get(ctx);
		if (!node)
			return (NULL);
	}
	if (!node->ptr)
	{
		node->ptr = ft_calloc(nmemb, size);
		if (!node->ptr)
		{
			gc_pool_add(ctx, node);
			return (NULL);
		}
	}
	node->temporary = false;
	if (!gc_add(ctx, node, node->ptr))
	{
		if (!ctx->pool)
			ft_free_ptr(&node->ptr);
		gc_pool_add(ctx, node);
		return (NULL);
	}
	return (node->ptr);
}
