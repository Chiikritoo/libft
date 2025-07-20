/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctx_destroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 16:59:04 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/20 02:16:56 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

// function who destroys the list context
void	ft_ctx_destroy(t_lst_ctx *ctx)
{
	if (!ctx)
		return ;
	ft_lstclear(ctx, free);
	free(ctx);
}

void	safe_ctx_destroy(t_libft *libft, t_lst_ctx *ctx)
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
	ft_ctx_destroy(ctx);
}
