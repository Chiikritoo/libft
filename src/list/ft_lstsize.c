/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 20:18:37 by anchikri          #+#    #+#             */
/*   Updated: 2024/08/13 03:03:38 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

// function who returns the number of elements in the list
int	ft_lstsize(t_lst_ctx *ctx)
{
	if (!ctx)
		return (0);
	return (ctx->size);
}

int	safe_lstsize(t_libft *libft, t_lst_ctx *ctx)
{
	int	result;

	if (!libft)
		return (0);
	if (!ctx)
	{
		SET_ERROR(libft->error_ctx, ERROR_INVALID_PARAM, EINVAL,
			"list context is null");
		PRINT_ERROR(libft->error_ctx);
		return (0);
	}
	result = ft_lstsize(ctx);
	return (result);
}
