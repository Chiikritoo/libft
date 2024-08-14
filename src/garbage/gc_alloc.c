/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_alloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 01:31:56 by anchikri          #+#    #+#             */
/*   Updated: 2024/08/15 01:28:31 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	*gc_alloc(t_gc_context *ctx, size_t nmemb, size_t size)
{
	void		*ptr;
	t_garbage	*node;

	if (!ctx || !nmemb || !size)
		return (NULL);
	ptr = ft_calloc(nmemb, size);
	if (!ptr)
		return (NULL);
	node = ft_calloc(1, sizeof(t_garbage));
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
