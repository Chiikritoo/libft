/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_ctx_destroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 01:05:36 by anchikri          #+#    #+#             */
/*   Updated: 2024/08/15 17:58:47 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/garbage.h"

void	gc_ctx_destroy(t_gc_ctx *ctx)
{
	gc_clear(ctx);
	ft_free_ptr((void *)ctx);
}
