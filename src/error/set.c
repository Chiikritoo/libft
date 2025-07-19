/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 17:45:41 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/19 22:14:01 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

typedef struct s_error_info
{
	const char	*file;
	const char	*func;
	int			line;
}	t_error_info;

static char	*format_message(const char *msg, va_list ap)
{
	char	*buffer;
	int		len;
	va_list	ap_copy;

	if (!msg)
		return (ft_strdup("NULL message"));
	va_copy(ap_copy, ap);
	len = ft_vsnprintf(NULL, 0, msg, ap_copy);
	va_end(ap_copy);
	if (len < 0 || len > 10000)
		return (ft_strdup(msg));
	buffer = ft_calloc(len + 1, sizeof(char));
	if (!buffer)
		return (ft_strdup("Memory allocation failed for error message"));
	if (ft_vsnprintf(buffer, len + 1, msg, ap) < 0)
	{
		ft_free_ptr((void **)&buffer);
		return (ft_strdup(msg));
	}
	return (buffer);
}

static void	set_error_info(t_error_ctx *ctx, t_error_info *info)
{
	if (info->file)
		ctx->file = ft_strdup(info->file);
	else
		ctx->file = ft_strdup(__FILE__);
	if (info->func)
		ctx->function = ft_strdup(info->func);
	else
		ctx->function = ft_strdup(__func__);
	if (info->line > 0)
		ctx->line = info->line;
	else
		ctx->line = __LINE__;
}

static void	set_error_core(t_error_ctx *ctx, t_error_type type, int code,
				char *formatted_msg)
{
	ctx->type = type;
	ctx->code = code;
	ctx->message = formatted_msg;
	ctx->has_error = true;
}

void	set_error_ctx(t_error_ctx *ctx, t_error_type type, int code, const char *file, const char *func, int line, const char *msg, ...)
{
	va_list		ap;
	char		*formatted_msg;
	t_error_info	info;

	if (!ctx || !msg || !is_error_type_valid(type))
		return ;
	if (code < 0)
		code = EINVAL;
	info.file = file;
	info.func = func;
	info.line = line;
	va_start(ap, msg);
	formatted_msg = format_message(msg, ap);
	va_end(ap);
	if (!formatted_msg)
	{
		error_ctx_reset(ctx);
		return ;
	}
	set_error_core(ctx, type, code, formatted_msg);
	set_error_info(ctx, &info);
	if (!ctx->function || !ctx->file)
		error_ctx_reset(ctx);
}
