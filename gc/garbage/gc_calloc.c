/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 01:31:56 by anchikri          #+#    #+#             */
/*   Updated: 2025/02/21 19:55:24 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

// function who allocates memory and adds it to the garbage collector
void	*gc_calloc(t_gc_ctx *ctx, size_t nmemb, size_t size)
{
	t_gc	*node;

	if (!ctx)
		return (NULL);
	node = (t_gc *)ft_calloc(1, sizeof(t_gc));
	if (!node)
		return (NULL);
	node->ptr = ft_calloc(nmemb, size);
	if (!node->ptr)
	{
		free(node);
		return (NULL);
	}
	gc_add(ctx, node, node->ptr);
	return (node->ptr);
}
