/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctx_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 16:21:17 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/20 02:15:20 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

// function who initializes the list context
t_lst_ctx	*ft_ctx_init(void)
{
	t_lst_ctx	*ctx;

	ctx = (t_lst_ctx *)ft_calloc(1, sizeof(t_lst_ctx));
	if (!ctx)
		return (NULL);
	return (ctx);
}

t_lst_ctx	*safe_ctx_init(t_libft *libft)
{
	t_lst_ctx	*result;

	if (!libft)
		return (NULL);
	result = ft_ctx_init();
	if (!result)
	{
		SET_ERROR(libft->error_ctx, ERROR_MEMORY, ENOMEM,
			"ft_ctx_init() failed to create list context");
		PRINT_ERROR(libft->error_ctx);
	}
	return (result);
}
