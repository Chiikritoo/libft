/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 01:31:56 by anchikri          #+#    #+#             */
/*   Updated: 2024/08/16 01:59:58 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/garbage.h"

// function who allocates memory and adds it to the garbage collector
void	*gc_malloc(t_gc_ctx *ctx, size_t nmemb, size_t size)
{
	void	*ptr;
	t_gc	*node;

	if (!ctx)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	node = malloc(sizeof(t_gc));
	if (!node)
	{
		ft_free_ptr(ptr);
		return (NULL);
	}
	node->ptr = ptr;
	node->next = ctx->head;
	ctx->head = node;
	ctx->size++;
	return (ptr);
}
