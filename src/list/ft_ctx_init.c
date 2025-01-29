/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctx_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 16:21:17 by anchikri          #+#    #+#             */
/*   Updated: 2025/01/29 17:26:04 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

// function who initializes the list context
t_lst_ctx	*ft_ctx_init(void)
{
	t_lst_ctx	*ctx;

	ctx = (t_lst_ctx *)ft_calloc(1, sizeof(t_lst_ctx));
	if (!ctx)
		return (NULL);
	return (ctx);
}
