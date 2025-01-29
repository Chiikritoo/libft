/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_ctx_destroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 01:05:36 by anchikri          #+#    #+#             */
/*   Updated: 2025/01/29 16:13:30 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/garbage.h"

// function who destroys the garbage collector
void	gc_ctx_destroy(t_gc_ctx *ctx)
{
	gc_clear(ctx);
	ft_free_ptr((void **)&ctx);
}
