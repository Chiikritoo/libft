/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 21:46:11 by anchikri          #+#    #+#             */
/*   Updated: 2024/08/13 03:03:38 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

// function who applies the function 'f' to each content of the list 
void	ft_lstiter(t_lst_ctx *ctx, void (*f)(void *))
{
	t_lst	*tmp;

	if (!ctx || !f)
		return ;
	tmp = ctx->head;
	while (tmp)
	{
		f(tmp->content);
		tmp = tmp->next;
	}
}
