/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 00:54:26 by anchikri          #+#    #+#             */
/*   Updated: 2024/08/15 02:28:01 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

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
			ft_free_ptr((void *)current);
			return ;
		}
		prev = current;
		current = current->next;
	}
}
