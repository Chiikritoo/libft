/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_triple_ptr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 01:28:45 by anchikri          #+#    #+#             */
/*   Updated: 2024/08/14 22:48:05 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

// function who free a triple pointer
void	ft_free_triple_ptr(void ***ptr)
{
	int	i;

	i = 0;
	if (ptr)
	{
		while (ptr[i])
			ft_free_double_ptr(ptr[i++]);
		ft_free_ptr((void *)ptr);
		ptr = NULL;
	}
}
