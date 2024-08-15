/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 00:40:16 by anchikri          #+#    #+#             */
/*   Updated: 2024/08/15 02:07:19 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

t_gc_ctx	*gc_init(void)
{
	t_gc_ctx	*ctx;

	ctx = ft_calloc(1, sizeof(t_gc_ctx));
	if (!ctx)
		return (NULL);
	return (ctx);
}
