/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_ctx_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 17:58:27 by anchikri          #+#    #+#             */
/*   Updated: 2024/08/15 17:58:29 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/garbage.h"

t_gc_ctx	*gc_ctx_init(void)
{
	t_gc_ctx	*ctx;

	ctx = ft_calloc(1, sizeof(t_gc_ctx));
	if (!ctx)
		return (NULL);
	return (ctx);
}