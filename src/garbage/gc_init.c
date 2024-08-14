/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 00:40:16 by anchikri          #+#    #+#             */
/*   Updated: 2024/08/15 00:41:15 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

t_gc_context	*gc_init(void)
{
	t_gc_context	*ctx;

	ctx = ft_calloc(1, sizeof(t_gc_context));
	if (!ctx)
		return (NULL);
	return (ctx);
}
