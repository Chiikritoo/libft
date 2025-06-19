/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_ctx_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 17:58:27 by anchikri          #+#    #+#             */
/*   Updated: 2025/06/19 11:26:39 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

// function who initializes the garbage collector
t_gc_ctx	*gc_ctx_init(void)
{
	t_gc_ctx	*ctx;

	ctx = ft_calloc(1, sizeof(t_gc_ctx));
	if (!ctx)
		return (NULL);
	ctx->hashmap = ft_calloc(HASH_SIZE, sizeof(t_gc *));
	if (!ctx->hashmap)
	{
		free(ctx);
		return (NULL);
	}
	ctx->capacity = HASH_SIZE;
	ctx->size = 0;
	ctx->load_factor = 0.75f;
	return (ctx);
}
