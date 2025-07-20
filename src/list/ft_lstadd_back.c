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

#include "../../include/libft.h"

// function who adds the node 'new' at the end of the list
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

void	safe_lstadd_back(t_libft *libft, t_lst_ctx *ctx, t_lst *new)
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
	ft_lstadd_back(ctx, new);
}
