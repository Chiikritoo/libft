/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_ctx_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 17:58:27 by anchikri          #+#    #+#             */
/*   Updated: 2025/02/01 04:08:11 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

// function who initializes the garbage collector
t_gc_ctx	*gc_ctx_init(void)
{
	t_gc_ctx	*ctx;

	ctx = ft_calloc(1, sizeof(t_gc_ctx));
	if (!ctx)
		return (NULL);
	return (ctx);
}
