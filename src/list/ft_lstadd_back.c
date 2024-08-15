/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 20:33:37 by anchikri          #+#    #+#             */
/*   Updated: 2024/08/13 03:03:38 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/list.h"

void	ft_lstadd_back(t_lst_ctx *ctx, t_lst *new)
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
		ctx->tail->next = new;
		new->prev = ctx->tail;
		ctx->tail = new;
	}
	ctx->size++;
}
