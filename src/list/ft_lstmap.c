/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 17:00:01 by anchikri          #+#    #+#             */
/*   Updated: 2024/08/15 17:13:21 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/list.h"

static t_lst	*add_node(void *content, void (*del)(void *))
{
	t_lst	*node;

	node = ft_lstnew(content);
	if (!node)
	{
		del(content);
		return (NULL);
	}
	return (node);
}

t_lst_ctx	*ft_lstmap(t_lst_ctx *ctx, void *(*f)(void *), void (*del)(void *))
{
	t_lst_ctx	*new_ctx;
	t_lst		*tmp;
	t_lst		*node;

	if (!ctx || !f)
		return (NULL);
	new_ctx = ft_ctx_init();
	if (!new_ctx)
		return (NULL);
	tmp = ctx->head;
	while (tmp)
	{
		node = add_node(f(tmp->content), del);
		if (!node)
		{
			ft_ctx_destroy(new_ctx);
			return (NULL);
		}
		ft_lstadd_back(new_ctx, node);
		tmp = tmp->next;
	}
	return (new_ctx);
}
