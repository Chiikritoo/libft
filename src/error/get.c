/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 17:44:32 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/19 22:21:45 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	clear_error_ctx(t_error_ctx *ctx)
{
	if (!ctx)
		return ;
	error_ctx_reset(ctx);
}

bool	has_error_ctx(const t_error_ctx *ctx)
{
	if (!ctx)
		return (false);
	return (ctx->has_error);
}

const char	*get_error_type_name(t_error_type type)
{
	static const char	*type_names[] = {
		"ERROR_NONE",
		"ERROR_MEMORY",
		"ERROR_INVALID_PARAM",
		"ERROR_IO",
		"ERROR_LOGIC",
		"ERROR_UNKNOWN"
	};

	if (type >= 0 && type <= ERROR_UNKNOWN)
		return (type_names[type]);
	return ("ERROR_UNKNOWN");
}
