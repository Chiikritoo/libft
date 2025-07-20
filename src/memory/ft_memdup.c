/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 17:50:44 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/20 02:28:44 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

// function who duplicates the memory of 'src' with the size 'size'
void	*ft_memdup(const void *src, size_t size)
{
	void	*dst;

	dst = ft_calloc(size, sizeof(char));
	if (!dst)
		return (NULL);
	ft_memcpy(dst, src, size);
	return (dst);
}

void	*safe_memdup(t_libft *libft, const void *src, size_t size)
{
	void	*result;

	if (!libft)
		return (NULL);
	if (!src)
	{
		SET_ERROR(libft->error_ctx, ERROR_INVALID_PARAM, EINVAL,
			"source memory area is null");
		PRINT_ERROR(libft->error_ctx);
		return (NULL);
	}
	result = ft_memdup(src, size);
	if (!result)
	{
		SET_ERROR(libft->error_ctx, ERROR_MEMORY, ENOMEM,
			"ft_memdup() failed for size %zu", size);
		PRINT_ERROR(libft->error_ctx);
	}
	return (result);
}
