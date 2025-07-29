/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 20:03:22 by anchikri          #+#    #+#             */
/*   Updated: 2024/08/13 03:03:38 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

// function who adds the node 'new' at the beginning of the list
void	ft_lstadd_front(t_lst_ctx *ctx, t_lst *new)
{
	if (!ctx || !new)
		return ;
	if (!ctx->head)
	{
		ctx->head = new;
		ctx->tail = new;
	}
	else
	{
		new->next = ctx->head;
		ctx->head->prev = new;
		ctx->head = new;
	}
	ctx->size++;
}
