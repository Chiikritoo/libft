/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_clear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 00:59:19 by anchikri          #+#    #+#             */
/*   Updated: 2024/08/15 17:54:12 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/garbage.h"

void	gc_clear(t_gc_ctx *ctx)
{
	t_gc	*current;
	t_gc	*next;

	current = ctx->head;
	while (current)
	{
		next = current->next;
		ft_free_ptr((void **)&current->ptr);
		ft_free_ptr((void **)&current);
		current = next;
	}
	ctx->head = NULL;
	ctx->size = 0;
}
