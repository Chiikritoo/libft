/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 20:26:03 by anchikri          #+#    #+#             */
/*   Updated: 2024/08/13 03:03:38 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

// function who returns the last node of the list
t_lst	*ft_lstlast(t_lst_ctx *ctx)
{
	if (!ctx)
		return (NULL);
	return (ctx->tail);
}

t_lst	*safe_lstlast(t_libft *libft, t_lst_ctx *ctx)
{
	t_lst	*result;

	if (!libft)
		return (NULL);
	if (!ctx)
	{
		SET_ERROR(libft->error_ctx, ERROR_INVALID_PARAM, EINVAL,
			"list context is null");
		PRINT_ERROR(libft->error_ctx);
		return (NULL);
	}
	result = ft_lstlast(ctx);
	if (!result)
	{
		SET_ERROR(libft->error_ctx, ERROR_LOGIC, EINVAL,
			"list is empty, no last node");
		PRINT_ERROR(libft->error_ctx);
	}
	return (result);
}
