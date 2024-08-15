/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_double_ptr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 01:28:33 by anchikri          #+#    #+#             */
/*   Updated: 2024/08/15 15:27:48 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/free.h"

// function who free a double pointer
void	ft_free_double_ptr(void **ptr)
{
	int	i;

	i = 0;
	if (ptr)
	{
		while (ptr[i])
			ft_free_ptr((void *)ptr[i++]);
		ft_free_ptr((void *)ptr);
		ptr = NULL;
	}
}
