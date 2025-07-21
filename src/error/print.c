/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 17:58:00 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/21 23:00:05 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

static const char	*get_error_color(t_error_type type)
{
	if (type == ERROR_MEMORY)
		return (RED);
	if (type == ERROR_INVALID_PARAM)
		return (YELLOW);
	if (type == ERROR_IO)
		return (BLUE);
	if (type == ERROR_LOGIC)
		return (MAGENTA);
	return (CYAN);
}

void	print_error_ctx(const t_error_ctx *ctx)
{
	const char	*message;
	const char	*file;

	if (!ctx || !ctx->has_error)
		return ;
	if (ctx->message)
		message = ctx->message;
	else
		message = "unknown error";
	if (ctx->file)
		file = ctx->file;
	else
		file = "unknown file";
	ft_printf("%s%s:%d:%s %serror:%s %s\n", BOLD WHITE, file, ctx->line, RESET,
		BOLD RED, RESET, message);
}

void	debug_print_error_ctx(const t_error_ctx *ctx)
{
	const char	*message;
	const char	*function;
	const char	*color;

	if (!ctx || !ctx->has_error)
		return ;
	if (ctx->message)
		message = ctx->message;
	else
		message = "unknown error";
	if (ctx->function)
		function = ctx->function;
	else
		function = "unknown function";
	color = get_error_color(ctx->type);
	ft_printf("%s%sError:%s %s: %s, %s\n", BOLD, color, RESET,
		get_error_type_name(ctx->type), message, function);
	if (ctx->file)
	{
		ft_printf("    %sat%s %s (%s:%d)\n", CYAN, RESET, function, ctx->file,
			ctx->line);
	}
	ft_printf(" %s{%s\n", YELLOW, RESET);
	ft_printf("   %serrno:%s %d,\n", GREEN, RESET, ctx->code);
	ft_printf("   %scode:%s '%s',\n", GREEN, RESET,
		get_error_type_name(ctx->type));
	if (ctx->function)
		ft_printf("   %sfunction:%s '%s',\n", GREEN, RESET, ctx->function);
	if (ctx->file)
		ft_printf("   %sfile:%s '%s:%d'\n", GREEN, RESET, ctx->file, ctx->line);
	ft_printf(" %s}%s\n", YELLOW, RESET);
}
