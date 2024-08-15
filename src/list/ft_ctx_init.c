/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctx_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 16:21:17 by anchikri          #+#    #+#             */
/*   Updated: 2024/08/15 16:21:23 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/list.h"

t_lst_ctx	*ft_ctx_init(void)
{
	t_lst_ctx	*ctx;

	ctx = (t_lst_ctx *)ft_calloc(1, sizeof(t_lst_ctx));
	if (!ctx)
		return (NULL);
	return (ctx);
}
