/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:27:56 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/20 02:12:09 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

// function who copies the string 'src' to 'dst'
// with the size 'size'
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (!size)
		return (ft_strlen(src));
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

size_t	safe_strlcpy(t_libft *libft, char *dst, const char *src, size_t size)
{
	size_t	result;

	if (!libft)
		return (0);
	if (!dst || !src)
	{
		SET_ERROR(libft->error_ctx, ERROR_INVALID_PARAM, EINVAL,
			"dst or src is null");
		PRINT_ERROR(libft->error_ctx);
		return (0);
	}
	result = ft_strlcpy(dst, src, size);
	return (result);
}
