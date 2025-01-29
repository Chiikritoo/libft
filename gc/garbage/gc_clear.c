/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_clear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 00:59:19 by anchikri          #+#    #+#             */
/*   Updated: 2025/01/29 17:00:39 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/garbage.h"

// function who clears the garbage collector
void	gc_clear(t_gc_ctx *ctx)
{
	t_gc	*current;
	t_gc	*next;
	int		i;

	i = 0;
	while (i < HASH_SIZE)
	{
		current = ctx->hashmap[i];
		while (current)
		{
			next = current->next;
			ft_free_ptr((void *)&current->ptr);
			ft_free_ptr((void *)current);
			current = next;
		}
		ctx->hashmap[i] = NULL;
		i++;
	}
}
