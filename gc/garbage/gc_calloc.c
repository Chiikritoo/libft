/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 01:31:56 by anchikri          #+#    #+#             */
/*   Updated: 2025/01/29 16:59:06 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/garbage.h"

// function who allocates memory and adds it to the garbage collector
void	*gc_calloc(t_gc_ctx *ctx, size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	len;
	t_gc	*node;

	if (!ctx || !nmemb || !size)
		return (NULL);
	len = nmemb * size;
	if (len / size != nmemb)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	node = gc_pool_get(ctx);
	if (!node)
	{
		ft_free_ptr(ptr);
		return (NULL);
	}
	gc_add(ctx, node, ptr);
	return (ptr);
}
