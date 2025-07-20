/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_double_ptr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 01:28:33 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/20 02:29:27 by anchikri         ###   ########.fr       */
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

void	safe_free_double_ptr(t_libft *libft, void ***ptr)
{
	if (!libft)
		return ;
	if (!ptr)
	{
		SET_ERROR(libft->error_ctx, ERROR_INVALID_PARAM, EINVAL,
			"pointer to double pointer is null");
		PRINT_ERROR(libft->error_ctx);
		return ;
	}
	ft_free_double_ptr(ptr);
}
