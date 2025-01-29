/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctx_destroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 16:59:04 by anchikri          #+#    #+#             */
/*   Updated: 2025/01/29 17:26:04 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

// function who destroys the list context
void	ft_ctx_destroy(t_lst_ctx *ctx)
{
	if (!ctx)
		return ;
	ft_lstclear(ctx, free);
	free(ctx);
}
