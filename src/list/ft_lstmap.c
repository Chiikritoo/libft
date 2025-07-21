/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 17:00:01 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/21 23:01:37 by anchikri         ###   ########.fr       */
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

t_lst_ctx	*safe_lstmap(t_libft *libft, t_lst_ctx *ctx, void *(*f)(void *),
		void (*del)(void *))
{
	t_lst_ctx	*result;

	if (!libft)
		return (NULL);
	if (!ctx)
	{
		SET_ERROR(libft->error_ctx, ERROR_INVALID_PARAM, EINVAL,
			"list context is null");
		PRINT_ERROR(libft->error_ctx);
		return (NULL);
	}
	if (!f)
	{
		SET_ERROR(libft->error_ctx, ERROR_INVALID_PARAM, EINVAL,
			"map function is null");
		PRINT_ERROR(libft->error_ctx);
		return (NULL);
	}
	if (!del)
	{
		SET_ERROR(libft->error_ctx, ERROR_INVALID_PARAM, EINVAL,
			"delete function is null");
		PRINT_ERROR(libft->error_ctx);
		return (NULL);
	}
	result = ft_lstmap(ctx, f, del);
	if (!result)
	{
		SET_ERROR(libft->error_ctx, ERROR_MEMORY, ENOMEM,
			"ft_lstmap() failed to create new list");
		PRINT_ERROR(libft->error_ctx);
	}
	return (result);
}
