/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_alloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 01:31:56 by anchikri          #+#    #+#             */
/*   Updated: 2024/08/15 02:37:02 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	*gc_alloc(t_gc_ctx *ctx, size_t nmemb, size_t size)
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
		free(ptr);
		return (NULL);
	}
	node->ptr = ptr;
	node->next = ctx->head;
	ctx->head = node;
	return (ptr);
}
