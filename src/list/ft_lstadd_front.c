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

void	safe_lstadd_front(t_libft *libft, t_lst_ctx *ctx, t_lst *new)
{
	if (!libft)
		return ;
	if (!ctx)
	{
		SET_ERROR(libft->error_ctx, ERROR_INVALID_PARAM, EINVAL,
			"list context is null");
		PRINT_ERROR(libft->error_ctx);
		return ;
	}
	if (!new)
	{
		SET_ERROR(libft->error_ctx, ERROR_INVALID_PARAM, EINVAL,
			"new node is null");
		PRINT_ERROR(libft->error_ctx);
		return ;
	}
	ft_lstadd_front(ctx, new);
}
