/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 21:07:36 by anchikri          #+#    #+#             */
/*   Updated: 2024/08/13 03:03:38 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

// function who clears the list with the function 'del'
void	ft_lstclear(t_lst_ctx *ctx, void (*del)(void *))
{
	t_lst	*tmp;

	if (!ctx || !del)
		return ;
	while (ctx->head)
	{
		tmp = ctx->head;
		ft_lstdelone(ctx, tmp, del);
	}
	ctx->tail = NULL;
	ctx->size = 0;
}

void	safe_lstclear(t_libft *libft, t_lst_ctx *ctx, void (*del)(void *))
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
	if (!del)
	{
		SET_ERROR(libft->error_ctx, ERROR_INVALID_PARAM, EINVAL,
			"delete function is null");
		PRINT_ERROR(libft->error_ctx);
		return ;
	}
	ft_lstclear(ctx, del);
}
