/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 17:42:37 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/19 22:14:09 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

t_error_ctx	*error_ctx_init(void)
{
	t_error_ctx	*error_ctx;

	error_ctx = ft_calloc(1, sizeof(t_error_ctx));
	if (!error_ctx)
		return (NULL);
	error_ctx->type = ERROR_NONE;
	error_ctx->code = 0;
	error_ctx->line = 0;
	error_ctx->data = NULL;
	error_ctx->has_error = false;
	error_ctx->message = NULL;
	error_ctx->function = NULL;
	error_ctx->file = NULL;
	return (error_ctx);
}

void	error_ctx_destroy(t_error_ctx *error_ctx)
{
	if (!error_ctx)
		return ;
	error_ctx_reset(error_ctx);
	ft_free_ptr((void **)&error_ctx);
}

void	error_ctx_reset(t_error_ctx *error_ctx)
{
	if (!error_ctx)
		return ;
	if (error_ctx->message)
		ft_free_ptr((void **)&error_ctx->message);
	if (error_ctx->function)
		ft_free_ptr((void **)&error_ctx->function);
	if (error_ctx->file)
		ft_free_ptr((void **)&error_ctx->file);
	error_ctx->type = ERROR_NONE;
	error_ctx->code = 0;
	error_ctx->line = 0;
	error_ctx->data = NULL;
	error_ctx->has_error = false;
}

void	error_ctx_copy(t_error_ctx *dest, const t_error_ctx *src)
{
	if (!dest || !src)
		return ;
	error_ctx_reset(dest);
	dest->type = src->type;
	dest->code = src->code;
	dest->line = src->line;
	dest->data = src->data;
	dest->has_error = src->has_error;
	if (src->message)
		dest->message = ft_strdup(src->message);
	if (src->function)
		dest->function = ft_strdup(src->function);
	if (src->file)
		dest->file = ft_strdup(src->file);
}
