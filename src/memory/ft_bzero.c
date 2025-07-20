/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 13:26:30 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/20 02:28:08 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

// function who erases the data in the n bytes of the memory of s
void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

void	safe_bzero(t_libft *libft, void *s, size_t n)
{
	if (!libft)
		return ;
	if (!s)
	{
		SET_ERROR(libft->error_ctx, ERROR_INVALID_PARAM, EINVAL,
			"memory area is null");
		PRINT_ERROR(libft->error_ctx);
		return ;
	}
	ft_bzero(s, n);
}
