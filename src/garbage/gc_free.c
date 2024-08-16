/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 00:54:26 by anchikri          #+#    #+#             */
/*   Updated: 2024/08/16 01:59:52 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/garbage.h"

// function who frees a node from the garbage collector
void	gc_free(t_gc_ctx *ctx, void *ptr)
{
	t_gc	*current;
	t_gc	*prev;

	if (!ctx || !ptr)
		return ;
	current = ctx->head;
	prev = NULL;
	while (current)
	{
		if (current->ptr == ptr)
		{
			if (prev)
				prev->next = current->next;
			else
				ctx->head = current->next;
			ft_free_ptr(current->ptr);
			ft_free_ptr(current);
			ctx->size--;
			return ;
		}
		prev = current;
		current = current->next;
	}
}
