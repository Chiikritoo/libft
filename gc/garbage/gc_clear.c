/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_clear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 00:59:19 by anchikri          #+#    #+#             */
/*   Updated: 2025/06/19 11:28:13 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

// function who clears the garbage collector
void	gc_clear(t_gc_ctx *ctx)
{
	t_gc	*current;
	t_gc	*next;
	int		i;

	if (!ctx)
		return ;
	i = 0;
	while (i < (int)ctx->capacity)
	{
		current = ctx->hashmap[i];
		while (current)
		{
			next = current->hash_next;
			ft_free_ptr((void **)&current->ptr);
			free(current);
			current = next;
		}
		ctx->hashmap[i] = NULL;
		i++;
	}
	ctx->size = 0;
}
