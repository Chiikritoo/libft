/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_double_ptr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 01:28:33 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/29 13:19:53 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

// function who free a double pointer
void	ft_free_double_ptr(void ***ptr)
{
	int	i;

	if (ptr && *ptr)
	{
		i = 0;
		while ((*ptr)[i])
		{
			ft_free_ptr(&(*ptr)[i]);
			i++;
		}
		ft_free_ptr((void **)ptr);
	}
}
