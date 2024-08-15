/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctx_destroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 16:59:04 by anchikri          #+#    #+#             */
/*   Updated: 2024/08/15 16:59:11 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/list.h"

void	ft_ctx_destroy(t_lst_ctx *ctx)
{
	if (!ctx)
		return ;
	ft_lstclear(ctx, free);
	free(ctx);
}
