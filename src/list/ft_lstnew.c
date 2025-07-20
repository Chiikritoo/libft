/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 18:49:01 by anchikri          #+#    #+#             */
/*   Updated: 2024/08/13 03:03:38 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

// function who creates a new node with the content 'content'
t_lst	*ft_lstnew(void *content)
{
	t_lst	*new;

	new = (t_lst *)ft_calloc(1, sizeof(t_lst));
	if (!new)
		return (NULL);
	new->content = content;
	return (new);
}

t_lst	*safe_lstnew(t_libft *libft, void *content)
{
	t_lst	*result;

	if (!libft)
		return (NULL);
	result = ft_lstnew(content);
	if (!result)
	{
		SET_ERROR(libft->error_ctx, ERROR_MEMORY, ENOMEM,
			"ft_lstnew() failed to create new list node");
		PRINT_ERROR(libft->error_ctx);
	}
	return (result);
}
