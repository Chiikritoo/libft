/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 20:44:13 by anchikri          #+#    #+#             */
/*   Updated: 2024/08/13 03:03:38 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

// function who deletes the node 'lst' and his content with the function 'del'
void	ft_lstdelone(t_lst_ctx *ctx, t_lst *lst, void (*del)(void *))
{
	if (!ctx || !lst || !del)
		return ;
	if (lst->prev)
		lst->prev->next = lst->next;
	else
		ctx->head = lst->next;
	if (lst->next)
		lst->next->prev = lst->prev;
	else
		ctx->tail = lst->prev;
	del(lst->content);
	free(lst);
	ctx->size--;
}
