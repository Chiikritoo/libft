/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 17:00:01 by anchikri          #+#    #+#             */
/*   Updated: 2025/01/29 17:26:04 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

// function who creates a new list context and applies 
// the function f to each conrent of the list
t_lst_ctx	*ft_lstmap(t_lst_ctx *ctx, void *(*f)(void *), void (*del)(void *))
{
	t_lst_ctx	*new_ctx;
	t_lst		*new_lst;
	t_lst		*current;

	if (!ctx || !f || !del)
		return (NULL);
	new_ctx = ft_ctx_init();
	if (!new_ctx)
		return (NULL);
	current = ctx->head;
	while (current)
	{
		new_lst = ft_lstnew(f(current->content));
		if (!new_lst)
		{
			ft_ctx_destroy(new_ctx);
			return (NULL);
		}
		ft_lstadd_back(new_ctx, new_lst);
		current = current->next;
	}
	ft_lstclear(ctx, del);
	return (new_ctx);
}
