/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_garbage.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 01:32:39 by anchikri          #+#    #+#             */
/*   Updated: 2024/06/10 01:49:51 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libs/libft.h"

void	*ft_garbage(t_garbage **garbage, size_t nmemb, size_t size)
{
	t_garbage	*new;
	t_garbage	*temp;

	new = (t_garbage *)ft_gc_calloc(1, sizeof(t_garbage));
	if (!new)
		return (NULL);
	new->ptr = ft_gc_calloc(nmemb, size);
	if (!new->ptr)
	{
		ft_free_ptr(new);
		return (NULL);
	}
	if (!*garbage)
	{
		*garbage = new;
		return (new->ptr);
	}
	temp = *garbage;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
	return (new->ptr);
}
