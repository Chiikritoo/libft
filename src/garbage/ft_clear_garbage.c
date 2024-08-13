/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_garbage.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 01:48:24 by anchikri          #+#    #+#             */
/*   Updated: 2024/08/13 03:03:38 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	ft_clear_garbage(t_garbage **garbage)
{
	t_garbage	*tmp;

	if (garbage)
	{
		while (*garbage)
		{
			tmp = (*garbage)->next;
			ft_free_ptr((*garbage)->ptr);
			ft_free_ptr((void *)(*garbage));
			*garbage = tmp;
		}
	}
}
